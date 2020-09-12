#Declarations
.data
$err_zero: .asciiz "Error: Tried to divide by zero."
$var_a: .word 0
$var_b: .word 0
$t_5: .word 5
$var_c: .float 0.0
$var_d: .float 0.0
$t_1: .word 1
$t_2: .word 2
$t_3: .word 3
$t_4: .word 4



#Actual Instructions
.text


#Assign
#Assign
lw $t9, $t_5
move $t8, $t9
move $t7, $t8
move $t6, $t7
sw $t6, $var_b



sw $t6, $var_a



#Assign
#Assign
lw $t9, $t_5
move $t8, $t9
move $t7, $t8
move $t6, $t7
mtc1 $t6, $f6
cvt.s.w $f6, $f6
s.s $f6, $var_d



s.s $f6, $var_c



lw $t9, $var_a
move $t8, $t9
move $t7, $t8
move $t6, $t7
move $t5, $t6
lw $t9, $var_b
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



$l_0:
lw $t9, $var_b
move $t8, $t9
move $t7, $t8
move $t6, $t7
move $t5, $t6
l.s $f9, $var_c
mov.s $f8, $f9
mov.s $f7, $f8
mov.s $f6, $f7

mtc1 $t5, $f5
cvt.s.w $f5, $f5
c.eq.s $f5, $f6
li $t5, 1
movf $t5, $zero

beqz $t5, $l_1
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
l.s $f9, $var_c
mov.s $f8, $f9
mov.s $f7, $f8
mov.s $f6, $f7
mov.s $f5, $f6
l.s $f9, $var_d
mov.s $f8, $f9
mov.s $f7, $f8
mov.s $f6, $f7

c.eq.s $f5, $f6
li $t5, 1
movf $t5, $zero

beqz $t5, $l_2
#Print
lw $t9, $t_3
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
l.s $f9, $var_d
mov.s $f8, $f9
mov.s $f7, $f8
mov.s $f6, $f7
mov.s $f5, $f6
lw $t9, $var_a
move $t8, $t9
move $t7, $t8
move $t6, $t7

mtc1 $t6, $f6
cvt.s.w $f6, $f6
c.eq.s $f5, $f6
li $t5, 1
movf $t5, $zero

beqz $t5, $l_3
#Print
lw $t9, $t_4
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