subroutine normalizebmet(bmet, n)
! Normalize bit metrics: subtract mean, divide by std deviation
! This matches FT8's normalizebmet() behavior (from ft8b.f90)
  implicit none
  integer, intent(in) :: n
  real, intent(inout) :: bmet(n)
  real :: bmetav, bmet2av, var, bmetsig

  bmetav = sum(bmet) / real(n)
  bmet2av = sum(bmet*bmet) / real(n)
  var = bmet2av - bmetav*bmetav
  if( var .gt. 0.0 ) then
    bmetsig = sqrt(var)
  else
    bmetsig = sqrt(bmet2av)
  endif
  if(bmetsig .gt. 0.0) bmet = bmet / bmetsig
  return
end subroutine normalizebmet
