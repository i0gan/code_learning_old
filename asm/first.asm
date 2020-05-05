assume cs:code,ds:data
data segment
messege db 'Hello,Welcom to asm!',Odh,Oab,24b
data ends
code segment
start:
	mov ax,data
	mov ds,ax
	;
	mov ah,9
	int 21h
	mov ax,4c00h
	int 21h
code ends
	end start
