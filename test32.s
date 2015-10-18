	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	subl	$4096, %esp             ## imm = 0x1000
	calll	L0$pb
L0$pb:
	popl	%eax
	leal	L_.str-L0$pb(%eax), %ecx
	leal	-4012(%ebp), %edx
	movl	L___stack_chk_guard$non_lazy_ptr-L0$pb(%eax), %esi
	movl	(%esi), %esi
	movl	%esi, -12(%ebp)
	movl	$0, -4036(%ebp)
	movl	%ecx, (%esp)
	movl	%edx, 4(%esp)
	movl	%edx, 8(%esp)
	movl	%edx, 12(%esp)
	movl	%eax, -4052(%ebp)       ## 4-byte Spill
	calll	_printf
	movl	-4052(%ebp), %ecx       ## 4-byte Reload
	leal	L_.str1-L0$pb(%ecx), %edx
	movl	$4, %esi
	movl	%edx, (%esp)
	movl	$4, 4(%esp)
	movl	%eax, -4056(%ebp)       ## 4-byte Spill
	movl	%esi, -4060(%ebp)       ## 4-byte Spill
	calll	_printf
	movl	-4052(%ebp), %ecx       ## 4-byte Reload
	leal	L_.str2-L0$pb(%ecx), %edx
	movl	$8, %esi
	movl	%edx, (%esp)
	movl	$8, 4(%esp)
	movl	%eax, -4064(%ebp)       ## 4-byte Spill
	movl	%esi, -4068(%ebp)       ## 4-byte Spill
	calll	_printf
	movl	-4052(%ebp), %ecx       ## 4-byte Reload
	leal	L_.str3-L0$pb(%ecx), %edx
	leal	-4032(%ebp), %esi
	movl	%esi, %edi
	addl	$8, %edi
	movl	%edx, (%esp)
	movl	%esi, 4(%esp)
	movl	%edi, 8(%esp)
	movl	%eax, -4072(%ebp)       ## 4-byte Spill
	calll	_printf
	movl	-4052(%ebp), %ecx       ## 4-byte Reload
	movl	L___stack_chk_guard$non_lazy_ptr-L0$pb(%ecx), %edx
	movl	(%edx), %edx
	cmpl	-12(%ebp), %edx
	movl	%eax, -4076(%ebp)       ## 4-byte Spill
	jne	LBB0_2
## BB#1:                                ## %SP_return
	xorl	%eax, %eax
	addl	$4096, %esp             ## imm = 0x1000
	popl	%esi
	popl	%edi
	popl	%ebp
	retl
LBB0_2:                                 ## %CallStackCheckFailBlk
	calll	___stack_chk_fail

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%p\t%p\t%p\n"

L_.str1:                                ## @.str1
	.asciz	"size of float is %lu\n"

L_.str2:                                ## @.str2
	.asciz	"sizeof data is %lu\n"

L_.str3:                                ## @.str3
	.asciz	"index 0 address is %p index address 1 is %p"


	.section	__IMPORT,__pointers,non_lazy_symbol_pointers
L___stack_chk_guard$non_lazy_ptr:
	.indirect_symbol	___stack_chk_guard
	.long	0

.subsections_via_symbols
