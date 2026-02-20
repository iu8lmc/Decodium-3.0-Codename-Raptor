subroutine foxfiltft2(nslots,nfreq,width,wave)

! Spectral filtering for FT2 Fox multi-slot signals.
! Analogous to foxfilt.f90 for FT8.
!
! FT2 baud rate = 41.667 Hz, 4 tones -> signal BW ~167 Hz
! Slot spacing = 200 Hz

  parameter (NN2=105,NSPS=4*288)
  parameter (NWAVEFT2=NN2*NSPS)
  parameter (NFFT=614400,NH=NFFT/2)
  real wave(NWAVEFT2)
  real x(NFFT)
  complex cx(0:NH)
  equivalence (x,cx)

  x(1:NWAVEFT2)=wave
  x(NWAVEFT2+1:)=0.
  call four2a(cx,NFFT,1,-1,0)              !r2c
  df=48000.0/NFFT

! FT2 baud = 48000/1152 = 41.667 Hz
! Signal spans tones 0-3: bandwidth = 3*41.667 = 125 Hz center-to-center
! With GFSK spreading, effective BW ~167 Hz
  baud=48000.0/NSPS
  fa=nfreq - 0.5*baud
  fb=nfreq + 3.5*baud + (nslots-1)*200.0
  ia2=nint(fa/df)
  ib1=nint(fb/df)
  ia1=nint(ia2-width/df)
  ib2=nint(ib1+width/df)
  pi=4.0*atan(1.0)
  do i=ia1,ia2
     fil=(1.0 + cos(pi*df*(i-ia2)/width))/2.0
     cx(i)=fil*cx(i)
  enddo
  do i=ib1,ib2
     fil=(1.0 + cos(pi*df*(i-ib1)/width))/2.0
     cx(i)=fil*cx(i)
  enddo
  cx(0:ia1-1)=0.
  cx(ib2+1:)=0.

  call four2a(cx,nfft,1,1,-1)                  !c2r
  wave=x(1:NWAVEFT2)/nfft

  return
end subroutine foxfiltft2
