    global  mult
    section .text

;mult(float cant,float precio);
mult:
    
    mov rax ,rdi ;move param cant to rax
    mov rdx ,rsi ;move param percio to ecx

    mul rdx ;multiplicar cant y precio
    
    ret