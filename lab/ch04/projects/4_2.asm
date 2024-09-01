		include 	stdlib.a
		includelib	stdlib.lib

sseg		segment	para stack 'stack'
stk		byte	128 dup ("stack   ")
sseg		ends

dseg		segment para public 'data'
DataMemory	byte	65520 dup (?)
dseg		ends


cseg		segment	para public 'code'
		assume	cs:cseg, ds:cseg

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


put		textequ	<call PutHex>
PutHex		proc	near
		putw
		putcr
		ret
PutHex		endp


Main		proc
		mov	ax, dseg
		mov	ds, ax
		mov	es, ax
		meminit


;*****************************************************************************************
; Storing values to DS:3000h form 0 to 07FFh and summing the first 512 words
;*****************************************************************************************

    xor ax, ax
    xor bx, bx
l:
    mov ds:[3000h + bx], ax
    inc bx
    inc bx

    inc ax
    cmp ax, 800h
    jl  l

    mov dx, 3000h
    mov ds:[1000h], dx
    mov bx, ds:[1000h]

    xor si, si
    xor ax, ax

m:  mov dx, ds:[bx + si]
    add ax, dx
    inc si
    inc si
    cmp si, 402h
    jl  m
    
    put    

;*****************************************************************************************


		ExitPgm
Main		endp

cseg		ends


zzzzzzseg	segment	para public 'zzzzzz'
LastBytes	byte	16 dup (?)
zzzzzzseg	ends
		end	Main
