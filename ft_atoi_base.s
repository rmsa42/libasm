section .data

data: db "LOL: %d", 10, 0

section .text
global ft_atoi_base

extern strlen ; strlen(rdi - char *str)
extern printf ; printf("Str", )

print:
	push rbp
	mov rbp, rsp
	mov rdi, data
	mov rsi, rax
	call printf
	mov rsp, rbp
	pop rbp
	ret
	
; rdi str
get_base:
	push rbp
	mov rbp, rsp
	sub rsp, 4
	mov dword [rbp - 4], 0
	mov rax, 0
.loop:
	movsx rcx, byte [rdi + rax]
	cmp rcx, 0
	je .return
	inc rax
	jmp .loop
.return:
	mov rsp, rbp
	pop rbp
	ret

; rdi str, rsi base
ft_atoi_base:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov dword [rbp - 4], 0

	; Get the length of base
	push rdi ; This misaligns the stack. Calling other functions will result in sigsev
	mov rdi, rsi
	call get_base
	mov r11, rax
	pop rdi
	mov r10, 0

.loop:
	movsx rcx, byte [rdi + r10] ; Get character
	cmp rcx, 0
	je .return
	sub rcx, 48 ; add '0'
	push rax ; Save last rax value
	mov rax, r11 ; Load the multiplier in rax
	mul dword [rbp - 4] ; Multiply the rax reg (strlen ret) with the current number in the variable
	add eax, ecx ; Add the multiplication result and the number
	mov dword [rbp - 4], eax ; Store the result into the variable
	pop rax
	inc r10
	jmp .loop
.return:
	movsx rax, dword [rbp - 4]
	mov rsp, rbp
	pop rbp
	ret
