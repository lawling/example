	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$4096, %rsp             ## imm = 0x1000
	leaq	L_.str(%rip), %rdi
	leaq	-4016(%rbp), %rax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -8(%rbp)
	movl	$0, -4052(%rbp)
	movq	%rax, %rsi
	movq	%rax, %rdx
	movq	%rax, %rcx
	movb	$0, %al
	callq	_printf
	leaq	L_.str1(%rip), %rdi
	movl	$4, %r8d
	movl	%r8d, %esi
	movl	%eax, -4076(%rbp)       ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str2(%rip), %rdi
	movl	$16, %r8d
	movl	%r8d, %esi
	movl	%eax, -4080(%rbp)       ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str3(%rip), %rdi
	leaq	-4048(%rbp), %rcx
	movq	%rcx, %rdx
	addq	$16, %rdx
	movq	%rcx, %rsi
	movl	%eax, -4084(%rbp)       ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	cmpq	-8(%rbp), %rcx
	movl	%eax, -4088(%rbp)       ## 4-byte Spill
	jne	LBB0_2
## BB#1:                                ## %SP_return
	xorl	%eax, %eax
	addq	$4096, %rsp             ## imm = 0x1000
	popq	%rbp
	retq
LBB0_2:                                 ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%p\t%p\t%p\n"

L_.str1:                                ## @.str1
	.asciz	"size of float is %lu\n"

L_.str2:                                ## @.str2
	.asciz	"sizeof data is %lu\n"

L_.str3:                                ## @.str3
	.asciz	"index 0 address is %p index address 1 is %p"


.subsections_via_symbols
