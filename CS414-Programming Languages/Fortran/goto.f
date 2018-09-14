* fibnoacci.f FORTRAN77
* William Kelley
* CS414 Programming Languages(2-4)
* GOTO written as IF statements
* Must be two tabs in for program to run...(FACEPALM)

        IMPLICIT NONE
        INTEGER  I                                     !! Index.

c.......................................................................

C     Initial value.
        I=0
*     I=2                                            !! To test error.

c.......................................................................

C     Set index.
    1   CONTINUE
        WRITE(*,*)
        I=I+1

C     Check range of I.
        IF (I.GT.2) GOTO 95                            !! Error.

C     Choose path.
        WRITE(*,*) 'I =',I,'  Starting'
        IF (I.EQ.1) GOTO 10                            !! First path.
        GOTO 20                                        !! Second path.

C     First path.
   10   CONTINUE
        WRITE(*,*) 'I =',I,'  Got to 10'
        GOTO 30                                        !! Both paths.

C     Second path.
   20   CONTINUE
        WRITE(*,*) 'I =',I,'  Got to 20'

C     Both paths.
   30   CONTINUE
        WRITE(*,*) 'I =',I,'  Got to 30'
        IF (I.EQ.2) GOTO 99                            !! Finish off.
        GOTO 1                                         !! Set index.

c.......................................................................

C     Error: I too large.
   95   CONTINUE
        WRITE(*,*) 'I =',I,'  Got to 95'

c.......................................................................

C     Finish off.
   99   CONTINUE
        WRITE(*,*) 'I =',I,'  Got to 99'

        STOP ' '
        END