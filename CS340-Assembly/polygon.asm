;polygon.asm - Sums Array, Finds Average with Remainder, Prints Human-Readable Output
; WILLIAM KELLEY
; CS340 - ASSEMBLY LANGUAGE(RIMES)
; PROGRAMMING ASSIGNMENT 2

; setup for blankout proc
;   move 8 to ecx for counter since there is 8 array indexes for our string
;   load effective address of strg to esi, this will move the beginning memory address location of the array to esi register

INCLUDE Irvine32.inc

.386
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
CR      EQU     10
LF      EQU     13
NULL    EQU     0

input   dword   "PolygonIn.txt", 0

line1   byte    "Sum =       ", 0
strg    byte    8 dup(?)
        byte    CR, LF, NULL                    ;doesn't seem to work as intended(discuss)
exvar   dword   0
poly1   dword   0
poly2   dword   0
poly3   dword   0
poly4   dword   0
poly5   dword   0

.code
main proc
    mov	eax,    0               ;clean up reg eax for sum

;Remainder Print Line
    mov eax,    rem             ;move avg(average) to eax register(linkage for ItoA conversion)
    mov edx,    0               ;cleanup edx
    mov ecx,    8               ;8 indexes in array, set the counting register to # of indexes
    lea esi,    strg            ;load the address of beginning of strg array to esi

    lea edx,    line1           ;load description into edx to write out
    call writeString

    call _BLANKOUT              ;blankout strg for sum conversion ItoA
    call _ITOA                  ;convert sum ItoA
    lea edx,    strg            ;load number into edx to write out(sum)
    call writeString            ;write {sum} out to console


    invoke ExitProcess,0
main endP