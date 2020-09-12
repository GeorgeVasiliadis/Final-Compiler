#Declarations
.data
$err_zero: .asciiz "Error: Tried to divide by zero."
$t_1: .word 1
$t_0: .word 0
$t_0.0: .float 0.000000
$t_1.0: .float 1.000000



#Actual Instructions
.text


#Print
lw $t9, $t_1
move $t8, $t9
move $t7, $t8
move $t7, $t7
lw $t9, $t_0
move $t8, $t9

add $t7, $t7, $t8
move $t6, $t7
li $v0, 1
move $a0, $t6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
lw $t9, $t_1
move $t8, $t9
move $t7, $t8
move $t7, $t7
l.s $f9, $t_0.0
mov.s $f8, $f9

mtc1 $t7, $f7
cvt.s.w $f7, $f7
add.s $f7, $f7, $f8

mov.s $f6, $f7
li $v0, 2
mov.s $f12, $f6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
l.s $f9, $t_1.0
mov.s $f8, $f9
mov.s $f7, $f8
mov.s $f7, $f7
lw $t9, $t_0
move $t8, $t9

mtc1 $t8, $f8
cvt.s.w $f8, $f8
add.s $f7, $f7, $f8

mov.s $f6, $f7
li $v0, 2
mov.s $f12, $f6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
l.s $f9, $t_1.0
mov.s $f8, $f9
mov.s $f7, $f8
mov.s $f7, $f7
l.s $f9, $t_0.0
mov.s $f8, $f9

add.s $f7, $f7, $f8

mov.s $f6, $f7
li $v0, 2
mov.s $f12, $f6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
lw $t9, $t_1
move $t8, $t9
move $t7, $t8
move $t7, $t7
lw $t9, $t_0
move $t8, $t9

sub $t7, $t7, $t8
move $t6, $t7
li $v0, 1
move $a0, $t6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
lw $t9, $t_1
move $t8, $t9
move $t7, $t8
move $t7, $t7
l.s $f9, $t_0.0
mov.s $f8, $f9

mtc1 $t7, $f7
cvt.s.w $f7, $f7
sub.s $f7, $f7, $f8

mov.s $f6, $f7
li $v0, 2
mov.s $f12, $f6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
l.s $f9, $t_1.0
mov.s $f8, $f9
mov.s $f7, $f8
mov.s $f7, $f7
lw $t9, $t_0
move $t8, $t9

mtc1 $t8, $f8
cvt.s.w $f8, $f8
sub.s $f7, $f7, $f8

mov.s $f6, $f7
li $v0, 2
mov.s $f12, $f6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
l.s $f9, $t_1.0
mov.s $f8, $f9
mov.s $f7, $f8
mov.s $f7, $f7
l.s $f9, $t_0.0
mov.s $f8, $f9

sub.s $f7, $f7, $f8

mov.s $f6, $f7
li $v0, 2
mov.s $f12, $f6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
lw $t9, $t_0
move $t8, $t9
move $t7, $t8
move $t7, $t7
lw $t9, $t_1
move $t8, $t9

sub $t7, $t7, $t8
move $t6, $t7
li $v0, 1
move $a0, $t6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
l.s $f9, $t_0.0
mov.s $f8, $f9
mov.s $f7, $f8
mov.s $f7, $f7
lw $t9, $t_1
move $t8, $t9

mtc1 $t8, $f8
cvt.s.w $f8, $f8
sub.s $f7, $f7, $f8

mov.s $f6, $f7
li $v0, 2
mov.s $f12, $f6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
lw $t9, $t_0
move $t8, $t9
move $t7, $t8
move $t7, $t7
l.s $f9, $t_1.0
mov.s $f8, $f9

mtc1 $t7, $f7
cvt.s.w $f7, $f7
sub.s $f7, $f7, $f8

mov.s $f6, $f7
li $v0, 2
mov.s $f12, $f6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
l.s $f9, $t_0.0
mov.s $f8, $f9
mov.s $f7, $f8
mov.s $f7, $f7
l.s $f9, $t_1.0
mov.s $f8, $f9

sub.s $f7, $f7, $f8

mov.s $f6, $f7
li $v0, 2
mov.s $f12, $f6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
lw $t9, $t_1
move $t8, $t9
move $t8, $t8
lw $t9, $t_1

mul $t8, $t8, $t9
move $t7, $t8
move $t6, $t7
li $v0, 1
move $a0, $t6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
lw $t9, $t_1
move $t8, $t9
move $t8, $t8
l.s $f9, $t_1.0

mtc1 $t8, $f8
cvt.s.w $f8, $f8
mul.s $f8, $f8, $f9

mov.s $f7, $f8
mov.s $f6, $f7
li $v0, 2
mov.s $f12, $f6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
l.s $f9, $t_1.0
mov.s $f8, $f9
mov.s $f8, $f8
lw $t9, $t_1

mtc1 $t9, $f9
cvt.s.w $f9, $f9
mul.s $f8, $f8, $f9

mov.s $f7, $f8
mov.s $f6, $f7
li $v0, 2
mov.s $f12, $f6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
l.s $f9, $t_1.0
mov.s $f8, $f9
mov.s $f8, $f8
l.s $f9, $t_1.0

mul.s $f8, $f8, $f9

mov.s $f7, $f8
mov.s $f6, $f7
li $v0, 2
mov.s $f12, $f6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
lw $t9, $t_1
neg $t9, $t9

move $t8, $t9
move $t8, $t8
lw $t9, $t_1

mul $t8, $t8, $t9
move $t7, $t8
move $t6, $t7
li $v0, 1
move $a0, $t6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
lw $t9, $t_1
neg $t9, $t9

move $t8, $t9
move $t8, $t8
l.s $f9, $t_1.0

mtc1 $t8, $f8
cvt.s.w $f8, $f8
mul.s $f8, $f8, $f9

mov.s $f7, $f8
mov.s $f6, $f7
li $v0, 2
mov.s $f12, $f6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
l.s $f9, $t_1.0
neg.s $f9, $f9

mov.s $f8, $f9
mov.s $f8, $f8
lw $t9, $t_1

mtc1 $t9, $f9
cvt.s.w $f9, $f9
mul.s $f8, $f8, $f9

mov.s $f7, $f8
mov.s $f6, $f7
li $v0, 2
mov.s $f12, $f6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
l.s $f9, $t_1.0
neg.s $f9, $f9

mov.s $f8, $f9
mov.s $f8, $f8
l.s $f9, $t_1.0

mul.s $f8, $f8, $f9

mov.s $f7, $f8
mov.s $f6, $f7
li $v0, 2
mov.s $f12, $f6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
lw $t9, $t_1
move $t8, $t9
move $t8, $t8
lw $t9, $t_1
neg $t9, $t9


mul $t8, $t8, $t9
move $t7, $t8
move $t6, $t7
li $v0, 1
move $a0, $t6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
lw $t9, $t_1
move $t8, $t9
move $t8, $t8
l.s $f9, $t_1.0
neg.s $f9, $f9


mtc1 $t8, $f8
cvt.s.w $f8, $f8
mul.s $f8, $f8, $f9

mov.s $f7, $f8
mov.s $f6, $f7
li $v0, 2
mov.s $f12, $f6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
l.s $f9, $t_1.0
mov.s $f8, $f9
mov.s $f8, $f8
lw $t9, $t_1
neg $t9, $t9


mtc1 $t9, $f9
cvt.s.w $f9, $f9
mul.s $f8, $f8, $f9

mov.s $f7, $f8
mov.s $f6, $f7
li $v0, 2
mov.s $f12, $f6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
l.s $f9, $t_1.0
mov.s $f8, $f9
mov.s $f8, $f8
l.s $f9, $t_1.0
neg.s $f9, $f9


mul.s $f8, $f8, $f9

mov.s $f7, $f8
mov.s $f6, $f7
li $v0, 2
mov.s $f12, $f6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
lw $t9, $t_1
move $t8, $t9
move $t8, $t8
lw $t9, $t_1
beqz $t9, err_zero

div $t8, $t8, $t9
move $t7, $t8
move $t6, $t7
li $v0, 1
move $a0, $t6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
lw $t9, $t_1
move $t8, $t9
move $t8, $t8
l.s $f9, $t_1.0
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



#Print
l.s $f9, $t_1.0
mov.s $f8, $f9
mov.s $f8, $f8
lw $t9, $t_1
beqz $t9, err_zero

mtc1 $t9, $f9
cvt.s.w $f9, $f9
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



#Print
l.s $f9, $t_1.0
mov.s $f8, $f9
mov.s $f8, $f8
l.s $f9, $t_1.0
mtc1 $zero, $f0
c.eq.s $f9, $f0
bc1t err_zero

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



#Print
lw $t9, $t_1
neg $t9, $t9

move $t8, $t9
move $t8, $t8
lw $t9, $t_1
beqz $t9, err_zero

div $t8, $t8, $t9
move $t7, $t8
move $t6, $t7
li $v0, 1
move $a0, $t6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
lw $t9, $t_1
neg $t9, $t9

move $t8, $t9
move $t8, $t8
l.s $f9, $t_1.0
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



#Print
l.s $f9, $t_1.0
neg.s $f9, $f9

mov.s $f8, $f9
mov.s $f8, $f8
lw $t9, $t_1
beqz $t9, err_zero

mtc1 $t9, $f9
cvt.s.w $f9, $f9
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



#Print
l.s $f9, $t_1.0
neg.s $f9, $f9

mov.s $f8, $f9
mov.s $f8, $f8
l.s $f9, $t_1.0
mtc1 $zero, $f0
c.eq.s $f9, $f0
bc1t err_zero

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



#Print
lw $t9, $t_1
move $t8, $t9
move $t8, $t8
lw $t9, $t_1
neg $t9, $t9

beqz $t9, err_zero

div $t8, $t8, $t9
move $t7, $t8
move $t6, $t7
li $v0, 1
move $a0, $t6
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
lw $t9, $t_1
move $t8, $t9
move $t8, $t8
l.s $f9, $t_1.0
neg.s $f9, $f9

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



#Print
l.s $f9, $t_1.0
mov.s $f8, $f9
mov.s $f8, $f8
lw $t9, $t_1
neg $t9, $t9

beqz $t9, err_zero

mtc1 $t9, $f9
cvt.s.w $f9, $f9
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



#Print
l.s $f9, $t_1.0
mov.s $f8, $f9
mov.s $f8, $f8
l.s $f9, $t_1.0
neg.s $f9, $f9

mtc1 $zero, $f0
c.eq.s $f9, $f0
bc1t err_zero

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