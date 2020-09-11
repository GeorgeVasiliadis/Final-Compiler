#Declarations
.data
$t_2: .word 2
$t_1: .word 1
$t_1.5: .float 1.500000
$t_2.5: .float 2.500000
$t_7.2: .float 7.200000
$t_4.2: .float 4.200000



#Actual Instructions
.text


#Print
lw $t0, $t_2
move $t1, $t0
lw $t0, $t_1
move $t0, $t0
sub $t0, $t1, $t0
li $v0, 1
move $a0, $t0
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
lw $t0, $t_2
move $t1, $t0
l.s $f0, $t_1.5
mov.s $f0, $f0

mtc1 $t1, $f1
cvt.s.w $f1, $f1
sub.s $f0, $f1, $f0

li $v0, 2
mov.s $f12, $f0
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
l.s $f0, $t_2.5
mov.s $f1, $f0
lw $t0, $t_1
move $t0, $t0
mtc1 $t0, $f0
cvt.s.w $f0, $f0
sub.s $f0, $f1, $f0

li $v0, 2
mov.s $f12, $f0
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
l.s $f0, $t_7.2
mov.s $f1, $f0
l.s $f0, $t_4.2
mov.s $f0, $f0

sub.s $f0, $f1, $f0

li $v0, 2
mov.s $f12, $f0
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
lw $t0, $t_1
move $t1, $t0
lw $t0, $t_2
move $t0, $t0
sub $t0, $t1, $t0
li $v0, 1
move $a0, $t0
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
l.s $f0, $t_1.5
mov.s $f1, $f0
lw $t0, $t_2
move $t0, $t0
mtc1 $t0, $f0
cvt.s.w $f0, $f0
sub.s $f0, $f1, $f0

li $v0, 2
mov.s $f12, $f0
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
lw $t0, $t_1
move $t1, $t0
l.s $f0, $t_2.5
mov.s $f0, $f0

mtc1 $t1, $f1
cvt.s.w $f1, $f1
sub.s $f0, $f1, $f0

li $v0, 2
mov.s $f12, $f0
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
l.s $f0, $t_4.2
mov.s $f1, $f0
l.s $f0, $t_7.2
mov.s $f0, $f0

sub.s $f0, $f1, $f0

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