* const.f FORTRAN77
* William Kelley
* CS414 Programming Languages(Investigation)
* Can we change a constant?
* Must be two tabs in for program to run...(FACEPALM)

      INTEGER*4 N
      N = +2

      PRINT *, "Before attempting to change constant N =>", N

      N = 3

      PRINT *, "After attempting to change constant N => ", N

      STOP
      END

c  Before attempting to change constant N =>           2
c  After attempting to change constant N =>            3
c  It appears a FORTRAN77 constant can be changed.