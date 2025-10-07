!*******************************************************************************
!>
! A simple module for `popen`.

    module popen_module

    use,intrinsic :: iso_c_binding

    implicit none

    private

    ! interfaces to C functions
    interface

        function popen(command, mode) bind(C,name='popen')
        !! initiate pipe streams to or from a process
        import :: c_char, c_ptr
        implicit none
        character(kind=c_char),dimension(*) :: command
        character(kind=c_char),dimension(*) :: mode
        type(c_ptr) :: popen
        end function popen

        function fgets(s, siz, stream) bind(C,name='fgets')
        !! get a string from a stream
        import :: c_char, c_ptr, c_int
        implicit none
        type (c_ptr) :: fgets
        character(kind=c_char),dimension(*) :: s
        integer(kind=c_int),value :: siz
        type(c_ptr),value :: stream
        end function fgets

        function pclose(stream) bind(C,name='pclose')
        !! close a pipe stream to or from a process
        import :: c_ptr, c_int
        implicit none
        integer(c_int) :: pclose
        type(c_ptr),value :: stream
        end function pclose

    end interface

    public :: c2f_string, get_command_as_string

contains

    !*******************************************************************************
    !>
    !  Convert a C string to a Fortran string.

    function c2f_string(c) result(f)

        character(len=*),intent(in) :: c !! C string
        character(len=:),allocatable :: f !! Fortran string

        integer :: i

        i = index(c,c_null_char)

        if (i<=0) then
            f = c
        else if (i==1) then
            f = ''
        else if (i>1) then
            f = c(1:i-1)
        end if

    end function c2f_string

    !*******************************************************************************
    !>
    !  Return the result of the command as a string.

    function get_command_as_string(command) result(str)

        character(len=*),intent(in) :: command !! the command to run
        character(len=:),allocatable :: str !! the result of that command

        integer,parameter :: buffer_length = 1000 !! read stream in chunks of this size

        type(c_ptr) :: h !! for `popen`
        integer(c_int) :: istat !! `pclose` status
        character(kind=c_char,len=buffer_length) :: line !! buffer to read from `fgets`

        str = ''
        h = c_null_ptr
        h = popen(command//c_null_char,'r'//c_null_char)

        if (c_associated(h)) then
            do while (c_associated(fgets(line,buffer_length,h)))
                str = str//c2f_string(line)
            end do
            istat = pclose(h)
        end if

    end function get_command_as_string

!*******************************************************************************
    end module popen_module
!*******************************************************************************
    
