#Declarations
.data
$err_zero: .asciiz "Error: Tried to divide by zero."
$var_fizz: .word 0
$t_111111: .word 111111
$var_buzz: .word 0
$t_2: .word 2
$var_i: .word 0
$var_t1: .word 0
$var_t2: .word 0
$t_0: .word 0
$var_N: .word 0
$t_100: .word 100
$t_1: .word 1
$t_3: .word 3
$t_5: .word 5



#Actual Instructions
.text


#Assign
lw $t9, $t_111111
move $t8, $t9
move $t7, $t8
move $t6, $t7
sw $t6, $var_fizz



#Assign
lw $t9, $t_2
move $t8, $t9
move $t8, $t8
lw $t9, $var_fizz

mul $t8, $t8, $t9
move $t7, $t8
move $t6, $t7
sw $t6, $var_buzz



#Assign
#Assign
#Assign
lw $t9, $t_0
move $t8, $t9
move $t7, $t8
move $t6, $t7
sw $t6, $var_t2



sw $t6, $var_t1



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

slt $t5, $t5, $t6
beqz $t5, $l_1
lw $t9, $var_t1
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
lw $t9, $var_t2
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
lw $t9, $var_t1
move $t8, $t9
move $t7, $t8
move $t6, $t7
move $t5, $t6
lw $t9, $t_0
move $t8, $t9
move $t7, $t8
move $t6, $t7

seq $t5, $t5, $t6
beqz $t5, $l_4
b $l_5
$l_4:
lw $t9, $var_t2
move $t8, $t9
move $t7, $t8
move $t6, $t7
move $t5, $t6
lw $t9, $t_0
move $t8, $t9
move $t7, $t8
move $t6, $t7

seq $t5, $t5, $t6
beqz $t5, $l_6
b $l_7
$l_6:
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



$l_7:
$l_5:
#Assign
lw $t9, $var_t1
move $t8, $t9
move $t7, $t8
move $t7, $t7
lw $t9, $t_1
move $t8, $t9

add $t7, $t7, $t8
move $t6, $t7
sw $t6, $var_t1



#Assign
lw $t9, $var_t2
move $t8, $t9
move $t7, $t8
move $t7, $t7
lw $t9, $t_1
move $t8, $t9

add $t7, $t7, $t8
move $t6, $t7
sw $t6, $var_t2



lw $t9, $var_t1
move $t8, $t9
move $t7, $t8
move $t6, $t7
move $t5, $t6
lw $t9, $t_3
move $t8, $t9
move $t7, $t8
move $t6, $t7

seq $t5, $t5, $t6
beqz $t5, $l_8
#Assign
lw $t9, $t_0
move $t8, $t9
move $t7, $t8
move $t6, $t7
sw $t6, $var_t1



$l_8:
lw $t9, $var_t2
move $t8, $t9
move $t7, $t8
move $t6, $t7
move $t5, $t6
lw $t9, $t_5
move $t8, $t9
move $t7, $t8
move $t6, $t7

seq $t5, $t5, $t6
beqz $t5, $l_9
#Assign
lw $t9, $t_0
move $t8, $t9
move $t7, $t8
move $t6, $t7
sw $t6, $var_t2



$l_9:
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