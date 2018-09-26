* goto.f FORTRAN77
* William Kelley
* CS414 Programming Languages(2-4)
* GOTO written as IF statements
* Must be two tabs in for program to run...(FACEPALM)

        IMPLICIT NONE
        INTEGER  I                                     !! Index.

        I=0

    1   CONTINUE
        WRITE(*,*)
        I=I+1

        WRITE(*,*) 'Starting'
        IF (I.EQ.1) GOTO 1                          
        GOTO 10                                        

   10   CONTINUE
        WRITE(*,*) 'Got to 10'
        IF (I.EQ.2) GOTO 1
        GOTO 20                                  

   20   CONTINUE
        WRITE(*,*) 'Got to 20'
        IF (I.EQ.3) GOTO 1
        GOTO 30

   30   CONTINUE
        WRITE(*,*) 'Got to 30'
        IF (I.EQ.4) GOTO 1                            !! Finish off.
        GOTO 40                                         !! Set index.

   40   CONTINUE
        WRITE(*,*) 'Got to 40'

        STOP
        END

         Starting

c  Got to 10

c  Starting
c  Got to 10
c  Got to 20

c  Starting
c  Got to 10
c  Got to 20
c  Got to 30

c  Starting
c  Got to 10
c  Got to 20
c  Got to 30
c  Got to 40