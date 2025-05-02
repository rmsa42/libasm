section .text
global ft_atoi_base

; rdi str, rsi base
ft_atoi_base:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov dword [rbp - 4], 0
	mov rax, 0
.loop:
	movsx rcx, byte [rdi + rax] ; Get character
	cmp rcx, 0
	je .return
	sub rcx, 48 ; add '0'
	push rax ; Save rax value
	mov rax, 10
	mul dword [rbp - 4]
	mov dword [rbp - 4], eax
	pop rax ; Restore rax value
	add dword [rbp - 4], ecx ; Put the character in the variable
	inc rax
	jmp .loop
.return:
	movsx rax, dword [rbp - 4]
	mov rsp, rbp
	pop rbp
	ret
