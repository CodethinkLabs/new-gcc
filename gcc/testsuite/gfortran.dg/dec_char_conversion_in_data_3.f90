! { dg-do run }
! { dg-options "-fdec -fno-dec-char-conversions" }
!
! Modified by Mark Eggleston <mark.eggleston@codethink.com>
!

subroutine normal
  integer(4) :: a
  real(4) :: b
  complex(4) :: c
  logical(4) :: d
  integer(4) :: e
  real(4) :: f
  complex(4) :: g
  logical(4) :: h

  data a, b, c, d / '1234', '1234', '12341234', '1234' / ! { dg-error "Incompatible types" }
  data e, f, g, h / 4h1234, 4h1234, 8h12341234, 4h1234 /
  
  if (a.ne.e) stop 1
  if (b.ne.f) stop 2
  if (c.ne.g) stop 3
  if (d.neqv.h) stop 4
end subroutine

subroutine padded
  integer(4) :: a
  real(4) :: b
  complex(4) :: c
  logical(4) :: d
  integer(4) :: e
  real(4) :: f
  complex(4) :: g
  logical(4) :: h

  data a, b, c, d / '12', '12', '12334', '123' / ! { dg-error "Incompatible types" }
  data e, f, g, h / 2h12, 2h12, 5h12334, 3h123 /
  
  if (a.ne.e) stop 5
  if (b.ne.f) stop 6
  if (c.ne.g) stop 7
  if (d.neqv.h) stop 8
end subroutine

subroutine truncated
  integer(4) :: a
  real(4) :: b
  complex(4) :: c
  logical(4) :: d
  integer(4) :: e
  real(4) :: f
  complex(4) :: g
  logical(4) :: h

  data a, b, c, d / '123478', '123478', '1234123498', '12345' /  ! { dg-error "Incompatible types" }
  data e, f, g, h / 6h123478, 6h123478, 10h1234123498, 5h12345 /
  
  if (a.ne.e) stop 9
  if (b.ne.f) stop 10
  if (c.ne.g) stop 11
  if (d.neqv.h) stop 12
end subroutine

program test
  call normal
  call padded
  call truncated
end program

