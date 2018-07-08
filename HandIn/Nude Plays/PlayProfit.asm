; PlayProfit.asm
; WILLIAM KELLEY
; CS340 - ASSEMBLY LANGUAGE(RIMES)
; NUDE PLAYS PROFIT PROGRAM W/ OUTPUT

include Irvine32.inc

.386
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
CR				EQU		13
LF				EQU 	10
NULL			EQU 	0

negative		byte	'+'	;set default to positive

ticket			dword	275
patrons			dword	130
cost			dword	85

ten				dword	10
hundred			dword	100

topprofit		dword	0
topprice		dword	0
topdollar		dword	0
topcent			dword	0

profit_dollars		dword	?
profit_cents		dword	?
profit				dword	?

ticket_dollars	dword	?
ticket_cents	dword	?

output	byte	'PlayProfitOutput.txt', NULL
outfile	dword	?

head	byte	'           ', 'Nude Plays Profit Chart', CR, LF
header	byte	'Ticket Price', '      ', 'Patrons', '      '
		byte	'    ', 'Profits', CR, LF, NULL

ticket_message			byte	12 dup(?), '      '
patrons_message			byte	7 dup(?), '          '
profit_message			byte	7 dup(?), CR, LF, NULL
best_header				byte	'Best ticket price is $'
best_ticket_price		byte	4 dup(?), CR, LF, NULL

.code
main PROC
		mov edx, offset output
		call CreateOutputFile
		mov outfile, eax
		lea esi, head
		mov eax, outfile
		call _PRINT_TO_FILE

again:
		mov eax, ticket
		mov ebx, cost
		sub eax, ebx
		mov ebx, patrons
		imul eax, ebx
		mov profit, eax
		cmp eax, 0
		jg positive
		mov negative, '-'
		imul eax, -1

positive:
		mov edx, 0
		idiv hundred
		mov profit_dollars, eax
		mov profit_cents, edx
		lea esi, profit_message
		mov ecx, 7
		call _BLANKOUT
		cmp profit_cents, 0
		jne good
		dec esi
		mov al, '0'
		mov [esi], al

good:
		mov eax, profit_cents
		call _INT_TO_ASCII
		mov al, '.'
		dec esi
		mov [esi], al
		mov eax, profit_dollars
		call _INT_TO_ASCII
		dec esi
		mov al, '$'
		mov [esi], al
		cmp negative, '-'
		jne pos_result
		dec esi
		mov al, '-'
		mov [esi], al

pos_result:
		lea esi, ticket_message
		mov ecx, 12
		call _BLANKOUT
		mov edx, 0
		mov eax, ticket
		idiv hundred
		mov ticket_dollars, eax
		mov ticket_cents, edx
		cmp ticket_cents, 0
		jne keep_going
		dec esi
		mov al, '0'
		mov [esi], al

keep_going:
		mov eax, ticket_cents
		call _INT_TO_ASCII
		dec esi
		mov al, '.'
		mov [esi], al
		mov eax, ticket_dollars
		call _INT_TO_ASCII
		mov al, '$'
		dec esi
		mov [esi], al
		lea esi, patrons_message
		mov ecx, 7
		call _BLANKOUT
		mov eax, patrons
		call _INT_TO_ASCII
		lea esi, ticket_message
		mov eax, outfile
		call _PRINT_TO_FILE
		mov eax, profit
		mov ebx, topprofit
		cmp ebx, eax
		jg undesired
		mov topprofit, eax
		mov eax, ticket
		mov topprice, eax

undesired:
		sub ticket, 5
		add patrons, 16
		add cost, 3
		cmp ticket, 145
		jne again
		mov edx, 0
		mov eax, topprice
		idiv hundred
		mov topdollar, eax
		mov topcent, edx
		lea esi, best_ticket_price
		mov ecx, 4
		call _BLANKOUT
		mov eax, topcent
		call _INT_TO_ASCII
		dec esi
		mov al, '.'
		mov [esi], al
		mov eax, topdollar
		call _INT_TO_ASCII
		lea esi, best_header
		call _PRINT_TO_FILE

		invoke ExitProcess, 0
main endP

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
next_char:
		mov dl, [esi]
		cmp dl, NULL
		je done
		mov edx, esi
		mov ecx, 1
		mov eax, outfile
		call WriteToFile
		inc esi
		jmp next_char
done:
		ret
_PRINT_TO_FILE endP

_BLANKOUT PROC
mov edx, ' '
next:
		mov[esi], dl
		inc esi
		dec ecx
		cmp ecx, 0
		jne next
		ret
_BLANKOUT endP

end main