#This file is written by Yuan Liang
.text

main:
	li $sp 0x7ffffffc	

	li $v0 5
	syscall

	sw $v0 n

	lw $t0 n
	sw $t0 0($sp)#push argument
	sub $sp $sp 4
	jal count_digits

	add $sp $sp 4

	move $a0 $t0
	li   $v0  1
	syscall 

	li   $v0 10
	syscall

count_digits:
	sub $sp $sp 12
        sw  $ra 12($sp)
	sw  $fp 8($sp)	
	add $fp $sp 12

	li $t0 0
	sw $t0 4($sp) 

	lw $t0 4($fp)
	bgtz $t0 else
	li $t1 -1
	mul $t0 $t0 $t1
	sw  $t0 4($fp)
	
else: 

do:	lw  $t0 4($fp)
	div $t0 $t0 10
	sw  $t0 4($fp)

	lw  $t1 4($sp)
	add $t1 $t1 1
	sw  $t1 4($sp)


	bgtz $t0 do 

	lw  $t0 4($sp)
	
	lw  $ra 12($sp)
	lw  $fp 8($sp)
	add $sp $sp 12
	
	jr  $ra
	
.data
n:	.word 0 

