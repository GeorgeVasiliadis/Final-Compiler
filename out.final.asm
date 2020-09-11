#Declarations
.data
$err_zero: .asciiz "Error: Tried to divide by zero."
$t_10: .word 10
$t_4: .word 4
$t_8.0: .float 8.000000
$t_3: .word 3



#Actual Instructions
.text


#Print
lw $t9, $t_10
move $t8, $t9
move $t7, $t8
move $t7, $t7
lw $t9, $t_4
move $t8, $t9
move $t8, $t8
l.s $f9, $t_8.0
mtc1 $zero, $f18
c.eq.s $f9, $f18
bc1t err_zero

mtc1 $t8, $f8
cvt.s.w $f8, $f8
div.s $f8, $f8, $f9


mtc1 $t7, $f7
cvt.s.w $f7, $f7
add.s $f7, $f7, $f8

mov.s $f7, $f7
lw $t9, $t_3
move $t8, $t9
move $t8, $t8
lw $t9, $t_4

mul $t8, $t8, $t9

mtc1 $t8, $f8
cvt.s.w $f8, $f8
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