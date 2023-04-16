    global  mult
    section .text

;double mult(double cant,double precio);
mult:

    push ebp ;Save old stack base pointer
    mov ebp , esp ; Set new stack base pointer

    fld	QWORD[ebp+8] ;push cant into FPU stack
    fld	QWORD[ebp+16] ;push precio into FPU stack
    fmulp ST1 ;multiply

    pop ebp ;Recover old stack base pointer
    ret