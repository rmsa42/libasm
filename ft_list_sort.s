section .text
global ft_list_sort

; rdi **list, rsi (int *)(func())
ft_list_sort:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov qword [rbp - 8], rsi
	mov rcx, [rdi]
.loop:
	cmp rcx, 0
	je .ret
	mov rdi, 1
	mov rsi, 12
	mov qword [rbp - 16], rcx
	call qword [rbp - 8]
	cmp rax, 0
	jg .swap
	jmp .loop2
.swap:
	; rdi - 100, rsi - 5
.loop2:
	mov rcx, qword [rbp - 16]
	mov rcx, qword [rcx + 8]
	jmp .loop
.ret:
	mov rsp, rbp
	pop rbp
	ret
