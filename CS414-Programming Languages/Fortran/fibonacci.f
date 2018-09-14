* fibnoacci.f FORTRAN77
* William Kelley
* CS414 Programming Languages(2-3)
* Fibonacci sequence until 1000 is reached
* Must be two tabs in for program to run...(FACEPALM)

        PROGRAM MAIN

        INTEGER X1, X2, FIB, MAX

        X1 = 0
        X2 = 1
        FIB = 0
        MAX = 1000

        DO WHILE(FIB.LT.MAX)
            FIB = X1 + X2
            X1 = X2
            X2 = FIB
            PRINT *, "Current Fibonacci Number", FIB
        END DO

        STOP
        END

c RESULTS FOR ABOVE PROGRAM
c parallels@ubuntu:~/school/CS414-Programming Languages/Fortran$ ./fibonacci
c  Current Fibonacci Number           1
c  Current Fibonacci Number           2
c  Current Fibonacci Number           3
c  Current Fibonacci Number           5
c  Current Fibonacci Number           8
c  Current Fibonacci Number          13
c  Current Fibonacci Number          21
c  Current Fibonacci Number          34
c  Current Fibonacci Number          55
c  Current Fibonacci Number          89
c  Current Fibonacci Number         144
c  Current Fibonacci Number         233
c  Current Fibonacci Number         377
c  Current Fibonacci Number         610
c  Current Fibonacci Number         987
c  Current Fibonacci Number        1597