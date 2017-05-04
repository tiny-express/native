#  char *string_concat(char *target, char *subtarget)
# Optimized algorithms for string_concat() with greater speed
# Reference from https://java.net/projects/solaris/sources/on-src/content/usr/src/lib/libc/amd64/gen/strcat.s
.section .text
    .global string_concat_asm
string_concat_asm:
    movq	%rdi,%rax
    movabsq	$0x7f7f7f7f7f7f7f7f, %r8
    movq	%r8, %r9
    notq	%r9
    testq	$7, %rdi
    jnz	.L1
    .align	4
.L2:
    movq	(%rdi), %rdx
    movq	%r8, %rcx
    andq	%rdx, %rcx
    addq	$8, %rdi
    addq	%r8, %rcx
    orq	%rdx, %rcx
    andq	%r9, %rcx
    cmpq	%r9, %rcx
    je	.L2
    subq	$8, %rdi
.L1:
    cmpb	$0, (%rdi)
    je	.L3
    incq	%rdi
    testq	$7, %rdi
    jnz	.L1
    jmp	.L2
    .align	4
.L3:
    testq	$7, %rsi
    jnz	.L4
    .align	4
.L5:
    movq	(%rsi), %rdx
    movq	%r8, %rcx
    andq	%rdx, %rcx
    addq	$8, %rsi
    addq	%r8, %rcx
    orq	%rdx, %rcx
    andq	%r9, %rcx
    cmpq	%r9, %rcx
    jne	.L7
    movq	%rdx, (%rdi)
    addq	$8, %rdi
    jmp	.L5
.L7:
    subq	$8, %rsi
    .align	4
.L4:
    movb	(%rsi), %dl
    cmpb	$0, %dl
    movb	%dl, (%rdi)
    je	.L6
    incq	%rsi
    incq	%rdi
    testq	$7, %rsi
    jnz	.L4
    jmp	.L5
    .align	4
.L6:
    ret
