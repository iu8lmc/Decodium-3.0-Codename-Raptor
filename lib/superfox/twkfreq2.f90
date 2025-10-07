subroutine twkfreq2(c3,c4,npts,fsample,fshift)

! Adjust frequency of complex waveform
  
  complex c3(npts)
  complex c4(npts)
  complex w,wstep
  data twopi/6.283185307/

  w=1.0
  dphi=fshift*twopi/fsample
  wstep=cmplx(cos(dphi),sin(dphi))
  do i=1,npts
     w=w*wstep
     c4(i)=w*c3(i)
  enddo

  return
end subroutine twkfreq2
