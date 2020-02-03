! { dg-do run }
! { dg-options "-cpp -w" }
!
! Test case contributed by Mark Eggleston  <mark.eggleston@codethink.com>

program test
  implicit none
  integer(1) :: a1 = 1_1
  integer(2) :: a2 = 2_2
  integer(4) :: a4 = 4_4
  integer(8) :: a8 = 8_8
  real(4) :: b4 = 4.0_4
  real(8) :: b8 = 8.0_8
#ifdef __GFC_REAL_16__
  real(16) :: b16 = 16.0_16
#endif
  ! Integers
  if (kind(max(1_1, 2_2, 4_4, 8_8)).ne.8) stop 1
  if (kind(max(1_1, 2_2, 4_4, a8)).ne.8) stop 2
  if (kind(max(8_8, 4_4, 2_2, 1_1)).ne.8) stop 3
  if (kind(max(4_4, 8_8, 2_2, 1_1)).ne.8) stop 4
  if (kind(max(2_2, 8_8, 4_4, 1_1)).ne.8) stop 5
  if (kind(max(a1, a2, a4)).ne.4) stop 6
  if (kind(max(a2, a4, a1)).ne.4) stop 7
  if (kind(min(1_1, 2_2, 4_4, 8_8)).ne.8) stop 8
  if (kind(min(1_1, 2_2, 4_4, a8)).ne.8) stop 9
  if (kind(min(10_1, 4_4, 2_2, 15_1)).ne.4) stop 10
  if (kind(min(4_4, 8_8, 2_2, 1_1)).ne.8) stop 11
  if (kind(min(2_2, 8_8, 4_4, 1_1)).ne.8) stop 12
  if (kind(min(a1, a2, a4)).ne.4) stop 13
  if (kind(min(a2, a4, a1)).ne.4) stop 14
  ! Reals
#ifdef __GFC_REAL_16__
  if (kind(max(b4, b8, b16)).ne.16) stop 15
  if (kind(max(7.0_8, 6.8_4, 77.0_16)).ne.16) stop 16
#endif
  if (kind(max(1.0_4, b8, 3.0_4, 78.0)).ne.8) stop 18
#ifdef __GFC_REAL_16__
  if (kind(min(b4, b8, b16)).ne.16) stop 19
  if (kind(min(7.0_8, 6.8_4, 77.0_16)).ne.16) stop 20
#endif
  if (kind(min(3.0_4, b8, 0.0_4, 78.0)).ne.8) stop 21 
end
