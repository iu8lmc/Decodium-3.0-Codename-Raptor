subroutine qpc_snr(s3,y,snr)

  use qpc_mod
!  real s2(0:NQ-1,0:151)               !Symbol spectra, including sync
  real s3(0:127,0:127)                !Synchronized symbol spectra
  integer*1 y(0:127)                  !Encoded symbols
!  integer isync(24)

  p=0.
  do j=1,127
     i=y(j)
     p=p + s3(i,j)
  enddo
  snr=db(p/127.0) - db(127.0) - 4.0

  return
end subroutine qpc_snr
