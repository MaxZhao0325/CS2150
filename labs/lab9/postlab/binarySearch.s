; Hanzhang Zhao
; CS 2150 Post-Lab 9
; 11.12
; binarySearch.s

	global binarySearch

	section .text


; Parameter 1 (rdi) is a pointer to the int array
; Parameter 2 (rsi) is the beginning of the array
; Parameter 3 (rdx) is the end of the array
; Parameter 4 (rcx) is the target
; Return type is int
binarySearch:
    xor rax, rax    ; zero out the mid index
start:
    cmp rsi, rdx    ; if beginning > end, jump to not found
    jg  nofound
    mov rax, rsi    ; rax = rsi
    add rax, rdx    ; rax = rsi + rdx
    shr rax, 1      ; rax = (rsi + rdx) / 2 = mid
    cmp ecx, [rdi + 4 * rax]    ; compare the value of mid to target
    je  done        ; if equal, we are done searching
    jl  firsthalf   ; if key < [mid], jump to smaller part
    jg  secondhalf  ; if key > [mid], jump to larger part
nofound:
    mov rax, -1     ; if not found, return -1
    jmp done
firsthalf:
    dec rax
    mov rdx, rax    ; end = mid - 1
    call binarySearch
    jmp done
secondhalf:
    inc rax
    mov rsi, rax    ; beginning = mid + 1
    call binarySearch
done:
    ret             ; return the index if found
