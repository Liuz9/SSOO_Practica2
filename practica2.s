	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
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
	subq	$80, %rsp
	leaq	L_.str(%rip), %rdi
	movl	$2, %esi
	movl	$0, -4(%rbp)
	movb	$0, %al
	callq	_open
	movl	%eax, -8(%rbp)
	cmpl	$-1, -8(%rbp)
	je	LBB0_2
## BB#1:
	leaq	-32(%rbp), %rdi
	xorl	%eax, %eax
	movl	%eax, %esi
	callq	_gettimeofday
	movl	-8(%rbp), %edi
	movl	%eax, -52(%rbp)         ## 4-byte Spill
	callq	_revisanotas
	leaq	-48(%rbp), %rdi
	xorl	%ecx, %ecx
	movl	%ecx, %esi
	movl	%eax, -12(%rbp)
	callq	_gettimeofday
	leaq	L_.str.1(%rip), %rdi
	movl	-12(%rbp), %esi
	movl	%eax, -56(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	leaq	L_.str.2(%rip), %rdi
	movl	-40(%rbp), %ecx
	subl	-24(%rbp), %ecx
	movl	%ecx, %esi
	movl	%eax, -60(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movl	%eax, -64(%rbp)         ## 4-byte Spill
	jmp	LBB0_3
LBB0_2:
	leaq	L_.str.3(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -68(%rbp)         ## 4-byte Spill
LBB0_3:
	movl	-8(%rbp), %edi
	callq	_close
	xorl	%edi, %edi
	movl	%eax, -72(%rbp)         ## 4-byte Spill
	movl	%edi, %eax
	addq	$80, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"datos.bin"

L_.str.1:                               ## @.str.1
	.asciz	"Notas modificadas: %i\n"

L_.str.2:                               ## @.str.2
	.asciz	"Tiempo empleado: %ld us\n"

L_.str.3:                               ## @.str.3
	.asciz	"Error al abrir el archivo\n"


.subsections_via_symbols
