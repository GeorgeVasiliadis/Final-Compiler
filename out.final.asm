#Declarations
.data
$err_zero: .asciiz "Error: Tried to divide by zero."
$var_a: .float 0.0
$t_10: .word 10
$t_0: .word 0
$t_1: .word 1



#Actual Instructions
.text


#Assign
lw $t9, $t_10
move $t8, $t9
move $t7, $t8
move $t6, $t7
mtc1 $t6, $f6
cvt.s.w $f6, $f6
s.s $f6, $var_a



$l_0:
l.s $f9, $var_a
mov.s $f8, $f9
mov.s $f7, $f8
mov.s $f6, $f7
mov.s $f5, $f6
lw $t9, $t_0
move $t8, $t9
move $t7, $t8
move $t6, $t7

mtc1 $t6, $f6
cvt.s.w $f6, $f6
c.lt.s $f5, $f6
li $t5, 0
li $t0, 1
movf $t5, $t0

beqz $t5, $l_1
#Print
lw $t9, $t_1
move $t8, $t9
move $t8, $t8
l.s $f9, $var_a
mtc1 $zero, $f0
c.eq.s $f9, $f0
bc1t err_zero

mtc1 $t8, $f8
cvt.s.w $f8, $f8
div.s $f8, $f8, $f9

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
mov.s $f7, $f8
mov.s $f7, $f7
lw $t9, $t_1
move $t8, $t9

mtc1 $t8, $f8
cvt.s.w $f8, $f8
sub.s $f7, $f7, $f8

mov.s $f6, $f7
s.s $f6, $var_a



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