; mathlib.s
; Hanzhang zhao hz9xs 11.01
;
; Purpose : This file contains the implementation of the function
;           mathlib, which first product and then power two integers
;
; Parameter 1 (in rdi) is the first integer
; Parameter 2 (in rsi) is the second integer
; Return value are the product and the power of two input integers
;

	global _product

	section .text

_product:
	; Standard prologue: we do not have to create any local
	; variables (those values will be kept in registers), and 
	; we are not using any callee-saved registers.

	; Subroutine body:
	xor	rax, rax	 ; zero out the return register
	xor	r10, r10	 ; zero out the counter i
start:	
	cmp	r10, rsi	 ; does i == the second input integer?
	je	done		 ; if so, we are done with the loop
	add	rax, rdi ; add rdi to rax
	inc	r10		 ; increment our counter i
	jmp	start		 ; we are done with this loop iteration
done:	
    
	; Standard epilogue: the return value is already in rax, we
	; do not have any callee-saved registers to restore, and we do not
	; have any local variables to deallocate, so all we do is return
	ret


    global _power

    section .text
    
_power:

    xor     rax, rax     ; zero out the return register

    cmp     rsi, 0
    je      done3
    cmp     rsi, 1
    je      done4

    dec     rsi
    call    _power       ; we are done with this loop iteration
    mov     rsi, rax
    call    _product
done2:

    ; Standard epilogue: the return value is already in rax, we
    ; do not have any callee-saved registers to restore, and we do not
    ; have any local variables to deallocate, so all we do is return
    ret
done3:
    mov rax,1
    ret

done4:
    mov rax,rdi
    ret
