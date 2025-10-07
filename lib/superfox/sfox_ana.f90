subroutine sfox_ana(dd,npts,c0,npts2)

  real dd(npts)                      !Raw data at 12000 Hz
  complex c0(0:npts2-1)                      !Complex data at 12000 Hz
  save

  nfft1=npts
  nfft2=nfft1
  fac=2.0/(32767.0*nfft1)
  c0(0:npts-1)=fac*dd(1:npts)
  call four2a(c0,nfft1,1,-1,1)             !Forward c2c FFT
  c0(nfft2/2+1:nfft2-1)=0.                 !Remove negative frequencies
  c0(0)=0.5*c0(0)                          !Scale the DC term to 1/2
  call four2a(c0,nfft2,1,1,1)              !Inverse c2c FFT; c0 is analytic sig

  return
end subroutine sfox_ana
