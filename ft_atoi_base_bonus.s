section .text
global ft_atoi_base

; rdi str
get_base:
	push rbp
	mov rbp, rsp
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

; rdi str
verify_base:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov qword [rbp - 8], rdi
.loop:
	movsx rcx, byte [rdi]
	cmp rcx, 0
	je .return
	cmp rcx, '+' ; Verify '+' char
	je .error
	cmp rcx, '-' ; Verify '-' char
	je .error
	lea rdi, qword [rdi + 1]
	mov rsi, rcx ; Load char to rsi
	call find ; Verify duplicate char (rdi - base, rsi - char)
	cmp rax, 1
	je .error
	mov rdi, qword [rbp - 8]
	inc rdi
	mov qword [rbp - 8], rdi
	jmp .loop
.error:
	mov rax, 1
	mov rsp, rbp
	pop rbp
	ret
.return:
	mov rax, 0
	mov rsp, rbp
	pop rbp
	ret

; rdi str, rsi char
find:
	push rbp
	mov rbp, rsp
	sub rsp, 4
	mov dword [rbp - 4], 0
	mov rax, 0
.loop:
	movsx rcx, byte [rdi + rax]
	cmp rcx, 0
	je .return
	cmp cl, sil
	je .dup
	movsx rax, dword [rbp - 4]
	inc rax
	mov dword [rbp - 4], eax
	jmp .loop
.dup:
	mov rax, 1
	mov rsp, rbp
	pop rbp
	ret
.return:
	mov rax, 0
	mov rsp, rbp
	pop rbp
	ret

; rdi str, rsi base
verify_str:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov qword [rbp - 8], rdi
	mov qword [rbp - 16], rsi
.loop:
	movsx rcx, byte [rdi]
	cmp rcx, 0
	je .return
	mov rdi, qword [rbp - 16]
	mov rsi, rcx
	call find
	cmp rax, 0
	je .error
	mov rdi, qword [rbp - 8]
	inc rdi
	mov qword [rbp - 8], rdi
	jmp .loop
.error:
	mov rax, 1
	mov rsp, rbp
	pop rbp
	ret
.return:
	mov rax, 0
	mov rsp, rbp
	pop rbp
	ret

; rdi str
sign_count:
	push rbp
	mov rbp, rsp
	mov r10, 1
.loop:
	movsx rcx, byte [rdi]
	cmp rcx, 48
	jge .return
	cmp rcx, 45
	je .minus_sign
.loop2:
	inc rdi
	jmp .loop
.minus_sign:
	mov rax, -1
	mul r10
	mov r10, rax
	jmp .loop2
.return:
	mov rax, r10
	mov rsp, rbp
	pop rbp
	ret

; rdi str, rsi base
ft_atoi_base:
	push rbp
	mov rbp, rsp
	sub rsp, 32
	mov dword [rbp - 4], 0
	mov qword [rbp - 8], rdi
	mov qword [rbp - 16], rsi

	; Get the length of base
	mov rdi, rsi ; Move base to rdi
	call get_base
	cmp rax, 1 ; See if base exists or has 1 length
	jle .error
	mov dword [rbp - 24], eax

	; Verify Base
	call verify_base
	cmp rax, 1
	je .error

	mov rdi, qword [rbp - 8] ; Get the pointer to the original string
	mov rsi, qword [rbp - 16] ; Get the original pointer to base

	; Count the "+-"
	call sign_count
	mov dword [rbp - 20], eax ; Save the sign
	mov qword [rbp - 8], rdi ; Pointer to the start of the number

	; Verify str input
	call verify_str
	cmp rax, 1
	je .error

	mov rdi, qword [rbp - 8] ; Get the pointer to the string
	mov r10, 0

.loop_1:
	movsx rcx, byte [rdi + r10] ; Get character
	cmp rcx, 0
	je .return
	cmp rcx, 'A' ; If is an hexa characters
	jge .hexa
	cmp rcx, '0' ; If is a number
	jge .dec
.dec:
	sub rcx, '0'
	jmp .loop_2
.hexa:
	sub rcx, 'A'
	add rcx, 10
	jmp .loop_2
.loop_2:
	movsx rax, dword [rbp - 24] ; Load the multiplier in rax
	mul dword [rbp - 4] ; Multiply the rax reg (strlen ret) with the current number in the variable
	add rax, rcx ; Add the multiplication result and the number
	mov dword [rbp - 4], eax ; Store the result into the variable
	inc r10
	jmp .loop_1
.error:
	mov rax, 0
	mov rsp, rbp
	pop rbp
	ret
.return:
	mov eax, dword [rbp - 4]
	movsx r10, dword [rbp - 20]
	mul r10
	mov rsp, rbp
	pop rbp
	ret
