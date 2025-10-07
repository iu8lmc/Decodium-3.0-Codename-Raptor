subroutine sfox_prob(s3,rxdat,rxprob,rxdat2,rxprob2)

! Demodulate the 64-bin spectra for each of 63 symbols in a frame.

! Parameters
!    rxdat    most reliable symbol value
!    rxdat2   second most likely symbol value
!    rxprob   probability that rxdat was the transmitted value
!    rxprob2  probability that rxdat2 was the transmitted value

  use sfox_mod
  implicit real*8 (a-h,o-z)
  real*4 s3(0:NQ-1,0:NN-1)
  integer rxdat(0:NN-1),rxprob(0:NN-1),rxdat2(0:NN-1),rxprob2(0:NN-1)

  afac=1.1
!  scale=255.999
  scale=2047.999

! Compute average spectral value
  ave=sum(s3)/(NQ*ND)
  i1=1                                      !Silence warning
  i2=1

! Compute probabilities for most reliable symbol values
  do j=0,NN-1                               !Loop over all symbols
     s1=-1.e30
     psum=0. 
     do i=0,NQ-1                            !Loop over frequency bins
        x=min(afac*s3(i,j)/ave,50.d0)
        psum=psum+s3(i,j)
        if(s3(i,j).gt.s1) then
           s1=s3(i,j)                       !Find max signal+noise power
           i1=i                             !Find most reliable symbol value
        endif
     enddo
     if(psum.eq.0.0) psum=1.e-6             !Guard against zero signal+noise

     s2=-1.e30
     do i=0,NQ-1
        if(i.ne.i1 .and. s3(i,j).gt.s2) then
           s2=s3(i,j)                       !Second largest signal+noise power
           i2=i                             !Bin number for second largest power
        endif
     enddo
     p1=s1/psum                             !p1, p2 are symbol metrics for ftrsd
     p2=s2/psum
     rxdat(j)=i1
     rxdat2(j)=i2
     rxprob(j)=scale*p1                     !Scaled probabilities, 0 - 255
     rxprob2(j)=scale*p2
  enddo
  
  return
end subroutine sfox_prob
