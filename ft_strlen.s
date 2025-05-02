global ft_strlen

section .text

; rsi str
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

;_start:
;	mov rsi, msg
;	call ft_strlen
;	push rax
;	mov rax, 60 ; exit() syscall
;	mov rsi, 1 ; status code
;	syscall

;section .data
;	
;	msg: db "Hello"
