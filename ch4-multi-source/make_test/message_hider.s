	.file	"message_hider.c"
	.section	.rodata
.LC0:
	.string	"%s"
.LC1:
	.string	"------------line---------"
	.text
.globl main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	jmp	.L2
.L3:
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	encrypt
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	puts
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	encrypt
	movl	$.LC0, %eax
	leaq	-80(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	movl	$.LC1, %edi
	call	puts
.L2:
	movq	stdin(%rip), %rax
	movq	%rax, %rdx
	leaq	-80(%rbp), %rax
	movl	$80, %esi
	movq	%rax, %rdi
	call	fgets
	testq	%rax, %rax
	jne	.L3
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.6 20120305 (Red Hat 4.4.6-4)"
	.section	.note.GNU-stack,"",@progbits
