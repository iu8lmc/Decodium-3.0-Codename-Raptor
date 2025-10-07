subroutine sfox_demod(crcvd,f,t,isync,s2,s3)

  use sfox_mod
  complex crcvd(NMAX)                    !Signal as received
  complex c(0:NSPS-1)                    !Work array, one symbol long
  real s2(0:NQ-1,0:151)                  !Symbol spectra, including sync
  real s3(0:NQ-1,0:NN)                   !Synchronized symbol spectra
  integer isync(24)
  integer ipk(1)
  integer hist1(0:NQ-1),hist2(0:NQ-1)

  j0=nint(12000.0*(t+0.5))
  df=12000.0/NSPS
  i0=nint(f/df)-NQ/2
  k2=0
  s2(:,0)=0.                             !The punctured symbol
  s3(:,0)=0.                             !The punctured symbol

  do n=1,NDS                             !Loop over all symbols
     jb=n*NSPS + j0
     ja=jb-NSPS+1
     k2=k2+1
     if(ja.lt.1 .or. jb.gt.NMAX) cycle
     c=crcvd(ja:jb)
     call four2a(c,NSPS,1,-1,1)          !Compute symbol spectrum
     do i=0,NQ-1
        s2(i,k2)=real(c(i0+i))**2 + aimag(c(i0+i))**2
     enddo
  enddo


  call pctile(s2,NQ*151,50,base2)
  s2=s2/base2

  hist1=0
  hist2=0
  do j=0,151
     ipk=maxloc(s2(1:NQ-1,j))       !Find the spectral peak
     i=ipk(1)-1
     hist1(i)=hist1(i)+1
  enddo

  hist1(0)=0                        !Don't treat sync tone as a birdie
  do i=0,123
     hist2(i)=sum(hist1(i:i+3))
  enddo

  ipk=maxloc(hist1)
  i1=ipk(1)-1
  m1=maxval(hist1)
  ipk=maxloc(hist2)
  i2=ipk(1)-1
  m2=maxval(hist2)
  if(m1.gt.12) then
     do i=0,127
        if(hist1(i).gt.12) then
             s2(i,:)=1.0
        endif
     enddo
  endif

  if(m2.gt.20) then
     if(i2.ge.1) i2=i2-1
     if(i2.gt.120) i2=120
     s2(i2:i2+7,:)=1.0
  endif

  k3=0
  do n=1,NDS                             !Copy symbol spectra from s2 into s3
     if(any(isync(1:NS).eq.n)) cycle     !Skip the sync symbols
     k3=k3+1
     s3(:,k3)=s2(:,n)
  enddo

  call pctile(s3,NQ*NN,50,base3)
  s3=s3/base3

  return
end subroutine sfox_demod
