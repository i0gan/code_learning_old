
# this progrma will print a interger
.data
	age: .word  123

.text
	li $v0, 1 # load immediate
	lw $a0, age # load word
	syscall