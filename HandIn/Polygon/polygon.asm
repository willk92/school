; polygon.asm
; WILLIAM KELLEY
; CS340 - ASSEMBLY LANGUAGE(RIMES)
; CALCULATES AREA OF ANY POLYGON

INCLUDE Irvine32.inc

.386
.stack 4096
ExitPROCess proto,dwExitCode:dword

.data
CR			EQU		13
LF			EQU 	10
NULL		EQU 	0

buffer		byte	500 dup(?)
array		dword	25 dup(' ')
output		byte	"PolygonAreas.txt", NULL
filename	byte	"PolygonIn.txt", NULL
infile		dword	?
outfile		dword	?

next	    dword	?
ten			dword	10
two			dword	2

area		    dword	?
area_remainder	dword	?

polygon_message		byte	"polygon "
polygon_count		byte	1 dup(?)
polygon_area	    byte	" area: "
area_message		byte	5 dup(?), NULL
next_line	        byte	CR, LF, NULL


.code
main PROC
		mov edx, offset output
		call CreateOutputFile
		mov outfile, eax
		mov edx, offset filename
		call OpenInputFile
		cmp eax, 0
		je failure
		mov infile, eax
		mov ecx, 500
		mov edx, offset buffer
		mov eax, infile
		call ReadFromFile
		mov ecx, 1
		mov next, offset buffer
main_loop:
		lea esi, array
		push ecx
		mov ecx, 25
		call _BLANK_ARRAY
		mov esi, next
		mov edi, offset array
		call _NEXT_SHAPE
		mov next, esi
		lea esi, array
		call _DUP_STARTING
		mov ecx, 0
		lea esi, array
		call _AREA
		pop ecx
		mov dl, cl
		add dl, '0'
		mov polygon_count, dl
		push ecx
		mov ecx, 5
		lea esi, area_message
		call _BLANKOUT
		mov eax, area
		call _INT_TO_ASCII
		lea esi, polygon_message
		mov eax, outfile
		call _PRINT_TO_FILE
		cmp area_remainder, 0
		je print_newline
		mov eax, outfile
		call _PRINT_TO_FILE
print_newline:
		lea esi, next_line
		mov eax, outfile
		call _PRINT_TO_FILE
		pop ecx
		inc ecx
		cmp ecx, 6
		jne main_loop
		
failure:
		invoke ExitPROCess, 0
main endP

_NEXT_SHAPE PROC
next_point:
		mov al, [esi]
		mov bl, 1[esi]
		cmp al, CR
		je done
		cmp al, ' '
		je space
		cmp bl, ' '
		jne two_digits
		sub al, '0'
		mov [edi], al
		inc esi
		add edi, 4
		jmp next_point
two_digits:
		sub al, '0'
		mul ten
		sub bl, '0'
		add al, bl
		mov [edi], al
		add edi, 4
		add esi, 2
		jmp next_point
space:
		inc esi
		jmp next_point
done:
		inc esi
		inc esi
		ret
_NEXT_SHAPE endP

_BLANK_ARRAY PROC
next_blank:
		cmp ecx, 0
		je all_blank
		mov al, ' '
		mov [esi], al
		add esi, 4
		dec ecx
		jmp next_blank
all_blank:
		ret
_BLANK_ARRAY endP

_DUP_STARTING PROC
		mov eax, [esi]
		mov ebx, 4[esi]
blankless:
		inc esi
		mov edx, [esi]
		cmp edx, ' '
		jne blankless
		mov [esi], eax
		mov 4[esi], ebx
		ret
_DUP_STARTING endP

_AREA PROC
next_points:
		mov edx, 12[esi]
		cmp edx, ' '
		je done
		mov eax, 8[esi]
		imul eax, 4[esi]
		mov ebx, [esi]
		imul ebx, 12[esi]
		sub eax, ebx
		add ecx, eax
		add esi, 8
		jmp next_points
done:
		mov edx, 0
		mov eax, ecx
		idiv two
		mov area, eax
		mov area_remainder, edx
		ret
_AREA endP

_INT_TO_ASCII PROC
next_digit:
		mov edx, 0
		div ten
		add dl, '0'
		dec esi
		mov [esi], dl
		cmp eax, 0
		jne next_digit
		ret
_INT_TO_ASCII endP

_PRINT_TO_FILE PROC
nextCharacter:
		mov dl, [esi]
		cmp dl, NULL
		je outOfHere
		mov edx, esi
		mov ecx, 1
		mov eax, outfile
		call WriteToFile
		inc esi
		jmp nextCharacter
outOfHere:
		ret
_PRINT_TO_FILE endP

_BLANKOUT PROC
mov edx, ' '
blank:
		mov[esi], dl
		inc esi
		dec ecx
		cmp ecx, 0
		jne blank
		ret
_BLANKOUT endP

end main