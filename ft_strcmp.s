section .text
global ft_strcmp

; rdi str1, rsi str2
ft_strcmp:
	mov rax, 0 ; Init rax reg
.loop:
	movzx rax, byte [rdi] ; Move Pointed char to al (8 bits reg)
	cmp al, 0 ; Is the end of string, if yes return
	je .return
	cmp al, [rsi] ; Compare the two characters, if ne return
	jne .return
	inc rdi ; Increment the str pointer
	inc rsi
	jmp .loop ; Back to the loop
.return:
	movsx rcx, byte [rsi] ; Mov 8 bit value to 64 bit reg (extends the sign)
	sub rax, rcx
	; sub al, [rsi]
	; movsx rax, al
	ret
	
