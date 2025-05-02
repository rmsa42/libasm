section .text
global teste

; int teste() {
;	int a = 4;
;	return (a);
; }

teste:
	push rbp ; Save the value from previous function. This prepares the stack frame for this funtion (save frame pointer - sfp)
	mov rbp, rsp ; Put rbp in the top of the stack to init the stack frame
	sub rsp, 4 ; Create space for a 4 byte local variable

	mov dword [rbp - 4], 10 ; Put the value 10 in the variable
	movsx rax, dword [rbp - 4] ; Put the value from the local variable to the return reg

	mov rsp, rbp ; Clean all the local variables
	pop rbp ; Clean the sfp (push rbp)
	ret ; Return to the previous function
