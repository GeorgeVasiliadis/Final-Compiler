#Declarations
.data
$err_zero: .asciiz "Error: Tried to divide by zero."
$var_fizz: .word 0
$t_333: .word 333
$var_buzz: .word 0
$t_555: .word 555
$var_i: .word 0
$var_c3: .word 0
$var_c5: .word 0
$t_1: .word 1
$var_N: .word 0
$t_100: .word 100
$t_0: .word 0
$t_3: .word 3
$t_5: .word 5
#Actual Instructions
.text
#Assign
lw $t9, $t_333
move $t8, $t9
move $t7, $t8
move $t6, $t7
sw $t6, $var_fizz
#Assign
lw $t9, $t_555
move $t8, $t9
move $t7, $t8
move $t6, $t7
sw $t6, $var_buzz
#Assign
#Assign
#Assign
lw $t9, $t_1
move $t8, $t9
move $t7, $t8
move $t6, $t7
sw $t6, $var_c5
sw $t6, $var_c3
sw $t6, $var_i
#Assign
lw $t9, $t_100
move $t8, $t9
move $t7, $t8
move $t6, $t7
sw $t6, $var_N
$l_0:
lw $t9, $var_i
move $t8, $t9
move $t7, $t8
move $t6, $t7
move $t5, $t6
lw $t9, $var_N
move $t8, $t9
move $t7, $t8
move $t6, $t7
sle $t5, $t5, $t6
beqz $t5, $l_1
lw $t9, $var_c3
move $t8, $t9
move $t7, $t8
move $t6, $t7
move $t5, $t6
lw $t9, $t_0
move $t8, $t9
move $t7, $t8
move $t6, $t7
seq $t5, $t5, $t6
beqz $t5, $l_2
#Print
lw $t9, $var_fizz
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
$l_2:
lw $t9, $var_c5
move $t8, $t9
move $t7, $t8
move $t6, $t7
move $t5, $t6
lw $t9, $t_0
move $t8, $t9
move $t7, $t8
move $t6, $t7
seq $t5, $t5, $t6
beqz $t5, $l_3
#Print
lw $t9, $var_buzz
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
$l_3:
lw $t9, $var_c3
move $t8, $t9
move $t7, $t8
move $t6, $t7
move $t5, $t6
lw $t9, $t_0
move $t8, $t9
move $t7, $t8
move $t6, $t7
sne $t5, $t5, $t6
beqz $t5, $l_4
lw $t9, $var_c5
move $t8, $t9
move $t7, $t8
move $t6, $t7
move $t5, $t6
lw $t9, $t_0
move $t8, $t9
move $t7, $t8
move $t6, $t7
sne $t5, $t5, $t6
beqz $t5, $l_5
#Print
lw $t9, $var_i
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
$l_5:
$l_4:
#Assign
lw $t9, $var_c3
move $t8, $t9
move $t7, $t8
move $t7, $t7
lw $t9, $t_1
move $t8, $t9
add $t7, $t7, $t8
move $t6, $t7
sw $t6, $var_c3
#Assign
lw $t9, $var_c5
move $t8, $t9
move $t7, $t8
move $t7, $t7
lw $t9, $t_1
move $t8, $t9
add $t7, $t7, $t8
move $t6, $t7
sw $t6, $var_c5
lw $t9, $var_c3
move $t8, $t9
move $t7, $t8
move $t6, $t7
move $t5, $t6
lw $t9, $t_3
move $t8, $t9
move $t7, $t8
move $t6, $t7
seq $t5, $t5, $t6
beqz $t5, $l_6
#Assign
lw $t9, $t_0
move $t8, $t9
move $t7, $t8
move $t6, $t7
sw $t6, $var_c3
$l_6:
lw $t9, $var_c5
move $t8, $t9
move $t7, $t8
move $t6, $t7
move $t5, $t6
lw $t9, $t_5
move $t8, $t9
move $t7, $t8
move $t6, $t7
seq $t5, $t5, $t6
beqz $t5, $l_7
#Assign
lw $t9, $t_0
move $t8, $t9
move $t7, $t8
move $t6, $t7
sw $t6, $var_c5
$l_7:
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
