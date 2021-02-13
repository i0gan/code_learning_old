; This is a very simple program
; Hello World Program
; Complie: nasm -f elf p1.asm
; Link   : ld -m elf_i386 p1.o -o p1

SECTION.data
	msg db "Hello World", 0Ah, 00h ; Crete a string, the 0Ah is a '\n' 

SECTION.text
global _start
_start:
	mov edx, 13 ; the length of string
	mov ecx,msg ; string address
	mov ebx,1   ; write this to standard io output
	mov eax,4   ; SYS_write
	int 80h     ; syscall
	mov ebx,0 ; return value
	mov eax,1 ; SYS_exit
	int 80h   ; syscall
