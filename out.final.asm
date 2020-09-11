#Declarations
.data
$err_zero: .asciiz "Error: Tried to divide by zero."
$var_george: .word 0
$t_3: .word 3
$var_dimitra: .float 0.0
$t_0.33: .float 0.330000



#Actual Instructions
.text


#Assign
lw $t9, $t_3
move $t8, $t9
move $t7, $t8
sw $t7, $var_george



#Print
lw $t9, $var_george
move $t8, $t9
move $t8, $t8
l.s $f9, $var_dimitra
mtc1 $zero, $f18
c.eq.s $f9, $f18
bc1t err_zero

mtc1 $t8, $f8
cvt.s.w $f8, $f8
div.s $f8, $f8, $f9

mov.s $f7, $f8
mov.s $f7, $f7
l.s $f9, $t_0.33
mov.s $f8, $f9

add.s $f7, $f7, $f8

li $v0, 2
mov.s $f12, $f7
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