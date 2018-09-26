* subprogram.f FORTRAN77
* William Kelley
* CS414 Programming Languages(2-15)
* Subprogram testing
* Must be two tabs in for program to run...(FACEPALM)

      INTEGER M,N

      N = 2
      M = 0                         !! Initiating value of M
      
      CALL TEST(N, N, M)
      PRINT *, "N passed by reference", N
      PRINT *, "M passed by reference", M

      STOP
      END

      SUBROUTINE TEST(X, Y, Z)
      INTEGER X, Y, Z
      X = 1                         !! X changes value of N(reference)
      Z = X + Y                     !! Z changes value of M(reference)
      RETURN
      END

c N passed by reference           1
c M passed by reference           2