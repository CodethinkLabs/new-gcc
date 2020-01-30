! { dg-do compile }
! { dg-options "-fdec -fno-dec-comparisons" }
!
! Test case contributed by Mark Eggleston  <mark.eggleston@codethink.com>
!

program convert
  character(4) :: c = 4HJMAC
  if (4HJMAC.ne.4HJMAC) stop 1 ! { dg-error "Operands of comparison" }
  if (4HJMAC.ne."JMAC") stop 2 ! { dg-error "Operands of comparison" }
  if (4HJMAC.eq."JMAN") stop 3 ! { dg-error "Operands of comparison" }
  if ("JMAC".eq.4HJMAN) stop 4 !  { dg-error "Operands of comparison" }
  if ("AAAA".eq.5HAAAAA) stop 5 ! { dg-error "Operands of comparison" }
  if ("BBBBB".eq.5HBBBB ) stop 6 ! { dg-error "Operands of comparison" }
  if (4HJMAC.ne.c) stop 7 ! { dg-error "Operands of comparison" }
end program

