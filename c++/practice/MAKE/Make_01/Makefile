CC = gcc
CFLAGS = -Iinclude
TARGET = Hello

$(TARGET):lib/main.o lib/CC.o  lib/BB.o
	$(CC) -o Hello $<
main.o:%o:%c
	$(CC) -c -o lib/main.o $< $(CFLAGS)
BB.o:src/%o:%c
	$(CC) -c -o lib/BB.o $< $(CFLAGS)
CC.o:src/%o:%c
	$(CC) -c -o lib/CC.o src/CC.c  $(CFLAGS)
clear:
	rm -f Hello lib/main.o lib/BB.o lib/CC.o
