! { dg-do run }
! { dg-options "-fdec -Wsurprising -Wcharacter-truncation" }
!
! Modified by Mark Eggleston <mark.eggleston@codethink.com>
!
program test
  integer(4) :: a
  real(4) :: b
  complex(4) :: c
  logical(4) :: d
  integer(4) :: e
  real(4) :: f
  complex(4) :: g
  logical(4) :: h

  a = '1234'
  b = '1234'
  c = '12341234'
  d = '1234'     ! { dg-warning "undefined result" }
  e = 4h1234
  f = 4h1234
  g = 8h12341234
  h = 4h1234     ! { dg-warning "undefined result" }
  
  if (a.ne.e) stop 1
  if (b.ne.f) stop 2
  if (c.ne.g) stop 3
  if (d.neqv.h) stop 4

  ! padded values
  a = '12'
  b = '12'
  c = '12234'
  d = '124'   ! { dg-warning "undefined result" }
  e = 2h12
  f = 2h12
  g = 5h12234
  h = 3h123   ! { dg-warning "undefined result" }

  if (a.ne.e) stop 5
  if (b.ne.f) stop 6
  if (c.ne.g) stop 7
  if (d.neqv.h) stop 8

  ! truncated values
  a = '123478'       ! { dg-warning "truncated in" }
  b = '123478'       ! { dg-warning "truncated in" }
  c = '12341234987'  ! { dg-warning "truncated in" }
  d = '1234abc'      ! { dg-warning "truncated in|undefined result" }
  e = 6h123478       ! { dg-warning "truncated in" }
  f = 6h123478       ! { dg-warning "truncated in" }
  g = 11h12341234987 ! { dg-warning "truncated in" }
  h = 7h1234abc      ! { dg-warning "truncated in|undefined result" }

  if (a.ne.e) stop 5
  if (b.ne.f) stop 6
  if (c.ne.g) stop 7
  if (d.neqv.h) stop 8

end program

