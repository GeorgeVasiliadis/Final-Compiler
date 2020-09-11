#Declarations
.data
$t_5: .word 5
$t_3: .word 3
$t_5.0: .float 5.000000
$t_3.0: .float 3.000000



#Actual Instructions
.text


#Print
lw $t0, $t_5
move $t1, $t0
lw $t0, $t_3
move $t0, $t0
mul $t0, $t1, $t0
li $v0, 1
move $a0, $t0
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
l.s $f0, $t_5.0
mov.s $f1, $f0
lw $t0, $t_3
move $t0, $t0
mtc1 $t0, $f0
cvt.s.w $f0, $f0
mul.s $f0, $f1, $f0

li $v0, 2
mov.s $f12, $f0
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
lw $t0, $t_5
move $t1, $t0
l.s $f0, $t_3.0
mov.s $f0, $f0

mtc1 $t1, $f1
cvt.s.w $f1, $f1
mul.s $f0, $f1, $f0

li $v0, 2
mov.s $f12, $f0
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
l.s $f0, $t_5.0
mov.s $f1, $f0
l.s $f0, $t_3.0
mov.s $f0, $f0

mul.s $f0, $f1, $f0

li $v0, 2
mov.s $f12, $f0
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Exit
li $v0, 10
syscall