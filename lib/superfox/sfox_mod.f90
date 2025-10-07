module sfox_mod
  
  parameter (NMAX=15*12000)       !Samples in iwave (180,000)
  integer MM,NQ,NN,KK,NS,NDS,NFZ,NSPS,NSYNC,NZ,NFFT1
  real baud,tsym,bw

contains
  subroutine sfox_init(mm0,nn0,kk0,itu,fspread,delay,fsample,ns0)

    character*2 itu
    integer isps(54)
    integer iloc(1)
    data isps/ 896, 960, 972, 980,1000,1008,1024,1029,1050,1080,   &
              1120,1125,1134,1152,1176,1200,1215,1225,1250,1260,   &
              1280,1296,1323,1344,1350,1372,1400,1440,1458,1470,   &
              1500,1512,1536,1568,1575,1600,1620,1680,1701,1715,   &
              1728,1750,1764,1792,1800,1875,1890,1920,1944,1960,   &
              2000,2016,2025,2048/

    MM=mm0              !Bits per symbol
    NQ=2**MM            !Q, number of MFSK tones
    NN=nn0              !Codeword length
    KK=kk0              !Number of information symbols
    NS=ns0              !Number of sync symbols
    NDS=NN+NS           !Total number of channel symbols
    NFZ=3               !First zero

    jsps=nint(12.8*fsample/NDS)
    iloc=minloc(abs(isps-jsps))
    NSPS=isps(iloc(1))  !Samples per symbol
    NSYNC=NS*NSPS       !Samples in sync waveform
    NZ=NSPS*NDS         !Samples in full Tx waveform
    NFFT1=2*NSPS        !Length of FFTs for symbol spectra
    
    baud=fsample/NSPS
    tsym=1.0/baud
    bw=NQ*baud

    fspread=0.0
    delay=0.0
    if(itu.eq.'LQ') then
       fspread=0.5
       delay=0.5
    else if(itu.eq.'LM') then
       fspread=1.5
       delay=2.0
    else if(itu.eq.'LD') then
       fspread=10.0
       delay=6.0
    else if(itu.eq.'MQ') then
       fspread=0.1
       delay=0.5
    else if(itu.eq.'MM') then
       fspread=0.5
       delay=1.0
    else if(itu.eq.'MD') then
       fspread=1.0
       delay=2.0
    else if(itu.eq.'HQ') then
       fspread=0.5
       delay=1.0
    else if(itu.eq.'HM') then
       fspread=10.0
       delay=3.0
    else if(itu.eq.'HD') then
       fspread=30.0
       delay=7.0
    endif

    return
  end subroutine sfox_init

end module sfox_mod
