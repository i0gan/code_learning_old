 

# 分离式编译

和C语言一样，汇编程序也是可以进行分离式编译的，你可以把自己的函数写到一个文件里，而另一的文件把它包含进去，然后就可以调用它。

## 头文件代码

```asm

;-------------------Hello World Program(include)--------------------
; 函数头文件
; by alongwy
;-------------------------------------------------------------------


;------------------------------------------
; int slen(String message)
; 计算字符串的长度
slen:
    push    ebx
    mov     ebx, eax

nextchar:
    cmp     byte [eax], 0
    jz      finished
    inc     eax
    jmp     nextchar

finished:
    sub     eax, ebx
    pop     ebx
    ret

;------------------------------------------
; void sprint(String message)
; 打印字符串
sprint:
    push    edx
    push    ecx
    push    ebx
    push    eax
    call    slen            ;调用slen计算字符串长度

    mov     edx, eax
    pop     eax

    mov     ecx, eax
    mov     ebx, 1
    mov     eax, 4
    int     80h

    pop     ebx
    pop     ecx
    pop     edx
    ret

;------------------------------------------
; void exit()
; 退出程序
quit:
    mov     ebx, 0
    mov     eax, 1
    int     80h
    ret
```

## 主文件

```assembly

;-------------------Hello World Program(include)--------------------
; by alongwy
; 编译： nasm -f elf helloworld-inc.asm
; 链接： ld -m elf_i386 helloworld-inc.o -o helloworld-inc
;        64位系统需要 elf_i386 选项
; 运行： ./helloworld-inc
;-------------------------------------------------------------------

%include    'functions.asm'              ; 包含头文件
SECTION .data                            ; 数据段
    msg1    db  'Hello World!', 0Ah, 0h  ; 创建字符串，0Ah是换行符
    msg2    db  'Hello NASM!', 0Ah, 0h   ; 后面添加了一个0
    
SECTION .text                            ; 代码段
global  _start

_start:
    mov     eax, msg1           ; 存入mag1的地址
    call    sprint              ; 调用sprint打印
    mov     eax, msg1
    call    sprint
    call    exit                ; 退出
```