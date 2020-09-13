#Declarations
.data
$err_zero: .asciiz "Error: Tried to divide by zero."
$var_first: .word 0
$t_0: .word 0
$var_second: .word 0
$t_1: .word 1
$var_i: .word 0
$t_10: .word 10
$var_tmp: .word 0



#Actual Instructions
.text


#Assign
lw $t9, $t_0
move $t8, $t9
move $t7, $t8
move $t6, $t7
sw $t6, $var_first



#Assign
lw $t9, $t_1
move $t8, $t9
move $t7, $t8
move $t6, $t7
sw $t6, $var_second



#Assign
lw $t9, $t_0
move $t8, $t9
move $t7, $t8
move $t6, $t7
sw $t6, $var_i



$l_0:
lw $t9, $var_i
move $t8, $t9
move $t7, $t8
move $t6, $t7
move $t5, $t6
lw $t9, $t_10
move $t8, $t9
move $t7, $t8
move $t6, $t7

slt $t5, $t5, $t6
beqz $t5, $l_1
#Assign
lw $t9, $var_i
move $t8, $t9
move $t7, $t8
move $t7, $t7
lw $t9, $t_1
move $t8, $t9

add $t7, $t7, $t8
move $t6, $t7
sw $t6, $var_i



#Assign
lw $t9, $var_first
move $t8, $t9
move $t7, $t8
move $t7, $t7
lw $t9, $var_second
move $t8, $t9

add $t7, $t7, $t8
move $t6, $t7
sw $t6, $var_tmp



#Print
lw $t9, $var_tmp
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



#Assign
lw $t9, $var_second
move $t8, $t9
move $t7, $t8
move $t6, $t7
sw $t6, $var_first



#Assign
lw $t9, $var_tmp
move $t8, $t9
move $t7, $t8
move $t6, $t7
sw $t6, $var_second



b $l_0
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