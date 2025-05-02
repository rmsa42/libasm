section .text
global ft_strcpy

; rdi dest, rsi src
ft_strcpy:
	mov rax, 0
.loop:
	movsx rdx, byte [rsi + rax] ; Mov src[0] to rcx reg
	cmp rdx, 0
	je .null_byte
	lea rcx, [rdi + rax] ; Load dest[0] address
	mov [rcx], dl ; Put src[0] in dest[0]
	inc rax
	jmp .loop
.null_byte:
	lea rcx, [rdi + rax]
	mov [rcx], dl
	jmp .return
.return:
	mov rax, rdi ; Return pointer to dest
	ret
