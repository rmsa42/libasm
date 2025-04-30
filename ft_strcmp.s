global ft_strcmp

section .text

; rdi str1, rsi str2
ft_strcmp:
	mov rax, 0 ; Init rax reg
.loop:
	mov al, [rdi] ; Move Pointed char to al (8 bits reg)
	mov cl, [rsi]
	cmp al, 0 ; Is the end of string, if yes return
	je .return
	cmp al, cl ; Compare the two characters, if ne return
	jne .return
	inc rdi ; Increment the str pointer
	inc rsi
	jmp .loop ; Back to the loop
.return:
	sub al, cl ; Get the return value
	ret
