section .text
global ft_strdup

extern malloc ; malloc(size * count)
extern __errno_location

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
	sub rsp, 8 ; Stack alignment
	add rax, 1 ; Null byte Char
	mov rdi, rax ; Malloc argument
	call malloc
	add rsp, 8 ; Stack alignment
	pop rdi ; Get str to rdi again
	cmp rax, 0
	je .error
	mov rbx, 0
	jmp .loop
.loop:
	movsx rcx, byte [rdi + rbx]
	cmp rcx, 0
	je .return
	mov [rax + rbx], cl
	inc rbx
	jmp .loop
.error:
	mov rcx, 12
	call __errno_location ; Set errno
	mov [rax], rcx
	mov rax, -1 ; Set return value to -1
	ret
.return:
	mov byte [rax + rbx], 0
	ret
