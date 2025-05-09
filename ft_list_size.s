section .text
global ft_list_size

; rdi *list
ft_list_size:
	push rbp
	mov rbp, rsp
	mov rax, 0
.loop:
	cmp rdi, 0
	je .ret
	mov rdi, qword [rdi + 8]
	inc rax
	jmp .loop
.ret:
	mov rsp, rbp
	pop rbp
	ret
