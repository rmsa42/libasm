section .text
global ft_list_sort

; rdi **list, rsi (int *)(func())
ft_list_sort:
	push rbp
	mov rbp, rsp
	sub rsp, 32
	mov qword [rbp - 8], rdi
	mov qword [rbp - 16], rsi
	mov rcx, [rdi]
.loop:
	cmp rcx, 0
	je .ret
	mov qword [rbp - 24], rcx ; Save List *
	mov rdi, qword [rcx] ; Load the void *
	mov rsi, qword [rcx + 8] ; Load next *
	cmp rsi, 0
	je .ret
	mov rsi, qword [rsi] ; Get void *
	call qword [rbp - 16] ; Call cmp function
	cmp eax, 0
	jg .swap
	jmp .loop2
.swap:
	mov rdi, qword [rbp - 24]
	mov rcx, qword [rdi] ; Load first void *
	mov rsi, qword [rdi + 8]
	mov rdx, qword [rsi] ; Load second void *
	mov qword [rsi], rcx
	mov qword [rdi], rdx
	mov rcx, qword [rbp - 8]
	mov rcx, [rcx]
	jmp .loop
.loop2:
	mov rcx, qword [rbp - 24]
	mov rcx, qword [rcx + 8]
	jmp .loop
.ret:
	mov rsp, rbp
	pop rbp
	ret
