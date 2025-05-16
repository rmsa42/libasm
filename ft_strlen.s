section .text
global ft_strlen

; rdi str
ft_strlen:
	mov rax, 0 ; Init rax reg
	jmp .loop
.loop:
	cmp byte [rdi + rax], 0 ; (str != '\0')
	je .return ; (str == '\0') = true, return
	inc rax ; +1 to rax value
	jmp .loop ; Loop again
.return:
	ret
