section .text
global ft_read

extern __errno_location

; rdi fd, rsi buffer, rdx len
ft_read:
	mov rax, 0	
	syscall
	cmp rax, 0
	jl errno
	ret

errno:
	neg rax
	mov rcx, rax
	call __errno_location ; Set errno
	mov [rax], rcx
	mov rax, -1 ; Set return value to -1
	ret
