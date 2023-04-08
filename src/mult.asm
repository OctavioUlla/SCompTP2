    global  mult
    section .text

;double mult(double cant,double precio);
mult:
    mulsd xmm0,xmm1
    
    ret