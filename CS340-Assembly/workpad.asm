; SumArray.asm - Sums Array, Finds Average with Remainder, Prints Human-Readable Output
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

ary     dword   150, -50, 125, 90, 35, -192, 52, 634, 193, 999
        dword   -524, 1, -5, 300, 25, 71, 414, 143, 142, 52, -32, 58
        dword   56, 42, -81, 25, 93, 151, 215, 0

line1   byte    "Sum =       ", 0
strg    byte    8 dup(?)
        byte    CR, LF, NULL                    ;doesn't seem to work as intended(discuss)
line2   byte    CR, LF, "Average =   ", 0
line3   byte    CR, LF, "Remainder = ", 0
exvar   dword   0
poly1   dword   0
poly2   dword   0
poly3   dword   0
poly4   dword   0
poly5   dword   0
poly6   dword   0
poly7   dword   0

.code
main proc
    mov	eax,    0               ;clean up reg eax for sum
    mov ecx,    0               ;clean up reg ecx for counter
    mov ebx,    exvar           ;move the exit variable to a register for compares

    lea esi,    ary             ;move the memory location of ary to esi

sumx:add eax,    [esi]          ;add value in memory location [esi] to register eax to start summing
    inc ecx                     ;increment the loop counter for averaging
    add esi,    4               ;add 4 bytes(dword) to indexer to move to next location
    cmp [esi],  ebx             ;check to see if next value in array is the exit variable
    jne sumx

;Remainder Print Line
    mov eax,    rem             ;move avg(average) to eax register(linkage for ItoA conversion)
    mov edx,    0               ;cleanup edx
    mov ecx,    8               ;8 indexes in array, set the counting register to # of indexes
    lea esi,    strg            ;load the address of beginning of strg array to esi

    lea edx,    line3           ;load description into edx to write out
    call writeString

    call _BLANKOUT              ;blankout strg for sum conversion ItoA
    call _ITOA                  ;convert sum ItoA
    lea edx,    strg            ;load number into edx to write out(sum)
    call writeString            ;write {sum} out to console


    invoke ExitProcess,0
main endP

_BLANKOUT PROC
        mov edx,    " "
nexB:   mov [esi],  edx             ;add "blank" ASCII character to current location in array
        dec ecx                     ;decrease counter by 1
        inc esi                     ;increment array by a single byte
        cmp ecx,    0               ;is the counter equal to 0? if so, return back to main proc, if not, keep going
        jne nexB                    ;jump back to top of nexB(nextBlank)
        ret
_BLANKOUT endP

_ITOA PROC
        mov ebx, 10
nexdig: mov edx,   0                ;cleanup edx register
        idiv    ebx                 ;lop off 10 for the smallest #
        add dl,     '0'             ;add character 0 to turn hex remaineder to ASCII
        dec esi                     ;move esi's location back to within array(we passed it when we blanked it out)
        mov [esi],  dl              ;move value from dl to array location
        cmp eax,    0               ;is eax 0 yet
        jne nexdig
        ret
_ITOA endP

end main

;Starting value is 275, final value is 150(cents)
;ticPrice = 275
;ticSold = 130
;ticExp = 85

;while(ticPrice > 149)
;	cout ticPrice, ticSold, (ticPrice-ticExp)
;	ticPrice = ticPrice - 5
;	ticSold = ticSold + 16
;	ticExp = ticExp + 3
;	is ticPrice > 149? If so, keep going; if not, fall out(output should have happened or will happen, idk)
;Function return


;set starting value for ticPrice, ticSold, ticExp
tmp1  byte  0
tmp2  byte  0
tmp3  byte  0
exvar byte  149 ;may need to be 150

ary     dword   5000 dup(" ") ;setup array with blanks
strg    byte    8 dup(?) ;setup array for ITOA conversion

ticPrice  SET   275
ticSold   SET   130
ticExp    SET   85

lea esi, ary ; move memory location of array holding values to esi so it can be loaded with necessary values

call _BUILDOUTPUT

;convert entire ary to ascii


;move ticPrice, ticSold, ticExp to array locations in preparation for output
_BUILDOUTPUT PROC
  Again:mov [esi],      ticPrice
        ;mov [esi+4],    ticSold
        ;mov [esi+8],    ticExp
        inc esi                     ;move array down 3 locations
        ;use previous values to build next ones
        mov eax,        ticPrice
        mov edx,    0               ;cleanup edx
        mov ecx,    8               ;8 indexes in array, set the counting register to # of indexes
        lea esi,    strg            ;load the address of beginning of strg array to esi

        call _BLANKOUT              ;blankout strg for sum conversion ItoA
        call _ITOA                  ;convert sum ItoA
        lea edx,    strg            ;load number into edx to write out(sum)
        call writeString            ;write out to console
        ;add eax,        -5
        ;mov eax,        ticSold
        ;add eax,        16
        ;mov eax,        ticExp
        ;add eax,        3
        cmp ticPrice,   exvar
        jne Again ; go back around if ticPrice is NOT equal to 149(less than 150 so don't input into array)
        ret
_BUILDOUTPUT endP

;_MOVEITOATOOUTPUT PROC
; move [esi](value for ticPrice, ticSold, ticExp, etc) to a register, itoa on that register and place in strg, move strg to a register, move that register back to [esi] where it was so its now an ascii value versus an integer value
;        lea esi,        ary
;        mov eax,        [esi]
;        mov edx,        0               ;cleanup edx
;        mov ecx,        8               ;8 indexes in array, set the counting register to # of indexes
;        lea esi,        strg            ;load the address of beginning of strg array to esi
;        call _BLANKOUT
;        call _ITOA
;        lea esi,



