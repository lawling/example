#this file is written by Yuan Liang
.text

main:	li $v0 5
        syscall 

	sw $v0 m

	li $v0 5
	syscall

	sw $v0 n

	li $v0 5
	syscall

	sw $v0 mod_value

while:  lw $t0 m
	lw $t1 n 
	bgt $t0 $t1 endwhile
	
	lw $t0 mod_value
	lw $t1 m
        
	rem $t0 $t1 $t0
	bnez $t0 else

	lw $t0 count
	add $t0 $t0 1
	sw $t0 count

else:	lw $t0 m
	add $t0 $t0 1
	sw $t0 m

	b while
endwhile:

	li $v0 1
	lw $a0 count
	syscall

	li $v0 10
	syscall

.data
m: .word 0 
n: .word 0
mod_value: .word 0
count: .word 0


