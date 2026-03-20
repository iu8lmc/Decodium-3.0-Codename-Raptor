subroutine ft2_excise(dd)

! Spectral excision of PERSISTENT narrowband interferers (e.g., FT8 signals)
! Uses temporal persistence detection to distinguish FT8 from FT2:
!   - FT8 tones are constant → high power in EVERY time segment → high specmin
!   - FT2 tones hop each symbol → active only 1/4 of segments → low specmin
!
! Algorithm:
!   1. Compute segmented spectrogram (same grid as getcandidates2)
!   2. Track per-bin MINIMUM power across all time segments
!   3. Bins where minimum > threshold = persistent interferers (FT8)
!   4. Apply excision via full-length FFT: zero out interferer frequencies
!
! This ONLY removes persistent tones. FT2 signals are completely unaffected
! because their per-bin minimum is at noise level (tone not active in most segments).

  include 'ft2_params.f90'

  real dd(NMAX)

! Segmented spectrogram arrays (same as getcandidates2)
  real xs(NFFT1+2)
  complex cxs(0:NH1)
  equivalence (xs, cxs)
  real spec_seg(NH1), specmin(NH1), specavg(NH1)
  real window(NFFT1)

! Full-length FFT arrays
  real xf(NMAX+2)
  complex cxf(0:NMAX/2)
  equivalence (xf, cxf)

  logical first
  data first/.true./
  save first, window

  if(first) then
    window = 0.
    call nuttal_window(window, NFFT1)
    first = .false.
  endif

! ── Phase 1: Detect persistent interferers via spectrogram ──────────

  specmin = 1.e30
  specavg = 0.
  nseg = 0
  fac = 1.0 / 300.0

  do j = 1, NHSYM
    ia = (j-1)*NSTEP + 1
    ib = ia + NFFT1 - 1
    if(ib .gt. NMAX) exit
    xs(1:NFFT1) = fac * dd(ia:ib) * window
    xs(NFFT1+1:NFFT1+2) = 0.0
    call four2a(xs, NFFT1, 1, -1, 0)
    do i = 1, NH1
      spec_seg(i) = real(cxs(i))**2 + aimag(cxs(i))**2
    enddo
    do i = 1, NH1
      if(spec_seg(i) .lt. specmin(i)) specmin(i) = spec_seg(i)
    enddo
    specavg = specavg + spec_seg
    nseg = nseg + 1
  enddo

  if(nseg .lt. 10) return
  specavg = specavg / real(nseg)

! Noise floor estimate via iterative clipped mean
  pmean = sum(specavg) / NH1
  do iter = 1, 3
    psum = 0.0
    nc = 0
    do i = 1, NH1
      if(specavg(i) .lt. 3.0*pmean) then
        psum = psum + specavg(i)
        nc = nc + 1
      endif
    enddo
    if(nc .gt. 0) pmean = psum / real(nc)
  enddo
  if(pmean .le. 0.0) return

! Persistent interferer = bin where MINIMUM power > 6 dB above noise floor
! FT2 tones: active ~25% of segments → specmin ≈ noise level → NOT flagged
! FT8 tones: active 100% of segments → specmin ≈ signal level → FLAGGED
  plimit = pmean * 4.0               ! 6 dB = factor 4 in power

  nintf = 0
  do i = 1, NH1
    if(specmin(i) .gt. plimit) nintf = nintf + 1
  enddo
  if(nintf .eq. 0) return             ! no persistent interferers found

! ── Phase 2: Excise interferers in full-length FFT ──────────────────

  xf(1:NMAX) = dd
  xf(NMAX+1:NMAX+2) = 0.0
  call four2a(xf, NMAX, 1, -1, 0)

! Map each flagged short-FFT bin to full-FFT bins and zero them out
  ibinratio = nint(real(NMAX) / real(NFFT1))  ! ≈ 39
  ihalfwidth = ibinratio / 2 + 1              ! ≈ 20 bins each side

  do i = 1, NH1
    if(specmin(i) .le. plimit) cycle
    icenter = nint(real(i) * real(ibinratio))
    ilo = max(1, icenter - ihalfwidth)
    ihi = min(NMAX/2, icenter + ihalfwidth)
    do ib = ilo, ihi
      cxf(ib) = cmplx(0.0, 0.0)
    enddo
  enddo

! Inverse FFT (complex to real)
  call four2a(xf, NMAX, 1, 1, -1)
  dd = xf(1:NMAX) / real(NMAX)

  return
end subroutine ft2_excise
