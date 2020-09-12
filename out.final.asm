#Declarations
.data
$err_zero: .asciiz "Error: Tried to divide by zero."
$var_a: .word 0



#Actual Instructions
.text


lw $t9, $var_a
move $t8, $t9
move $t7, $t8
move $t6, $t7
move $t5, $t6
lw $t9, $var_a
move $t8, $t9
move $t7, $t8
move $t6, $t7

seq $t5, $t5, $t6
beqz $t5, $l_0
$l_0:
$l_1:
li $t5, 0
beqz $t5, $l_2
#Print
lw $t9, $var_a
move $t8, $t9
move $t7, $t8
move $t6, $t7
li $v0, 1
move $a0, $t6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



b $l_1
$l_2:



b halt

#Print Zero-Division error
err_zero:
li $v0, 4
la $a0, $err_zero
syscall
b halt



#Halt
halt:
li $v0, 10
syscall