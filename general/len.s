# length_pointer_char(char *target)
.section .text
    .global length_pointer_char
length_pointer_char:
    push %rdi                       # First integer argument
    sub	%rcx, %rcx
    mov 0(%rsp), %rdi
    not %rcx
    sub %al, %al
    cld
repne scasb
	not	%rcx
	pop	%rdi
	lea	-1(%rcx), %rax
	ret
