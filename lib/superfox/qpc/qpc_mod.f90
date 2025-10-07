module qpc_mod
  interface
     integer(c_int32_t) function nhash2 (xin, length, initval) bind(C,  &
          name="nhash2")
       use iso_c_binding, only: c_signed_char, c_int64_t, c_int32_t
       integer(c_int64_t), intent(in), value :: length
       integer(c_signed_char), intent(in) :: xin(length)
       integer(c_int32_t), intent(in), value :: initval
     end function nhash2
  end interface

  interface
     subroutine qpc_encode(y, xin) bind(C,name="qpc_encode")
       use iso_c_binding, only: c_ptr, c_signed_char
       integer(c_signed_char), intent(out) :: y(127)
       integer(c_signed_char), intent(in) :: xin(50)
     end subroutine qpc_encode
  end interface

  interface
     subroutine qpc_channel(yout, y, EsNo) bind(C,name="qpc_channel")
       use iso_c_binding, only: c_float_complex, c_float, c_signed_char
       complex(c_float_complex), intent(out) :: yout(128,128)
       integer(c_signed_char), intent(out) :: y(127)
       real(c_float), intent(in), value :: EsNo
     end subroutine qpc_channel
  end interface

  interface
     subroutine qpc_decode(xdec, ydec, py) bind(C,name="qpc_decode")
       use iso_c_binding, only: c_float, c_signed_char
       real(c_float), intent(in) :: py(128,128)
       integer(c_signed_char), intent(out) :: ydec(127)
       integer(c_signed_char), intent(out) :: xdec(50)
     end subroutine qpc_decode
  end interface

end module qpc_mod
