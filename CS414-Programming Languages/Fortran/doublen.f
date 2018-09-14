* doublen.f FORTRAN77
* William Kelley
* CS414-Programming Languages(2-2)
* Double N until value is > 100

      PROGRAM MAIN

      INTEGER VALUE, MAX

      VALUE = 1
      MAX = 100
      DO WHILE (VALUE.LT.MAX)
            VALUE = VALUE * 2
            PRINT *, "Current Value: ", VALUE
      END DO

      STOP
      END

c RESULTS OF ABOVE PROGRAM:
c parallels@ubuntu:~/school/CS414-Programming Languages/Fortran$ ./doublen
c  Current Value:            2
c  Current Value:            4
c  Current Value:            8
c  Current Value:           16
c  Current Value:           32
c  Current Value:           64
c  Current Value:          128