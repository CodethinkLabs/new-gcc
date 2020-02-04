! { dg-do compile }
! { dg-options "-Wall -std=f2003" }
! Tests the patch for PR27996 and PR27998, in which warnings
! or errors were not emitted when the length of character
! constants was changed silently.
!
! Contributed by Tobias Burnus <tobias.burnus@physik.fu-berlin.de> 
!
program test
  implicit none
  character(10) :: a(3)
  character(10) :: b(3)= &
       (/ 'Takata ', 'Tanaka', 'Hayashi' /) ! { dg-error "Different CHARACTER" }
  character(4) :: c = "abcde"  ! { dg-warning "CHARACTER\\(5\\) truncated to CHARACTER\\(4\\)" }
  a =  (/ 'Takata', 'Tanaka ', 'Hayashi' /) ! { dg-error "Different CHARACTER" }
  a =  (/ 'Takata ', 'Tanaka ', 'Hayashi' /)
  b = "abc" ! { dg-error "no IMPLICIT" }
  c = "abcdefg"   ! { dg-warning " CHARACTER\\(7\\) truncated to CHARACTER\\(4\\)" }
end program test
