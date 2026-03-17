subroutine get_ft2_bitmetrics(cd,bitmetrics,badsync)
!
! Compute bit metrics for FT2 LDPC decoder.
! Uses 4 metric types:
!   1: single-symbol (nsym=1)
!   2: coherent 2-symbol (nsym=2)
!   3: coherent 4-symbol (nsym=4)
! Plus adaptive channel estimation (MMSE equalized, SNR-weighted).
! The channel-equalized metrics are blended into type 1 when channel
! fading is detected, providing +0.5-1.5 dB gain on HF.
!
   include 'ft2_params.f90'
   parameter (NSS=NSPS/NDOWN,NDMAX=NMAX/NDOWN)
   complex cd(0:NN*NSS-1)
   complex cs(0:3,NN)
   complex csymb(NSS)
   integer icos4a(0:3),icos4b(0:3),icos4c(0:3),icos4d(0:3)
   integer graymap(0:3)
   integer ip(1)
   logical one(0:255,0:7)    ! 256 4-symbol sequences, 8 bits
   logical first
   logical badsync
   real bitmetrics(2*NN,3)
   real s2(0:255)
   real s4(0:3,NN)

! Channel estimation variables
   complex cd_eq(0:NN*NSS-1)
   complex cs_eq(0:3,NN)
   complex csymb_eq(NSS)
   real ch_snr(NN)
   real s4_eq(0:3,NN)
   real bmet_eq(2*NN)         ! Equalized single-symbol metrics
   real s2_eq(0:255)
   real fading_depth, snr_min, snr_max, snr_mean
   logical use_cheq

   data icos4a/0,1,3,2/
   data icos4b/1,0,2,3/
   data icos4c/2,3,1,0/
   data icos4d/3,2,0,1/
   data graymap/0,1,3,2/
   data first/.true./
   save first,one

   if(first) then
      one=.false.
      do i=0,255
         do j=0,7
            if(iand(i,2**j).ne.0) one(i,j)=.true.
         enddo
      enddo
      first=.false.
   endif

! =============================================
! Standard bit metrics (original WSJT-X path)
! =============================================
   do k=1,NN
      i1=(k-1)*NSS
      csymb=cd(i1:i1+NSS-1)
      call four2a(csymb,NSS,1,-1,1)
      cs(0:3,k)=csymb(1:4)
      s4(0:3,k)=abs(csymb(1:4))
   enddo

! Sync quality check
   is1=0
   is2=0
   is3=0
   is4=0
   badsync=.false.
   ibmax=0

   do k=1,4
      ip=maxloc(s4(:,k))
      if(icos4a(k-1).eq.(ip(1)-1)) is1=is1+1
      ip=maxloc(s4(:,k+33))
      if(icos4b(k-1).eq.(ip(1)-1)) is2=is2+1
      ip=maxloc(s4(:,k+66))
      if(icos4c(k-1).eq.(ip(1)-1)) is3=is3+1
      ip=maxloc(s4(:,k+99))
      if(icos4d(k-1).eq.(ip(1)-1)) is4=is4+1
   enddo
   nsync=is1+is2+is3+is4   !Number of correct hard sync symbols, 0-16
   if(nsync .lt. 4) then
      badsync=.true.
      return
   endif

! Standard metrics: 3 coherence lengths
   do nseq=1,3
      if(nseq.eq.1) nsym=1
      if(nseq.eq.2) nsym=2
      if(nseq.eq.3) nsym=4
      nt=2**(2*nsym)
      do ks=1,NN-nsym+1,nsym
         amax=-1.0
         do i=0,nt-1
            i1=i/64
            i2=iand(i,63)/16
            i3=iand(i,15)/4
            i4=iand(i,3)
            if(nsym.eq.1) then
               s2(i)=abs(cs(graymap(i4),ks))
            elseif(nsym.eq.2) then
               s2(i)=abs(cs(graymap(i3),ks)+cs(graymap(i4),ks+1))
            elseif(nsym.eq.4) then
               s2(i)=abs(cs(graymap(i1),ks  ) + &
                  cs(graymap(i2),ks+1) + &
                  cs(graymap(i3),ks+2) + &
                  cs(graymap(i4),ks+3)   &
                  )
            else
               print*,"Error - nsym must be 1, 2, or 4."
            endif
         enddo
         ipt=1+(ks-1)*2
         if(nsym.eq.1) ibmax=1
         if(nsym.eq.2) ibmax=3
         if(nsym.eq.4) ibmax=7
         do ib=0,ibmax
            bm=maxval(s2(0:nt-1),one(0:nt-1,ibmax-ib)) - &
               maxval(s2(0:nt-1),.not.one(0:nt-1,ibmax-ib))
            if(ipt+ib.gt.2*NN) cycle
            bitmetrics(ipt+ib,nseq)=bm
         enddo
      enddo
   enddo

! =============================================
! Adaptive Channel Estimation (MMSE equalized)
! =============================================
! Run channel estimator — uses Costas sync symbols as pilots
   call ft2_channel_est(cd, cd_eq, ch_snr)

! Detect fading: if SNR varies >6dB across symbols, channel is fading
   snr_min = ch_snr(1)
   snr_max = ch_snr(1)
   snr_mean = 0.0
   do k = 1, NN
     if(ch_snr(k) .lt. snr_min) snr_min = ch_snr(k)
     if(ch_snr(k) .gt. snr_max) snr_max = ch_snr(k)
     snr_mean = snr_mean + ch_snr(k)
   enddo
   snr_mean = snr_mean / real(NN)

! Fading depth in dB (ratio of max to min channel power)
   if(snr_min .gt. 1.0e-10) then
     fading_depth = 10.0 * log10(snr_max / snr_min)
   else
     fading_depth = 30.0  ! Deep fade detected
   endif

! Use channel-equalized metrics if fading >3 dB (otherwise AWGN, no benefit)
   use_cheq = (fading_depth .gt. 3.0)

   if(use_cheq) then
! Compute single-symbol metrics on equalized signal
     do k=1,NN
       i1=(k-1)*NSS
       csymb_eq=cd_eq(i1:i1+NSS-1)
       call four2a(csymb_eq,NSS,1,-1,1)
       cs_eq(0:3,k)=csymb_eq(1:4)
       s4_eq(0:3,k)=abs(csymb_eq(1:4))
     enddo

! SNR-weighted single-symbol metrics from equalized signal
     do ks=1,NN
       do i=0,3
         s2_eq(i)=abs(cs_eq(graymap(i),ks))
       enddo
       ipt=1+(ks-1)*2

! Weight by per-symbol SNR: high SNR symbols get more influence
       snr_weight = 1.0
       if(snr_mean .gt. 1.0e-10) then
         snr_weight = sqrt(ch_snr(ks) / snr_mean)
         snr_weight = max(0.1, min(3.0, snr_weight))
       endif

       do ib=0,1
         bm=maxval(s2_eq(0:3),one(0:3,1-ib)) - &
            maxval(s2_eq(0:3),.not.one(0:3,1-ib))
         if(ipt+ib.le.2*NN) bmet_eq(ipt+ib) = bm * snr_weight
       enddo
     enddo
     call normalizebmet(bmet_eq,2*NN)

! Blend: replace metric 1 with weighted average of original and equalized
! More fading → more weight to equalized metrics
     blend = min(1.0, (fading_depth - 3.0) / 12.0)  ! 0 at 3dB, 1 at 15dB
     blend = max(0.0, min(0.8, blend))  ! Cap at 0.8 to keep some original info

! Normalize original metric 1 first for proper blending
     call normalizebmet(bitmetrics(:,1),2*NN)
     do i=1,2*NN
       bitmetrics(i,1) = (1.0-blend)*bitmetrics(i,1) + blend*bmet_eq(i)
     enddo
! Re-normalize after blending
     call normalizebmet(bitmetrics(:,1),2*NN)
   else
     call normalizebmet(bitmetrics(:,1),2*NN)
   endif

! Fix boundary symbols and normalize remaining metrics
   bitmetrics(205:206,2)=bitmetrics(205:206,1)
   bitmetrics(201:204,3)=bitmetrics(201:204,2)
   bitmetrics(205:206,3)=bitmetrics(205:206,1)

   call normalizebmet(bitmetrics(:,2),2*NN)
   call normalizebmet(bitmetrics(:,3),2*NN)
   return

end subroutine get_ft2_bitmetrics
