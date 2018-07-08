; Calculator.asm
; WILLIAM KELLEY
; CS340 - ASSEMBLY LANGUAGE(RIMES)
; CALCULATOR SCREEN INPUT PROGRAM

include Irvine32.inc

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
LF		EQU		10
CR		EQU		13
NULL	EQU		0

var1	dword	?
var2	dword	?

divisor	        dword	10
result		    dword	?
remainder		dword	?
operator		byte	?
times	        dword	8

equal	    byte	" = "
answer	    byte	8 dup (?), CR, LF, NULL
nextline    byte	LF, CR, NULL

outfile dword   ?
output	byte	"CalculatorResults.txt", NULL
input   byte	40 dup (?)

.code
main PROC
		mov edx, offset output
		call CreateOutputFile
		mov outfile, eax
again:
		lea esi, input
		call _READ_LINE
		lea esi, input
		mov eax, outfile
		call _PRINT_TO_FILE
		lea esi, input
		call _ASCII_TO_INT
		mov var1, eax
		dec esi
		call _NEXTDIGIT
		call _ASCII_TO_INT
		mov var2, eax
		lea esi, input
		call _WHICHOPERATOR
		lea esi, answer
		mov ecx, 8
		call _BLANKOUT
		mov eax, result
		call _INT_TO_ASCII
		lea esi, equal
		mov eax, outfile
		call _PRINT_TO_FILE
		lea esi, nextline
		call _WRITE_LINE
		mov ecx, times
		cmp ecx, 0
		dec ecx
		mov times, ecx
		jne again
complete:
		invoke ExitProcess, 0
main endP

_READ_LINE PROC
next_char:
		call ReadChar
		call WriteChar
		mov[esi], al
		cmp al, CR
		je done
		inc esi
		jmp next_char
done:	ret
_READ_LINE endP

_ASCII_TO_INT PROC
		mov ebx, 0
		mov eax, 0
next_digit:
		mov bl, [esi]
		cmp bl, '0'
		jl not_digit
		cmp bl, '9'
		jg not_digit
		sub bl, '0'
		imul eax, 10
		add eax, ebx
		inc esi
		jmp next_digit
not_digit:
		ret
_ASCII_TO_INT endP

_INT_TO_ASCII PROC
next_digit:
		mov edx, 0
		div divisor
		add dl, '0'
		dec esi
		mov [esi], dl
		cmp eax, 0
		jne next_digit
		ret
_INT_TO_ASCII endP

_PRINT_TO_FILE PROC
next:
		mov dl, [esi]
		cmp dl, NULL
		je outOfHere
		mov edx, esi
		mov ecx, 1
		mov eax, outfile
		call WriteToFile
		inc esi
		jmp next
outOfHere:
		ret
_PRINT_TO_FILE endP

_BLANKOUT PROC
mov edx, ' '
blank :
		mov[esi], dl
		inc esi
		dec ecx
		cmp ecx, 0
		jne blank
		ret
_BLANKOUT endP

_NEXTDIGIT PROC
noDigit:
		inc esi
		mov bl, [esi]
		cmp bl, '0'
		jl noDigit
		cmp bl, '9'
		jg noDigit
		ret
_NEXTDIGIT endP

_WHICHOPERATOR PROC
		mov		ebx,0
next:	mov	bl,[esi]
		cmp	bl,'*'
		je	multiply
		cmp	bl,'/'
		je	divide
		cmp	bl,'-'
		je	subtraction
		cmp	bl,'+'
		je	addition
		inc esi
		jmp	next
multiply:	mov	eax, var1
		mov ebx, var2
		imul eax, ebx
		mov	result, eax
		jmp	done
divide:
		mov operator, '/'
		mov	edx, 0
		mov	eax, var1
		idiv var2
		mov	remainder, edx
		mov	result, eax
		jmp	done
addition:	mov	eax, var1
		add	eax, var2
		mov	result, eax
		jmp	done
subtraction:	mov	eax, var1
		sub	eax, var2
		mov result, eax
		jmp done
done:
		ret
_WHICHOPERATOR endP

_WRITE_LINE PROC
next_char:
		mov al, [esi]
		cmp al, NULL
		je nearend
		call WriteChar
		inc esi
		jmp next_char
nearend:
		ret
_WRITE_LINE endP
end main