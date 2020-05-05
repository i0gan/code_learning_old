VPATH = .:add:sub:
CC = gcc
OBJS = add_int.o add_float.o sub_int.o sub_float.o main.o
OBJSDIR=objs
CFLAGS= -Isub -Iadd -O2
TARGET= cacu
RM = rm -f
$(TARGET):$(OBJS)
	$(CC) -o $(TARGET) $(OBJS) 
$(OBJS):%.o:%.c
	$(CC) -c $(CFLAGS) $^ -o $@
clean:
	$(RM) $(OBJS) $(TARGET)
