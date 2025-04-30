global ft_write

extern __errno_location

section .text

; rax fd, rdi str, rsi len
ft_write:
	mov rax, 1 ; Write syscall
	syscall ; Call write()
	cmp rax, 0 ; Compare rax with 0 and set Flags accordingly
	jl errno ; if (rax < 0) jump to exit
	ret

errno:
	neg rax
	mov rcx, rax
	call __errno_location ; Set errno
	mov [rax], rcx
	mov rax, -1 ; Set return value to -1
	ret
