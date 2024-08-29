; X86.ASM
;
; This is a special version of SHELL.ASM that includes macros for the x86 GET and PUT
; instructions.  It allows you to write x86 style programs for the 80x86.
;
; There are a few caveats.  
;
; First, you cannot use the HALT, BRK, or IRET instructions.
; BRK does not exist, HALT and IRET do not work the same way as they do on the x86
; hypothetical processors.
;
; Second, the memory-mapped I/O devices are not present (no switches, no LEDs).
;
; Third, use operands of the form "DS:[xxxx]" for the direct addressing mode.
; Without the "DS:" prefix, the instruction will not work the same way as the
; x86 instruction.
;
; Fourth, unlike the x86, this program uses separate segments for the code and
; data.  You cannot do self-modifying code like you did on the x86 assignments.
;
; Fifth, MASM lets you use labels that are just like the x86 labels with one exception:
; "C" is a reserved word in MASM so you cannot create a program label named "C".  MASM
; returns some bizarre error if you do.
;
; Sixth, you can use the x86 registers and addressing modes as well as the 80x86
; registers and addressing modes (8086 only). 


		include 	stdlib.a
		includelib	stdlib.lib

sseg		segment	para stack 'stack'
stk		byte	128 dup ("stack   ")
sseg		ends

dseg		segment para public 'data'
ORG 0h
DataMemory	byte	65520 dup (?)

ORG 1000h
dw 128h, 127h, 126h, 125h, 124h, 123h, 122h, 121h, 120h, 119h, 118h, 117h, 116h, 115h, 114h, 113h, 112h, 111h, 110h, 109h, 108h, 107h, 106h, 105h, 104h, 103h, 102h, 101h, 100h, 99h, 98h, 97h, 96h, 95h, 94h, 93h, 92h, 91h, 90h, 89h, 88h, 87h, 86h, 85h, 84h, 83h, 82h, 81h, 80h, 79h, 78h, 77h, 76h, 75h, 74h, 73h, 72h, 71h, 70h, 69h, 68h, 67h, 66h, 65h, 64h, 63h, 62h, 61h, 60h, 59h, 58h, 57h, 56h, 55h, 54h, 53h, 52h, 51h, 50h, 49h, 48h, 47h, 46h, 45h, 44h, 43h, 42h, 41h, 40h, 39h, 38h, 37h, 36h, 35h, 34h, 33h, 32h, 31h, 30h, 29h, 28h, 27h, 26h, 25h, 24h, 23h, 22h, 21h, 20h, 19h, 18h, 17h, 16h, 15h, 14h, 13h, 12h, 11h, 10h, 9h, 8h, 7h, 6h, 5h, 4h, 3h, 2h, 1h 
dseg		ends


cseg		segment	para public 'code'
		assume	cs:cseg, ds:cseg


; The following assembly language procedure simulates the x86 GET instruction.

get		textequ	<call Gethex>
GetHex		proc	near
		push	es
		push	bx
		push	di

GHLoop:		print
		byte	"Enter a hexadecimal number:",0
		getsm
		mov	bx, di
TestHex:	mov	al, es:[bx]
		inc	bx
		cmp	al, 0
		je	GoodHex
		IsXDigit
		je	TestHex
		print
		byte	"Illegal hexadecimal value, re-enter",cr,lf,0
		jmp	GHLoop

GoodHex:	AtoH
		free
		pop	di
		pop	bx
		pop	es
		ret
GetHex		endp

	

; The following assembly language procedure simulates the x86 PUT instruction.

put		textequ	<call PutHex>
PutHex		proc	near
		putw
		putcr
		ret
PutHex		endp



; This is where the main program goes.

Main		proc
		mov	ax, dseg
		mov	ds, ax
		mov	es, ax
		meminit


;*****************************************************************************************
; Insertion sort for 128 values starting at DS:1000h 
;*****************************************************************************************

    xor bx, bx

o:
    mov cx, bx
    inc cx
    inc cx
    
i:  
    mov dx, ds:[1000h + bx]
    mov ax, ds:[1000h + cx]
    cmp dx, ax
    jle s
    mov ds:[1000h + bx], ax
    mov ds:[1000h + cx], dx

s:
    inc cx
    inc cx
    cmp cx, 200h
    jl  i

    inc bx
    inc bx
    cmp bx, 1FEh
    jl  o
    
    xor bx, bx
l:  mov ax, ds:[1000h + bx]
    put
    inc bx
    inc bx
    cmp bx, 100h
    jle l



;*****************************************************************************************


		ExitPgm
Main		endp

cseg		ends


zzzzzzseg	segment	para public 'zzzzzz'
LastBytes	byte	16 dup (?)
zzzzzzseg	ends
		end	Main
