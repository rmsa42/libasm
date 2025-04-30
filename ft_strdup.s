global ft_strdup

extern malloc ; malloc(size * count)

section .text

; rdi str
ft_strdup:
	mov rax, 0
.len:
	movsx rcx, byte [rdi + rax]
	cmp rcx, 0
	je .malloc
	inc rax
	jmp .len
.malloc:
	push rdi
	add rax, 1 ; Null byte Char
	mov rdi, rax ; Malloc argument
	call malloc
	pop rdi
	mov rbx, 0
	jmp .loop
.loop:
	movsx rcx, byte [rdi + rbx]
	cmp rcx, 0
	je .return
	mov [rax + rbx], cl
	inc rbx
	jmp .loop
.return:
	mov byte [rax + rbx], 0
	ret
