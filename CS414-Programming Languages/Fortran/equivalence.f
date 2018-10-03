c William Kelley
c Investigation into Equivalence
c CS414-Programming Languages
c equivalence.f

program equivalence
    DIMENSION A(10), B(10)
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

c  Value of A(           1 ) =    1.00000000
c  Value of B(           1 ) =    1.00000000
c  Value of A(           2 ) =    2.00000000
c  Value of B(           2 ) =    2.00000000
c  Value of A(           3 ) =    3.00000000
c  Value of B(           3 ) =    3.00000000
c  Value of A(           4 ) =    4.00000000
c  Value of B(           4 ) =    4.00000000
c  Value of A(           5 ) =    5.00000000
c  Value of B(           5 ) =    5.00000000
c  Value of A(           6 ) =    6.00000000
c  Value of B(           6 ) =    6.00000000
c  Value of A(           7 ) =    7.00000000
c  Value of B(           7 ) =    7.00000000
c  Value of A(           8 ) =    8.00000000
c  Value of B(           8 ) =    8.00000000
c  Value of A(           9 ) =    9.00000000
c  Value of B(           9 ) =    9.00000000
c  Value of A(          10 ) =    10.0000000
c  Value of B(          10 ) =    10.0000000