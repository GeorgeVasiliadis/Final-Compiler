#Declarations
.data
$err_zero: .asciiz "Error: Tried to divide by zero."
$t_3: .word 3
$t_5: .word 5
$t_111: .word 111
$t_5.0: .float 5.000000
$t_222: .word 222
$t_333: .word 333
$t_444: .word 444
$t_3.0: .float 3.000000
$t_55: .word 55
$t_666: .word 666
$t_777: .word 777
$t_888: .word 888
$t_1: .word 1
$t_2: .word 2
$t_4: .word 4



#Actual Instructions
.text


lw $t9, $t_3
move $t8, $t9
move $t7, $t8
move $t6, $t7
move $t5, $t6
lw $t9, $t_5
move $t8, $t9
move $t7, $t8
move $t6, $t7

sne $t5, $t5, $t6
beqz $t5, $l_0
#Print
lw $t9, $t_111
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



$l_0:
lw $t9, $t_3
move $t8, $t9
move $t7, $t8
move $t6, $t7
move $t5, $t6
l.s $f9, $t_5.0
mov.s $f8, $f9
mov.s $f7, $f8
mov.s $f6, $f7

mtc1 $t5, $f5
cvt.s.w $f5, $f5
c.eq.s $f5, $f6
li $t5, 0
li $t0, 1
movf $t5, $t0

beqz $t5, $l_1
#Print
lw $t9, $t_222
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



$l_1:
lw $t9, $t_5
move $t8, $t9
move $t7, $t8
move $t6, $t7
move $t5, $t6
lw $t9, $t_3
move $t8, $t9
move $t7, $t8
move $t6, $t7

sne $t5, $t5, $t6
beqz $t5, $l_2
#Print
lw $t9, $t_333
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



$l_2:
l.s $f9, $t_5.0
mov.s $f8, $f9
mov.s $f7, $f8
mov.s $f6, $f7
mov.s $f5, $f6
lw $t9, $t_3
move $t8, $t9
move $t7, $t8
move $t6, $t7

mtc1 $t6, $f6
cvt.s.w $f6, $f6
c.eq.s $f5, $f6
li $t5, 0
li $t0, 1
movf $t5, $t0

beqz $t5, $l_3
#Print
lw $t9, $t_444
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



$l_3:
l.s $f9, $t_3.0
mov.s $f8, $f9
mov.s $f7, $f8
mov.s $f6, $f7
mov.s $f5, $f6
l.s $f9, $t_5.0
mov.s $f8, $f9
mov.s $f7, $f8
mov.s $f6, $f7

c.eq.s $f5, $f6
li $t5, 0
li $t0, 1
movf $t5, $t0

beqz $t5, $l_4
#Print
lw $t9, $t_55
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



$l_4:
l.s $f9, $t_3.0
mov.s $f8, $f9
mov.s $f7, $f8
mov.s $f6, $f7
mov.s $f5, $f6
lw $t9, $t_5
move $t8, $t9
move $t7, $t8
move $t6, $t7

mtc1 $t6, $f6
cvt.s.w $f6, $f6
c.eq.s $f5, $f6
li $t5, 0
li $t0, 1
movf $t5, $t0

beqz $t5, $l_5
#Print
lw $t9, $t_666
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



$l_5:
l.s $f9, $t_5.0
mov.s $f8, $f9
mov.s $f7, $f8
mov.s $f6, $f7
mov.s $f5, $f6
l.s $f9, $t_3.0
mov.s $f8, $f9
mov.s $f7, $f8
mov.s $f6, $f7

c.eq.s $f5, $f6
li $t5, 0
li $t0, 1
movf $t5, $t0

beqz $t5, $l_6
#Print
lw $t9, $t_777
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



$l_6:
lw $t9, $t_5
move $t8, $t9
move $t7, $t8
move $t6, $t7
move $t5, $t6
l.s $f9, $t_3.0
mov.s $f8, $f9
mov.s $f7, $f8
mov.s $f6, $f7

mtc1 $t5, $f5
cvt.s.w $f5, $f5
c.eq.s $f5, $f6
li $t5, 0
li $t0, 1
movf $t5, $t0

beqz $t5, $l_7
#Print
lw $t9, $t_888
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



$l_7:
lw $t9, $t_5
move $t8, $t9
move $t7, $t8
move $t6, $t7
move $t5, $t6
lw $t9, $t_5
move $t8, $t9
move $t7, $t8
move $t6, $t7

sne $t5, $t5, $t6
beqz $t5, $l_8
#Print
lw $t9, $t_1
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



$l_8:
l.s $f9, $t_5.0
mov.s $f8, $f9
mov.s $f7, $f8
mov.s $f6, $f7
mov.s $f5, $f6
lw $t9, $t_5
move $t8, $t9
move $t7, $t8
move $t6, $t7

mtc1 $t6, $f6
cvt.s.w $f6, $f6
c.eq.s $f5, $f6
li $t5, 0
li $t0, 1
movf $t5, $t0

beqz $t5, $l_9
#Print
lw $t9, $t_2
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



$l_9:
lw $t9, $t_5
move $t8, $t9
move $t7, $t8
move $t6, $t7
move $t5, $t6
l.s $f9, $t_5.0
mov.s $f8, $f9
mov.s $f7, $f8
mov.s $f6, $f7

mtc1 $t5, $f5
cvt.s.w $f5, $f5
c.eq.s $f5, $f6
li $t5, 0
li $t0, 1
movf $t5, $t0

beqz $t5, $l_10
#Print
lw $t9, $t_3
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



$l_10:
l.s $f9, $t_5.0
mov.s $f8, $f9
mov.s $f7, $f8
mov.s $f6, $f7
mov.s $f5, $f6
l.s $f9, $t_5.0
mov.s $f8, $f9
mov.s $f7, $f8
mov.s $f6, $f7

c.eq.s $f5, $f6
li $t5, 0
li $t0, 1
movf $t5, $t0

beqz $t5, $l_11
#Print
lw $t9, $t_4
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



$l_11:



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