# length_pointer_char(char *target)
# Optimized algorithms for length_pointer_char() with greater speed
# Reference from http://www.int80h.org/strlen/
.section .text
    .global length_pointer_char
length_pointer_char:
    push %rdi
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
