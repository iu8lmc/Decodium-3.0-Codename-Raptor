subroutine ft2_triggered_decode(iwave, nqsoprogress, nfqso, nfa, nfb, &
     ndepth, ncontest, mycall, hiscall, outlines, nout)

! Level 2: Sync-Triggered FT2 Decoder — Optimized for Async Mode
! ===============================================================
! Two-phase architecture with subtraction loop and AP decoding:
!
! Phase 1 - Costas Scan:
!   getcandidates2 + coarse sync2d over full DT range
!   Returns: list of (freq, ibest, sync) hits above trigger threshold
!
! Phase 2 - Targeted Decode with Subtraction:
!   Fine sync refinement + bitmetrics + LDPC at Phase 1 positions
!   AP (A Priori) decoding when in active QSO (nQSOProgress >= 1)
!   Subtraction of decoded signals for weak-signal recovery
!
! Same C++ interface as ft2_async_decode for drop-in replacement.

  use packjt77

  include 'ft2_params.f90'
  parameter (MAXCAND=300, NSS=NSPS/NDOWN, NDMAX=NMAX/NDOWN)
  parameter (MAXHITS=80)

  integer*2 iwave(NMAX)
  integer nqsoprogress, nfqso, nfa, nfb, ndepth, ncontest
  character*12 mycall, hiscall
  character*80 outlines(100)
  integer nout

! Phase 1 hit storage
  real hit_freq(MAXHITS), hit_sync(MAXHITS), hit_snr(MAXHITS)
  integer hit_ibest(MAXHITS), hit_idf(MAXHITS)
  integer nhits

! Decode variables
  real dd(NMAX)
  real candidate(2,MAXCAND), savg(NH1), sbase(NH1)
  complex cd2(0:NDMAX-1), cb(0:NDMAX-1), cd(0:NN*NSS-1)
  complex ctwk(2*NSS), ctwk2(2*NSS,-16:16)
  real bitmetrics(2*NN,3)
  real llr(2*ND), llra(2*ND), llrb(2*ND), llrc(2*ND)
  real llrd(2*ND), llre(2*ND)
  real a(5)

  integer apbits(2*ND)
  integer apmy_ru(28), aphis_fd(28)
  integer*1 message77(77), rvec(77), apmask(2*ND), cw(2*ND)
  integer*1 message91(91)
  integer*1 hbits(2*NN)
  integer i4tone(103)
  integer ncand, ndepth0
  integer nappasses(0:5)
  integer naptypes(0:5,4)
  integer mcq(29),mcqru(29),mcqfd(29),mcqtest(29),mcqww(29)
  integer mrrr(19),m73(19),mrr73(19)
  character*37 message, msgsent, decodes(100)
  character*77 c77
  character*12 mycall0, hiscall0
  character*2 annot
  logical badsync, dobigfft, unpk77_success, doosd, dosubtract
  logical first, nohiscall
  real xibest, sm1, sp1, den
  integer ndecodes, npasses, iaptype

  data rvec/0,1,0,0,1,0,1,0,0,1,0,1,1,1,1,0,1,0,0,0,1,0,0,1,1,0,1,1,0, &
     1,0,0,1,0,1,1,0,0,0,0,1,0,0,0,1,0,1,0,0,1,1,1,1,0,0,1,0,1, &
     0,1,0,1,0,1,1,0,1,1,1,1,1,0,0,0,1,0,1/
  data     mcq/0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0/
  data   mcqru/0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,0,1,1,0,0/
  data   mcqfd/0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,1,0/
  data mcqtest/0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,0,1,0,1,1,1,1,1,1,0,0,1,0/
  data   mcqww/0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,1,1,1,1,0/
  data    mrrr/0,1,1,1,1,1,1,0,1,0,0,1,0,0,1,0,0,0,1/
  data     m73/0,1,1,1,1,1,1,0,1,0,0,1,0,1,0,0,0,0,1/
  data   mrr73/0,1,1,1,1,1,1,0,0,1,1,1,0,1,0,1,0,0,1/
  data first/.true./
  save first, ctwk2, apbits, mycall0, hiscall0, nappasses, naptypes

  nout = 0
  outlines = ' '
  ndecodes = 0

! Initialize frequency tweak factors and AP tables (once)
  if(first) then
    do idf = -16, 16
      a = 0.
      a(1) = real(idf)
      ctwk = 1.
      call twkfreq1(ctwk, 2*NSS, (12000.0/NDOWN)/2.0, a, ctwk2(:,idf))
    enddo

    mcq=2*mod(mcq+rvec(1:29),2)-1
    mcqru=2*mod(mcqru+rvec(1:29),2)-1
    mcqfd=2*mod(mcqfd+rvec(1:29),2)-1
    mcqtest=2*mod(mcqtest+rvec(1:29),2)-1
    mcqww=2*mod(mcqww+rvec(1:29),2)-1
    mrrr=2*mod(mrrr+rvec(59:77),2)-1
    m73=2*mod(m73+rvec(59:77),2)-1
    mrr73=2*mod(mrr73+rvec(59:77),2)-1

    nappasses(0)=3
    nappasses(1)=3
    nappasses(2)=3
    nappasses(3)=4
    nappasses(4)=4
    nappasses(5)=4

    naptypes(0,1:4)=(/1,2,0,0/)
    naptypes(1,1:4)=(/2,3,0,0/)
    naptypes(2,1:4)=(/2,3,0,0/)
    naptypes(3,1:4)=(/3,4,5,6/)
    naptypes(4,1:4)=(/3,4,5,6/)
    naptypes(5,1:4)=(/3,1,2,0/)

    mycall0=''
    hiscall0=''
    apbits=0
    first = .false.
  endif

! Initialize packjt77 context
  dxcall13 = hiscall
  mycall13 = mycall

  ndepth0 = iand(ndepth, 7)
  doosd = ndepth0.ge.3
  dosubtract = ndepth0.ge.2
  dd = iwave

! ============================================
! AP (A Priori) Setup — same as standard decoder
! ============================================
  l1=index(mycall,char(0))
  if(l1.ne.0) mycall(l1:)=" "
  l1=index(hiscall,char(0))
  if(l1.ne.0) hiscall(l1:)=" "
  if(mycall.ne.mycall0 .or. hiscall.ne.hiscall0) then
    apbits=0
    apbits(1)=99
    apbits(30)=99
    apmy_ru=0
    aphis_fd=0

    if(len(trim(mycall)) .ge. 3) then
      nohiscall=.false.
      hiscall0=hiscall
      if(len(trim(hiscall0)).lt.3) then
        hiscall0=mycall
        nohiscall=.true.
      endif
      message=trim(mycall)//' '//trim(hiscall0)//' RR73'
      i3=-1
      n3=-1
      call pack77(message,i3,n3,c77)
      call unpack77(c77,1,msgsent,unpk77_success)
      if(i3.eq.1 .and. message.eq.msgsent .and. unpk77_success) then
        read(c77,'(77i1)') message77
        apmy_ru=2*mod(message77(1:28)+rvec(2:29),2)-1
        aphis_fd=2*mod(message77(30:57)+rvec(29:56),2)-1
        message77=mod(message77+rvec,2)
        call encode174_91(message77,cw)
        apbits=2*cw-1
        if(nohiscall) apbits(30)=99
      endif
    endif
    mycall0=mycall
    hiscall0=hiscall
  endif

! ============================================
! SUBTRACTION LOOP (up to 3 passes)
! ============================================
  nsp = 3
  if(ndepth0.eq.1) nsp = 1
  nd1 = 0
  nd2 = 0

  do isp = 1, nsp
    if(isp.eq.2) then
      if(ndecodes.eq.0) exit
      nd1 = ndecodes
    elseif(isp.eq.3) then
      nd2 = ndecodes - nd1
      if(nd2.eq.0) exit
    endif

! ============================================
! PHASE 1: Fast Costas Sync Scan
! ============================================
    nhits = 0

! Adaptive syncmin for scan: lower on later passes (weaker signals remain)
    syncmin_scan0 = 0.50
    if(ndepth0.ge.3) syncmin_scan0 = 0.40
    if(isp.ge.2) syncmin_scan0 = syncmin_scan0 * 0.85

! Get candidate frequencies from spectrogram
    call getcandidates2(dd, real(nfa), real(nfb), syncmin_scan0, nfqso, &
         MAXCAND, savg, candidate, ncand, sbase)

! For each candidate, coarse sync search only
    dobigfft = .true.
    do icand = 1, ncand
      f0 = candidate(1, icand)
      snr0 = candidate(2, icand) - 1.0

      call ft2_downsample(dd, dobigfft, f0, cd2)
      if(dobigfft) dobigfft = .false.

      sum2 = sum(cd2*conjg(cd2))/(real(NMAX)/real(NDOWN))
      if(sum2.gt.0.0) cd2 = cd2/sqrt(sum2)

! Coarse sync search: full DT range, freq +/-12 Hz step 3
      ibest_c = -1
      idfbest_c = 0
      smax_c = -99.
      do idf = -12, 12, 3
        do istart = -688, 2024, 4
          call sync2d(cd2, istart, ctwk2(:,idf), 1, sync)
          if(sync.gt.smax_c) then
            smax_c = sync
            ibest_c = istart
            idfbest_c = idf
          endif
        enddo
      enddo

! Trigger threshold
      syncmin_scan = 0.55
      if(ndepth0.ge.3) syncmin_scan = 0.40
      if(isp.ge.2) syncmin_scan = syncmin_scan * 0.85

      if(smax_c.ge.syncmin_scan .and. nhits.lt.MAXHITS) then
        nhits = nhits + 1
        hit_freq(nhits) = f0
        hit_ibest(nhits) = ibest_c
        hit_idf(nhits) = idfbest_c
        hit_sync(nhits) = smax_c
        hit_snr(nhits) = snr0
      endif
    enddo

! ============================================
! PHASE 2: Targeted Decode at Sync Positions
! ============================================
    do ihit = 1, nhits
      f0 = hit_freq(ihit)
      ibest0 = hit_ibest(ihit)
      idf0 = hit_idf(ihit)
      snr0 = hit_snr(ihit)

! Re-downsample at candidate frequency (reuses cached FFT)
      call ft2_downsample(dd, .false., f0, cd2)
      sum2 = sum(cd2*conjg(cd2))/(real(NMAX)/real(NDOWN))
      if(sum2.gt.0.0) cd2 = cd2/sqrt(sum2)

! Fine sync: +/-5 samples, +/-4 Hz around coarse position
      ibest = ibest0
      idfbest = idf0
      smax = -99.
      do idf = max(-16, idf0-4), min(16, idf0+4)
        do istart = ibest0-5, ibest0+5
          call sync2d(cd2, istart, ctwk2(:,idf), 1, sync)
          if(sync.gt.smax) then
            smax = sync
            ibest = istart
            idfbest = idf
          endif
        enddo
      enddo

! Decode threshold — lowered for depth>=3
      smaxthresh = 0.75
      if(ndepth0.ge.3) smaxthresh = 0.55
      if(isp.ge.2) smaxthresh = smaxthresh * 0.88
      if(smax.lt.smaxthresh) cycle

! Corrected frequency
      f1 = f0 + real(idfbest)
      if(f1.le.10.0 .or. f1.ge.4990.0) cycle

! Final downsample at corrected frequency
      call ft2_downsample(dd, .false., f1, cb)
      sum2 = sum(abs(cb)**2)/(real(NSS)*NN)
      if(sum2.gt.0.0) cb = cb/sqrt(sum2)

! Extract signal at known position
      cd = 0.
      if(ibest.ge.0) then
        it = min(NDMAX-1, ibest+NN*NSS-1)
        np = it - ibest + 1
        cd(0:np-1) = cb(ibest:it)
      else
        cd(-ibest:ibest+NN*NSS-1) = cb(0:NN*NSS+2*ibest-1)
      endif

! Bit metrics
      call get_ft2_bitmetrics(cd, bitmetrics, badsync)
      if(badsync) cycle

! Sub-sample DT refinement via parabolic interpolation
      if(ibest.gt.0 .and. ibest.lt.NDMAX-1) then
        call sync2d(cd2, ibest-1, ctwk2(:,idfbest), 1, sm1)
        call sync2d(cd2, ibest+1, ctwk2(:,idfbest), 1, sp1)
        den = sm1 - 2.0*smax + sp1
        if(abs(den).gt.1.0e-6) then
          xibest = real(ibest) + 0.5*(sm1 - sp1)/den
        else
          xibest = real(ibest)
        endif
      else
        xibest = real(ibest)
      endif

! Sync quality check (hard Costas symbol verification)
      hbits = 0
      where(bitmetrics(:,1).ge.0) hbits = 1
      ns1 = count(hbits(  1:  8).eq.(/0,0,0,1,1,0,1,1/))
      ns2 = count(hbits( 67: 74).eq.(/0,1,0,0,1,1,1,0/))
      ns3 = count(hbits(133:140).eq.(/1,1,1,0,0,1,0,0/))
      ns4 = count(hbits(199:206).eq.(/1,0,1,1,0,0,0,1/))
      nsync_qual = ns1 + ns2 + ns3 + ns4
      nsync_qual_min = 12
      if(ndepth0.ge.3) nsync_qual_min = 9
      if(nsync_qual.lt.nsync_qual_min) cycle

! Scale LLRs from bitmetrics (3 metric types)
      scalefac = 2.83
      llra(  1: 58) = bitmetrics(  9: 66, 1)
      llra( 59:116) = bitmetrics( 75:132, 1)
      llra(117:174) = bitmetrics(141:198, 1)
      llra = scalefac * llra
      llrb(  1: 58) = bitmetrics(  9: 66, 2)
      llrb( 59:116) = bitmetrics( 75:132, 2)
      llrb(117:174) = bitmetrics(141:198, 2)
      llrb = scalefac * llrb
      llrc(  1: 58) = bitmetrics(  9: 66, 3)
      llrc( 59:116) = bitmetrics( 75:132, 3)
      llrc(117:174) = bitmetrics(141:198, 3)
      llrc = scalefac * llrc

! Multi-metric: best-of (max |value|) and average
      do i = 1, 2*ND
        if(abs(llra(i)).ge.abs(llrb(i)) .and. &
           abs(llra(i)).ge.abs(llrc(i))) then
          llrd(i) = llra(i)
        elseif(abs(llrb(i)).ge.abs(llrc(i))) then
          llrd(i) = llrb(i)
        else
          llrd(i) = llrc(i)
        endif
        llre(i) = (llra(i) + llrb(i) + llrc(i))/3.0
      enddo

! Determine number of passes: 5 metric + AP passes
      apmag = maxval(abs(llra))*1.1
      npasses = 5 + nappasses(nqsoprogress)
      if(ndepth0.eq.1) npasses = 5

      do ipass = 1, npasses
        if(ipass.eq.1) llr = llra
        if(ipass.eq.2) llr = llrb
        if(ipass.eq.3) llr = llrc
        if(ipass.eq.4) llr = llrd
        if(ipass.eq.5) llr = llre
        if(ipass.le.5) then
          apmask = 0
          iaptype = 0
        endif

! AP (A Priori) passes — same logic as standard decoder
        if(ipass .gt. 5) then
          llrd = llrc
          iaptype = naptypes(nqsoprogress, ipass-5)

          napwid = 75
          if(ncontest.le.5 .and. iaptype.ge.3 .and. &
             (abs(f1-nfqso).gt.napwid)) cycle
          if(iaptype.ge.2 .and. apbits(1).gt.1) cycle
          if(iaptype.ge.3 .and. apbits(30).gt.1) cycle

          if(iaptype.eq.1) then
            apmask = 0
            apmask(1:29) = 1
            if(ncontest.eq.0) llrd(1:29) = apmag*mcq(1:29)
            if(ncontest.eq.1) llrd(1:29) = apmag*mcqtest(1:29)
            if(ncontest.eq.2) llrd(1:29) = apmag*mcqtest(1:29)
            if(ncontest.eq.3) llrd(1:29) = apmag*mcqfd(1:29)
            if(ncontest.eq.4) llrd(1:29) = apmag*mcqru(1:29)
            if(ncontest.eq.5) llrd(1:29) = apmag*mcqww(1:29)
          endif

          if(iaptype.eq.2) then
            apmask = 0
            if(ncontest.eq.0.or.ncontest.eq.1.or.ncontest.eq.5) then
              apmask(1:29) = 1
              llrd(1:29) = apmag*apbits(1:29)
            else if(ncontest.eq.2) then
              apmask(1:28) = 1
              llrd(1:28) = apmag*apbits(1:28)
            else if(ncontest.eq.3) then
              apmask(1:28) = 1
              llrd(1:28) = apmag*apbits(1:28)
            else if(ncontest.eq.4) then
              apmask(2:29) = 1
              llrd(2:29) = apmag*apmy_ru(1:28)
            endif
          endif

          if(iaptype.eq.3) then
            apmask = 0
            if(ncontest.eq.0.or.ncontest.eq.1.or. &
               ncontest.eq.2.or.ncontest.eq.5) then
              apmask(1:58) = 1
              llrd(1:58) = apmag*apbits(1:58)
            else if(ncontest.eq.3) then
              apmask(1:56) = 1
              llrd(1:28) = apmag*apbits(1:28)
              llrd(29:56) = apmag*aphis_fd(1:28)
            else if(ncontest.eq.4) then
              apmask(2:57) = 1
              llrd(2:29) = apmag*apmy_ru(1:28)
              llrd(30:57) = apmag*apbits(30:57)
            endif
          endif

          if(iaptype.eq.4 .or. iaptype.eq.5 .or. iaptype.eq.6) then
            apmask = 0
            if(ncontest.le.5) then
              apmask(1:77) = 1
              if(iaptype.eq.6) llrd(1:77) = apmag*apbits(1:77)
            endif
          endif

          llr = llrd
        endif

        message77 = 0
        dmin = 0.0
        maxosd = 3
        if(ndepth0.ge.3) maxosd = 4
        if(.not.doosd) maxosd = -1

        Keff = 91
        call decode174_91(llr, Keff, maxosd, 3, apmask, message91, cw, &
                          ntype, nharderror, dmin)
        message77 = message91(1:77)

        if(sum(message77).eq.0) cycle
        if(nharderror.ge.0) then
          message77 = mod(message77 + rvec, 2)
          write(c77, '(77i1)') message77(1:77)
          call unpack77(c77, 1, message, unpk77_success)
          if(.not.unpk77_success) cycle

! Subtract decoded signal from dd (for next subtraction pass)
          if(dosubtract) then
            call get_ft2_tones_from_77bits(message77, i4tone)
            dt_sub = real(ibest)/1333.33
            call subtractft2(dd, i4tone, f1, dt_sub)
          endif

! Check duplicate within this call
          idupe = 0
          do i = 1, ndecodes
            if(decodes(i).eq.message) idupe = 1
          enddo
          if(idupe.eq.1) exit

          ndecodes = ndecodes + 1
          decodes(ndecodes) = message

! Calculate SNR
          if(snr0.gt.0.0) then
            xsnr = 10*log10(snr0) - 13.0
          else
            xsnr = -21.0
          endif
          nsnr = nint(max(-21.0, xsnr))

! DT from known sync position
          xdt = xibest/1333.33 - 0.5
          annot = '  '
          if(iaptype.ne.0) then
            write(annot,'(a1,i1)') 'a', iaptype
          endif
          nout = nout + 1
          write(outlines(nout), 1001) nsnr, xdt, nint(f1), message, annot
1001      format(i4,f5.1,i5,' ~ ',1x,a37,1x,a2)
          exit
        endif
      enddo  ! ipass
    enddo  ! ihit
  enddo  ! isp (subtraction loop)

  return
end subroutine ft2_triggered_decode
