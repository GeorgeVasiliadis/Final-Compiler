#Declarations
.data
$err_zero: .asciiz "Error: Tried to divide by zero."
$var_a: .word 0
$t_1: .word 1
$t_5: .word 5
$t_3: .word 3
$t_1111: .word 1111



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
move $t7, $t7
lw $t9, $t_1
move $t8, $t9

add $t7, $t7, $t8
move $t6, $t7

seq $t5, $t5, $t6
beqz $t5, $l_label
#Assign
lw $t9, $t_5
move $t8, $t9
move $t7, $t8
move $t6, $t7
sw $t6, $var_a



#Assign
lw $t9, $var_a
move $t8, $t9
move $t7, $t8
move $t7, $t7
lw $t9, $t_3
move $t8, $t9

add $t7, $t7, $t8
move $t6, $t7
sw $t6, $var_a



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



$l_label:
#Print
lw $t9, $t_1111
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