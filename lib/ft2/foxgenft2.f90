subroutine foxgenft2()

! Called from MainWindow to generate the Tx waveform in FT2 Fox mode.
! The Tx message can contain up to 3 "slots", each carrying its own
! FT2 signal.  Analogous to foxgen.f90 for FT8.
!
! FT2 signals are ~167 Hz wide (4-GFSK, baud=41.667 Hz), so we use
! fstep=200 Hz between slots (vs 60 Hz for FT8).
!
! Input message information is provided in character array cmsg(5), in
! common/foxcom/.  The generated wave(NWAVE) is passed back in the same
! common block.

  parameter (NN2=105,NSPS=4*288)
  parameter (NWAVE=(160+2)*134400*4)
  parameter (NWAVEFT2=(NN2)*NSPS)
  character*40 cmsg
  character*37 msg,msgsent
  character*26 textMsg
  integer itone(103)
  integer*1 msgbits(77)
  integer*1, target:: mycall
  real waveslot(NWAVEFT2)
  complex cwaveslot(NWAVEFT2)
  real*8 fstep
  logical*1 bMoreCQs,bSendMsg
  common/foxcom/wave(NWAVE),nslots,nfreq,i3bit(5),cmsg(5),mycall(12), &
       textMsg,bMoreCQs,bSendMsg

  fstep=200.d0
  wave=0.

  do n=1,nslots
     msg=cmsg(n)(1:37)
     ichk=0
     call genft2(msg,ichk,msgsent,msgbits,itone)
     f0=nfreq + fstep*(n-1)
     nsym=103
     fsample=48000.0
     nwave1=NWAVEFT2
     icmplx=0
     waveslot=0.
     call gen_ft2wave(itone,nsym,NSPS,fsample,f0,cwaveslot, &
                      waveslot,icmplx,nwave1)
     wave(1:nwave1)=wave(1:nwave1)+waveslot(1:nwave1)
  enddo

  peak=maxval(abs(wave(1:NWAVEFT2)))
  if(peak.gt.0.0) wave(1:NWAVEFT2)=wave(1:NWAVEFT2)/peak
  width=50.0
  call foxfiltft2(nslots,nfreq,width,wave)
  peak=maxval(abs(wave(1:NWAVEFT2)))
  if(peak.gt.0.0) wave(1:NWAVEFT2)=wave(1:NWAVEFT2)/peak

  return
end subroutine foxgenft2
