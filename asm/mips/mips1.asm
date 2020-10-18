.data
	Message: .asciiz "Hello Wrold \n"

.text
	li $v0, 4
	la $a0, Message
	syscall