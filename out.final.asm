#Declarations
.data
$t_2: .word 2
$t_4: .word 4
$t_3.3: .float 3.300000



#Actual Instructions
.text
#Print
li $v0, 1
lw $a0, $t_2
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
li $v0, 1
lw $a0, $t_4
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
li $v0, 2
l.s $f12, $t_3.3
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Print
li $v0, 1
lw $a0, $t_2
syscall



#Print newline
li $v0, 11
li $a0, 10
syscall



#Exit
li $v0, 10
syscall