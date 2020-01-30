! { dg-do compile }
! { dg-options "-fdec" }
!
! Test promotion between integers and reals in intrinsic operations.
! These operations are: mod, modulo, dim, sign, min, max, minloc and
! maxloc.
!
! Contributed by Francisco Redondo Marchena <francisco.marchena@codethink.co.uk>
!             and Jeff Law <law@redhat.com>
! Modified by Mark Eggleston <mark.eggleston@codethink.com>
!
      PROGRAM promotion_int_real
        REAL l/0.0/
        INTEGER a_i/4/
        INTEGER*4 a2_i/4/
        CHARACTER b_c
        CHARACTER*8 b2_c
        INTEGER x_i/2/
        CHARACTER y_c
        REAL a_r/4.0/
        REAL*4 a2_r/4.0/
        LOGICAL b_l
        LOGICAL*8 b2_l
        REAL x_r/2.0/
        LOGICAL y_l

        INTEGER m_i/0/
        REAL m_r/0.0/

        INTEGER md_i/0/
        REAL md_r/0.0/

        INTEGER d_i/0/
        REAL d_r/0.0/

        INTEGER s_i/0/
        REAL s_r/0.0/

        INTEGER mn_i/0/
        REAL mn_r/0.0/

        INTEGER mx_i/0/
        REAL mx_r/0.0/

        m_i = MOD(a_i, b_c)                     ! { dg-error "" }
        if (m_i .ne. 1) STOP 1
        m_i = MOD(a2_i, b2_c)                   ! { dg-error "" }
        if (m_i .ne. 1) STOP 2
        m_r = MOD(a_r, b_l)                     ! { dg-error "" }
        if (abs(m_r - 1.0) > 1.0D-6) STOP 3
        m_r = MOD(a2_r, b2_l)                   ! { dg-error "" }
        if (abs(m_r - 1.0) > 1.0D-6) STOP 4
        m_r = MOD(a_i, b_l)                     ! { dg-error "" }
        if (abs(m_r - 1.0) > 1.0D-6) STOP 5
        m_r = MOD(a_r, b_c)                     ! { dg-error "" }
        if (abs(m_r - 1.0) > 1.0D-6) STOP 6

        md_i = MODULO(a_i, b_c)                 ! { dg-error "" }
        if (md_i .ne. 1) STOP 7
        md_i = MODULO(a2_i, b2_c)               ! { dg-error "" }
        if (md_i .ne. 1) STOP 8
        md_r = MODULO(a_r, b_l)                 ! { dg-error "" }
        if (abs(md_r - 1.0) > 1.0D-6) STOP 9
        md_r = MODULO(a2_r, b2_l)               ! { dg-error "" }
        if (abs(md_r - 1.0) > 1.0D-6) STOP 10
        md_r = MODULO(a_i, b_l)                 ! { dg-error "" }
        if (abs(md_r - 1.0) > 1.0D-6) STOP 11
        md_r = MODULO(a_r, b_c)                 ! { dg-error "" }
        if (abs(md_r - 1.0) > 1.0D-6) STOP 12

        d_i = DIM(a_i, b_c)                     ! { dg-error "" }
        if (d_i .ne. 1) STOP 13
        d_i = DIM(a2_i, b2_c)                   ! { dg-error "" }
        if (d_i .ne. 1) STOP 14
        d_r = DIM(a_r, b_l)                     ! { dg-error "" }
        if (abs(d_r - 1.0) > 1.0D-6) STOP 15
        d_r = DIM(a2_r, b2_l)                   ! { dg-error "" }
        if (abs(d_r - 1.0) > 1.0D-6) STOP 16
        d_r = DIM(a_r, b_c)                     ! { dg-error "" }
        if (abs(d_r - 1.0) > 1.0D-6) STOP 17
        d_r = DIM(b_c, a_r)                     ! { dg-error "" }
        if (abs(d_r) > 1.0D-6) STOP 18

        s_i = SIGN(-a_i, b_c)                   ! { dg-error "" }
        if (s_i .ne. 4) STOP 19
        s_i = SIGN(-a2_i, b2_c)                 ! { dg-error "" }
        if (s_i .ne. 4) STOP 20
        s_r = SIGN(a_r, -b_l)                   ! { dg-error "" }
        if (abs(s_r - (-a_r)) > 1.0D-6) STOP 21
        s_r = SIGN(a2_r, -b2_l)                 ! { dg-error "" }
        if (abs(s_r - (-a2_r)) > 1.0D-6) STOP 22
        s_r = SIGN(a_r, -b_c)                   ! { dg-error "" }
        if (abs(s_r - (-a_r)) > 1.0D-6) STOP 23
        s_r = SIGN(-a_i, b_l)                   ! { dg-error "" }
        if (abs(s_r - a_r) > 1.0D-6) STOP 24

        mx_i = MAX(-a_i, -b_c, x_i, y_c)        ! { dg-error "" }
        if (mx_i .ne. x_i) STOP 25
        mx_i = MAX(-a2_i, -b2_c, x_i, y_c)      ! { dg-error "" }
        if (mx_i .ne. x_i) STOP 26
        mx_r = MAX(-a_r, -b_l, x_r, y_l)        ! { dg-error "" }
        if (abs(mx_r - x_r) > 1.0D-6) STOP 27
        mx_r = MAX(-a_r, -b_l, x_r, y_l)        ! { dg-error "" }
        if (abs(mx_r - x_r) > 1.0D-6) STOP 28
        mx_r = MAX(-a_i, -b_l, x_r, y_c)        ! { dg-error "" }
        if (abs(mx_r - x_r) > 1.0D-6) STOP 29

        mn_i = MIN(-a_i, -b_c, x_i, y_c)        ! { dg-error "" }
        if (mn_i .ne. -a_i) STOP 31
        mn_i = MIN(-a2_i, -b2_c, x_i, y_c)      ! { dg-error "" }
        if (mn_i .ne. -a2_i) STOP 32
        mn_r = MIN(-a_r, -b_l, x_r, y_l)        ! { dg-error "" }
        if (abs(mn_r - (-a_r)) > 1.0D-6) STOP 33
        mn_r = MIN(-a2_r, -b2_l, x_r, y_l)      ! { dg-error "" }
        if (abs(mn_r - (-a2_r)) > 1.0D-6) STOP 34
        mn_r = MIN(-a_i, -b_l, x_r, y_c)        ! { dg-error "" }
        if (abs(mn_r - (-a_r)) > 1.0D-6) STOP 35
      END PROGRAM
