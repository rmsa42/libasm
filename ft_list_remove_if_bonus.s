section .text
global ft_list_remove_if

; rdi **list, rsi void*, rdx cmpf, rcx freef
ft_list_remove_if:
	push rbp
	mov rbp, rsp
	sub rsp, 48
	mov qword [rbp - 8], rdi ; Store &list in memory
	mov qword [rbp - 16], rsi ; Store void* to make cmp
	mov qword [rbp - 24], rdx ; Store the cmp func addr
	mov qword [rbp - 32], rcx ; Store the free func addr
	mov rax, [rdi]
	mov qword [rbp - 40], rax ; struct list *tmp = *list
	mov qword [rbp - 48], rax ; struct list *prev = *list

.loop:
	cmp rax, 0 ; while (tmp != NULL)
	je .ret

	mov r10, qword [rbp - 24] ; Load cmp func
	mov rdi, qword [rax] ; Load tmp->data
	mov rsi, qword [rbp - 16] ; Load data
	call r10 ; Call cmp(tmp->data, data)
	cmp eax, 0 ; if (cmp() == 0)
	je .equal

	mov rax, qword [rbp - 40] ; Load tmp
	mov qword [rbp - 48], rax ; Store prev value
	mov rax, qword [rax + 8] ; tmp = tmp->next
	mov qword [rbp - 40], rax ; Store new tmp
	jmp .loop
.equal:
	mov rax, qword [rbp - 40] ; Load tmp
	mov rdi, qword [rbp - 48] ; Load prev

	cmp rax, rdi ; if (tmp == prev)
	je .first_node
	mov rsi, qword [rax + 8] ; Load tmp->next
	mov qword [rdi + 8], rsi ; prev->next = tmp->next
	mov rdi, qword [rdi + 8] ; prev = prev->next
	mov qword [rbp - 40], rdi ; Store new prev
	jmp .call
.first_node:
	mov rcx, qword [rbp - 8] ; Load **list
	mov rsi, qword [rdi + 8] ; Load prev->next
	mov qword [rcx], rsi ; *list = prev->next
	mov qword [rbp - 40], rsi ; tmp = prev->next
	mov qword [rbp - 48], rsi ; prev = prev->next
.call:
	mov r10, qword [rbp - 32] ; Load free func
	mov rdi, rax ; Load tmp
	call r10 ; Call free(tmp)
	mov rax, qword [rbp - 40] ; Load tmp
	jmp .loop
.ret:
	mov rsp, rbp
	pop rbp
	ret
