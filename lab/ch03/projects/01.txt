    get               ;gather inputs into bx and cx
    mov   bx, ax
    get
    mov   cx, ax

    cmp   bx, 0       ;check either input for zero
    je    z
    cmp   cx, 0
    je    z

    mov   ax, bx      ;check first input for neg value
    and   ax, 8000    ;since first value (bx) is used as a counter in iteration
    cmp   ax, 0       ;and iterative adding with a neg value still produces correct multiples due to 2's complement
    jne    a          ;we only care of the cases where either bx, or both bx and cx are neg

d:  mov   ax, 0       ;reset accumulator before starting calculations
p:  cmp   bx, 0       ;use bx as the iteration counter
    je    h
    add   ax, cx      ;add cx to ax over and over again bx many times
    sub   bx, 1
    jmp   p

a:  not   cx          ;if both bx and cx were neg, then just flip both, since result will be positive
    add   cx, 1       ;if bx neg but cx is not, the same piece of code would flip their signs 
    not   bx          ;now mathematically, it doesn't matter whether bx or cx is neg, as long as the parity
    add   bx, 1       ;of neg inputs is the same. However, since we use bx as a counter in the iteration process
    jmp   d           ;we'd rather cx be the neg value holder, rather than bx. Flipping both always works.

z:  mov   ax, 0       ;in case of a zero, just print 0 immediately
h:  put
    halt

