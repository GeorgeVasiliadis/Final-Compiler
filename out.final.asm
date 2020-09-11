#Declarations
.data
$t_5: .word 5
$t_3.5: .float 3.500000
$t_0.4: .float 0.400000



#Actual Instructions
.text


#Print
lw $t0, $t_5
move $t1, $t0
lw $t0, $t_5

add $t0, $t1, $t0
move $t1, $t0
lw $t0, $t_5

add $t0, $t1, $t0
move $t1, $t0
l.s $f0, $t_3.5

mtc1 $t1, $f1
cvt.s.w $f1, $f1
add.s $f0, $f1, $f0

mov.s $f1, $f0
l.s $f0, $t_0.4
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