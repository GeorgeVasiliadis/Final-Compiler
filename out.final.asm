#Declarations
.data
$err_zero: .asciiz "Error: Tried to divide by zero."
$t_1: .word 1
$t_2: .word 2



#Actual Instructions
.text


lw $t9, $t_1
move $t8, $t9
move $t7, $t8
move $t6, $t7
move $t5, $t6
lw $t9, $t_2
move $t8, $t9
move $t7, $t8
move $t6, $t7

seq $t5, $t5, $t6
beqz $t5, $l_0
#Print
lw $t9, $t_1
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
$l_0:
#Print
lw $t9, $t_2
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



$l_1:



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