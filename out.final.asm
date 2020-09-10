#Declarations
.data
$t_2: .word 2
$t_3.5: .float 3.500000
$t_4.4: .float 4.400000



#Actual Instructions
.text
#Print
lw $t0, $t_2
li $v0, 1
move $a0, $t0
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
l.s $f0, $t_3.5
li $v0, 2
mov.s $f12, $f0
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
l.s $f0, $t_4.4
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