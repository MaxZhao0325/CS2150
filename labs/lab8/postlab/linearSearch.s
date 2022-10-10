; Hanzhang Zhao
; CS 2150 Post-Lab 8
; 11.02
; linearSearch.s

	global linearSearch

	section .text


; Parameter 1 is a pointer to the int array 
; Parameter 2 is the size of the array
; Parameter 3 is the target
; Return type is int
linearSearch:
    xor rax, rax
	xor r10, r10
loop:
    cmp r10, rsi
    je endNotFind
    cmp edx, [rdi + 4*r10]
    je  endFind
    inc r10
    jmp loop

endFind:
    mov rax, r10
    ret

endNotFind:
    mov rax, -1
    ret
