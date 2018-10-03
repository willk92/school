c William Kelley
c Investigation into Equivalence
c CS414-Programming Languages
c spaces.f

        program equivalence
            D I M E N S I O N A(10), B(10)
            EQUIVALENCE (A, B)
            INTEGER SIZE
            SIZE = 10

                DO 10, I = 1, SIZE
                    A(I) = I                    !! Only placing values into Array A
        10   CONTINUE

                DO 20, I = 1, SIZE
                    PRINT *,"Value of A(", I, ") = ", A(I)
                    PRINT *,"Value of B(", I, ") = ", B(I)
        20   CONTINUE
        end program equivalence

c jdoodle.f95:2:4:
c
c      D I M E N S I O N A(10), B(10)
c     1
c Error: Unclassifiable statement at (1)
c jdoodle.f95:8:12:
c
c              A(I) = I                    !! Only placing values into Array A
c             1
c Error: Unclassifiable statement at (1)
c jdoodle.f95:12:47:
c
c              PRINT *,"Value of A(", I, ") = ", A(I)
c                                                1
c Error: Syntax error in PRINT statement at (1)
c jdoodle.f95:13:47:
c
c              PRINT *,"Value of B(", I, ") = ", B(I)
c                                                1
c Error: Syntax error in PRINT statement at (1)
c
c It appears adding spaces to a particular line of code(in between letters) does not work
c The compiler throws an error as seen in lines 22-26