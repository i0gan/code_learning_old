CC=g++
ASM=nasm
TARGET=os.img

GEN_MAKE_OS=make_os
GEN_BOOT=boot

$TARGET : $GEN_MAKE_OS $GEN_BOOT
	./make_os

$GEN_MAKE_OS : make_os.cc
	$(CC) $< -o $(GEN_MAKE_OS)

$GEN_BOOT : boot.asm
	$(ASM) boot.asm

clean:
	$(RM) $(GEN_MAKE_OS) $(GEN_BOOT) $(TARGET)
