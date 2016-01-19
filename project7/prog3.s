#this file is written by Yuan Liang

.text

main:
	li $v0 5 #scanf
	syscall 
	sw $v0 n #assgin to n

	lw $t0 n 


beginwhile:
	beqz $t0 endwhile
	lw $t1 max         #t1 = max in while loop
	bge $t1 100 else
	mul $t1 $t1 4
	sw $t0 arr($t1) 
	div $t1 $t1 4
	add $t1 $t1 1
	sw  $t1 max
else:
	li $v0 5
	syscall
	sw  $v0 n
	lw  $t0 n
	b beginwhile
endwhile:

	li $v0 5
	syscall
	sw $v0 element

while_1:
	lw $t0 element
	beqz $t0 endwhile_1
	sw $0 idx
	
	lw  $t0  idx #idx = $t0 max = $t1
	lw  $t1   max

nest_while_1: #idx and arr[idx] should be updated 
	bge $t0 $t1  end_nest_while_1 #one branch

	lw  $t2 element
	
	mul $t0 $t0 4
	lw  $t3 arr($t0)
	div $t0 $t0 4

	beq $t3 $t2 end_nest_while_1 #other branch 

	add $t0 $t0 1
	sw  $t0 idx

	lw  $t0 idx
	
	b nest_while_1

end_nest_while_1:

	lw $t0 idx
	lw $t1 max

	bge $t0 $t1 else_1
	move $a0 $t0
	li $v0 1
	syscall

	b end_if

else_1: li $a0 -1
	li $v0 1
	syscall

end_if:
	la $a0 newline
	li $v0 4
	syscall

	li $v0 5
	syscall
	sw $v0 element
	b while_1
endwhile_1:

	li $v0 10
	syscall
.data
arr:.space 400
n: .word 0
max: .word 0
element: .word 0
idx:.word 0
pos:.word 0
newline: .asciiz "\n"
