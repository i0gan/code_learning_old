; This program also is Hello Wrold, but it is auto calc the length of string
; It will take strlen function to calc length of string

.data
	msg db 'Hello Wrold', 0ah, 00h ;	

.text
global _start
_start:
	mov ebx,msg ; move address of string in ebx register
	call strlen ;
	mov edx, eax ; length
	mov ecx, msg ; address of string
	mov ebx, 1   ; print to standard io output
	mov eax, 4   ; SYS_write
	int 80h      ; syscall
	mov ebx, 0   ; return value
	mov eax, 1   ; sys_exit
	int 80h      ; syscall
	
; calc length of string function
strlen:
	mov eax, 0
;A loop to get length of string
nextchar:
	cmp byte[ebx + eax], 0
	jz finished ; if eax equle to 0, then break
	inc eax ; eax increse 1
	jmp nextchar ; continue loop
finished:
	ret          ; return
