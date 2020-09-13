#Declarations
.data
$err_zero: .asciiz "Error: Tried to divide by zero."
$var_a: .float 0.0
$t_2: .word 2
$var_i: .word 0
$t_0: .word 0
$t_59: .word 59
$t_1: .word 1



#Actual Instructions
.text


#Assign
lw $t9, $t_2
move $t8, $t9
move $t7, $t8
move $t6, $t7
mtc1 $t6, $f6
cvt.s.w $f6, $f6
s.s $f6, $var_a



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
lw $t9, $t_59
move $t8, $t9
move $t7, $t8
move $t6, $t7

slt $t5, $t5, $t6
beqz $t5, $l_1
#Print
l.s $f9, $var_a
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



#Assign
l.s $f9, $var_a
mov.s $f8, $f9
mov.s $f8, $f8
lw $t9, $t_2
beqz $t9, err_zero

mtc1 $t9, $f9
cvt.s.w $f9, $f9
div.s $f8, $f8, $f9

mov.s $f7, $f8
mov.s $f6, $f7
s.s $f6, $var_a



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