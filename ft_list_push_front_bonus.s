section .text
global ft_list_push_front

extern malloc ; malloc(sizeof())
extern __errno_location

; struct list {
;	void *data -> 8 bytes
;	struct list *next -> 8 bytes
;} -> 16 bytes

; rdi data
create_node:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov qword [rbp - 8], rdi
	mov rdi, 16
	call malloc ; Alloc struct list *new_node
	cmp rax, 0
	je .error
	mov rdi, qword [rbp - 8] ; Restore the data value
	mov qword [rax], rdi ; Store the data (new_node->data = data)
	mov qword [rax + 8], 0 ; Make *next NULL (new_node->next = NULL)
	mov rsp, rbp
	pop rbp
	ret
.error:
	mov rax, 0
	mov rsp, rbp
	pop rbp
	ret

; rdi **list, rsi (void *)
ft_list_push_front:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov qword [rbp - 8], rdi ; Save the list
	mov rdi, rsi
	call create_node
	cmp rax, 0
	je errno
	mov rdi, qword [rbp - 8] ; Restore List *list
	mov rdx, [rdi] ; Dereference list (*list)
	mov qword [rax + 8], rdx ; new_node->next = *list
	mov qword [rdi], rax ; Make list ptr point to new_node (*list = new_node)
	mov rsp, rbp
	pop rbp
	ret

errno:
	mov rcx, 12
	call __errno_location ; Set errno
	mov [rax], rcx
	mov rax, -1 ; Set return value to -1
	mov rsp, rbp
	pop rbp
	ret
