org 0x7c00;

jmp entry
db  0x90
DB  "OSKERNEL"
DW  512
DB  1
DW  1
DB  2
DW  224
DW  2880
DB  0XF0
DW  9
DW  18
DW  2
DD  0
DD  2880
DB  0, 0, 0x29
DD  0xFFFFFFFF
DB  "MYFIRSTOS"
DB  "FAT12"
RESB 18

entry:
    mov ax, 0
    mov ss, ax
    mov ds, ax
    mov es, ax
    mov si, msg

readFlppy:
    mov DH, 0 ; DH用来储存磁头号
    mov CL, 1 ; CL用来储存柱面号
    mov CH, 2 ; CH用来储存扇区号

    mov BX, msg ;ES:BX数据储存缓冲区, 读取到msg
    mov AH, 0x02 ; AH = 02表示要做的是读盘操作
    mov AL, 0x02 ; AL 表示要连续读几个扇区
    mov DL, 0    ; 驱动编号, 一般只有一个的话就是0
    INT 0x13     ; 中断调用
    jc error

putloop:
    mov al, [si]
    add si, 1
    cmp al, 0
    je fin
    mov ah, 0x0e
    mov bx, 15
    int 0x10
    jmp putloop

fin:
    HLT
    jmp fin

error:
    mov si, errmsg ; 打印错误
    jmp putloop

msg:
    RESB 64 ; 开辟64字节内存储存消息

errmsg:
    DB "error"
