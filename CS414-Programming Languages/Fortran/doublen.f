* doublen.f FORTRAN77
* William Kelley
* CS414-Programming Languages
* Double N until value is > 100

      program main

      implicit none

      SUM = 0
      DO 10, I = 1,100
         SUM = SUM * 2
         PRINT *, 'Current value', SUM
      10 CONTINUE



      stop
      end
