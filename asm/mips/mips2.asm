.data
	myCharacter:.byte 'm' # print a character

.text
	li $v0, 4  # load imediately
	la $a0, myCharacter # load address
	syscall