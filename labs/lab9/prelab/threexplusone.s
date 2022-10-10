; Hanzhang zhao hz9xs
; 11.11
; threexplusone.s
;
;
; Parameter 1 (in rdi) is the number x that we want to calculate
; Return value is the number of steps we need to converge x to 1
;
; optimizations
; 1. I use 'lea' to triple the value of rdi
; 2. I use bit shift instead of division
; 3. I do not use any push and pop
; 4. My program only contains 3 registers
;
	global _threexplusone

	section .text

_threexplusone:
    xor rcx, rcx     ; zero out a temp variable to store value of rdi
	xor	rax, rax	 ; zero out the return register
    xor r10, r10     ; zero out the counter i
start:
	cmp	rdi, 1	     ; does rdi == 1?
	je	done		 ; if so, we are done with calculation
    mov rcx, rdi     ; move the value of rdi to rcx
	and rcx, 1       ; if rdi is even, return 0. if rdi is odd, return 1
    jz  even         ; if even, jump to even loop. if odd, go to next line
odd:
    lea rdi, [rdi*3 + 1]    ; rdi = rdi * 3
    call _threexplusone     ; call recursion
    inc r10                 ; for each recursion, counter increases by 1
    jmp done                ; jump to return
even:
    shr rdi, 1              ; rdi = rdi / 2
    call _threexplusone     ; call recursion
    inc r10                 ; for each recursion, counter increases by 1
done:
    mov rax, r10     ; return the value of counter
	ret
