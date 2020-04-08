! { dg-do compile }
! { dg-options "-std=legacy -fdec -fno-dec-old-init" }
!
! Test old style initializers in derived types
!
        PROGRAM spec_in_var
          TYPE STRUCT1
            INTEGER*4      ID       /8/ ! { dg-error "Invalid old style initialization" }
            INTEGER*4      TYPE     /5/ ! { dg-error "Invalid old style initialization" }
            INTEGER*8      DEFVAL   /0/ ! { dg-error "Invalid old style initialization" }
            CHARACTER*(5)  NAME     /'tests'/ ! { dg-error "Invalid old style initialization" }
            LOGICAL*1      NIL      /0/ ! { dg-error "Invalid old style initialization" }
          END TYPE STRUCT1

          TYPE (STRUCT1) SINST

          if(SINST%ID.NE.8) STOP 1 ! { dg-error "'id' at \\(1\\) is not a member" }
          if(SINST%TYPE.NE.5) STOP 2 ! { dg-error "'type' at \\(1\\) is not a member" }
          if(SINST%DEFVAL.NE.0) STOP 3  ! { dg-error "'defval' at \\(1\\) is not a member" }
          if(SINST%NAME.NE.'tests') STOP 4 ! { dg-error "'name' at \\(1\\) is not a member" }
          if(SINST%NIL) STOP 5 ! { dg-error "'nil' at \\(1\\) is not a member" }
        END
