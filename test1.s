	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.section	__TEXT,__literal4,4byte_literals
	.align	2
LCPI0_0:
	.long	1065437102              ## float 1.00999999
	.section	__TEXT,__text,regular,pure_instructions
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
	subq	$64, %rsp
	movss	LCPI0_0(%rip), %xmm0
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -36(%rbp)
	movl	$10, -40(%rbp)
	movl	$20, -44(%rbp)
	movq	l_main.z(%rip), %rax
	movq	%rax, -32(%rbp)
	movq	l_main.z+8(%rip), %rax
	movq	%rax, -24(%rbp)
	movq	l_main.z+16(%rip), %rax
	movq	%rax, -16(%rbp)
	movss	%xmm0, -48(%rbp)
	movl	-40(%rbp), %ecx
	subl	-44(%rbp), %ecx
	cmpl	$0, %ecx
	je	LBB0_2
## BB#1:
	jmp	LBB0_3
LBB0_2:
	jmp	LBB0_3
LBB0_3:
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movl	-36(%rbp), %ecx
	movq	(%rax), %rax
	cmpq	-8(%rbp), %rax
	movl	%ecx, -52(%rbp)         ## 4-byte Spill
	jne	LBB0_5
## BB#4:                                ## %SP_return
	movl	-52(%rbp), %eax         ## 4-byte Reload
	addq	$64, %rsp
	popq	%rbp
	retq
LBB0_5:                                 ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	.cfi_endproc

	.section	__TEXT,__const
	.align	4                       ## @main.z
l_main.z:
	.long	1                       ## 0x1
	.long	2                       ## 0x2
	.long	3                       ## 0x3
	.long	4                       ## 0x4
	.long	5                       ## 0x5
	.long	6                       ## 0x6

	.comm	_var,8,3                ## @var

.subsections_via_symbols
