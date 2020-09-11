#Declarations
.data
$err_zero: .asciiz "Error: Tried to divide by zero."
$var_a: .word 0
$var_b: .word 0
$var_c: .word 0
$t_5: .word 5



#Actual Instructions
.text


#Assign
#Assign
#Assign
lw $t9, $t_5
move $t8, $t9
move $t7, $t8
move $t6, $t7
sw $t6, $var_c



sw $t6, $var_b



sw $t6, $var_a



#Print
lw $t9, $var_a
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



#Print
lw $t9, $var_b
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



#Print
lw $t9, $var_c
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