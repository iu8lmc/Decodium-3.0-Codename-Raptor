! ─────────────────────────────────────────────────────────────
! C-callable wrappers for pack77/unpack77 (which live in module packjt77)
! ─────────────────────────────────────────────────────────────

subroutine pack77_c(msg0, i3, n3, c77) bind(C, name="pack77_c")
  use iso_c_binding
  use packjt77
  implicit none
  character(kind=c_char), intent(in)  :: msg0(37)
  integer(c_int),         intent(out) :: i3, n3
  character(kind=c_char), intent(out) :: c77(77)

  character*37 fmsg
  character*77 fc77
  integer :: fi3, fn3, k

  ! Copy C chars to Fortran string
  do k = 1, 37
    fmsg(k:k) = msg0(k)
  end do

  fi3 = -1
  fn3 = -1
  call pack77(fmsg, fi3, fn3, fc77)

  i3 = fi3
  n3 = fn3

  ! Copy Fortran string to C chars
  do k = 1, 77
    c77(k) = fc77(k:k)
  end do
end subroutine pack77_c


subroutine unpack77_c(c77, nrx, msg, success) bind(C, name="unpack77_c")
  use iso_c_binding
  use packjt77
  implicit none
  character(kind=c_char), intent(in)  :: c77(77)
  integer(c_int),         intent(in)  :: nrx
  character(kind=c_char), intent(out) :: msg(37)
  integer(c_int),         intent(out) :: success

  character*77 fc77
  character*37 fmsg
  integer :: fnrx, k
  logical :: unpk_ok

  ! Copy C chars to Fortran string
  do k = 1, 77
    fc77(k:k) = c77(k)
  end do

  fnrx = nrx
  fmsg = ' '
  call unpack77(fc77, fnrx, fmsg, unpk_ok)

  ! Copy Fortran string to C chars
  do k = 1, 37
    msg(k) = fmsg(k:k)
  end do

  if (unpk_ok) then
    success = 1
  else
    success = 0
  endif
end subroutine unpack77_c
