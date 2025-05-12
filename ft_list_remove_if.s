section .text
global ft_list_remove_if

; rdi **list, rsi void*, rdx cmpf, rcx freef
ft_list_remove_if:
	push rbp
	mov rbp, rsp
	sub rsp, 32
	mov r10, [rdi]
	mov qword [rbp - 8], r10
	mov qword [rbp - 16], rsi
	mov qword [rbp - 24], rdx
	mov qword [rbp - 32], rcx
.loop:
	cmp r10, 0
	je .ret
	mov rdi, qword [r10]
	mov rsi, qword [rbp - 16]
	mov rdx, qword [rbp - 24]
	call rdx
	mov r10, qword [rbp - 8]
	cmp rax, 0
	je .call_free
	jmp .loop2
.call_free:
	mov rdi, qword [r10]
	mov rcx, qword [rbp - 32]
	call rcx
.loop2:
	mov r10, qword [rbp - 8]
	mov r10, qword [r10 + 8]
	mov qword [rbp - 8], r10
	jmp .loop
.ret:
	mov rsp, rbp
	pop rbp
	ret

