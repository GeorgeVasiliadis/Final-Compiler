#Declarations
.data
$err_zero: .asciiz "Error: Tried to divide by zero."
$var_a: .word 0
$t_5: .word 5
$t_3: .word 3
$t_9: .word 9
$t_1.1: .float 1.100000
$t_2.2: .float 2.200000
$t_1111: .word 1111
$t_1: .word 1



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



lw $t9, $var_a
move $t8, $t9
move $t7, $t8
move $t6, $t7
move $t5, $t6
lw $t9, $t_9
move $t8, $t9
move $t7, $t8
move $t6, $t7

seq $t5, $t5, $t6
beqz $t5, $l_1
#Print
l.s $f9, $t_1.1
mov.s $f8, $f9
mov.s $f7, $f8
mov.s $f6, $f7
li $v0, 2
mov.s $f12, $f6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



$l_1:
#Print
l.s $f9, $t_2.2
mov.s $f8, $f9
mov.s $f7, $f8
mov.s $f6, $f7
li $v0, 2
mov.s $f12, $f6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



$l_0:
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



lw $t9, $t_1
move $t8, $t9
move $t7, $t8
move $t6, $t7
move $t5, $t6
lw $t9, $t_1
neg $t9, $t9

neg $t9, $t9

move $t8, $t9
move $t7, $t8
move $t6, $t7

seq $t5, $t5, $t6
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