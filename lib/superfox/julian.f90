module julian

contains

  integer*8 function itime8()

    implicit integer (a-z)
!                  1 2 3  4   5 6 7
    integer it(8) !y m d nmin h m s
    integer*8 secday
    data secday/86400/

    call date_and_time(values=it)
    iyr=it(1)
    imo=it(2)
    iday=it(3)
    days=JD(iyr,imo,iday) - 2440588        !Days since epoch Jan 1, 1970
    ih=it(5)
    im=it(6)-it(4)                         !it(4) corrects for time zone
    is=it(7)
    nsec=3600*ih + 60*im + is
    itime8=days*secday + nsec

    return
  end function itime8

  integer function JD(I,J,K)

! Return Julian Date for I=year, J=month, K=day
! Reference: Fliegel and Van Flandern, Comm. ACM 11, 10, 1968

    JD = K - 32075 + 1461*(I + 4800 + (J - 14)/12)/4            &
         + 367*(J - 2 - (J - 14)/12*12)/12 - 3                  &
         *((I + 4900 + (J - 14)/12)/100)/4

    return
  end function JD

end module julian
