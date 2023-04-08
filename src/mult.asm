SECTION .TEXT
	GLOBAL _mult

;mult(float cant,float precio);
_mult:
    
    mov eax, [ebp+4] ;move cant to eax
    mov ecx, [ebp+8] ;move percio to ecx

    mul ecx ;multiplicar cant y precio

    leave
    ret