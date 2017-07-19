/**
 * Copyright 2017 Food Tiny Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

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
