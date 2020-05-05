cacu:add_int.o add_float.o sub_int.o sub_float.o main.o
	gcc -o cacu add/add_int.o add/add_float.o sub/sub_int.o sub/sub_float.o main.o
main.o:main.c add/add.h
	gcc -c -o main.o main.c -Iadd -Isub
add_int.o:add/add_int.c
	gcc -c -o add/add_int.o add/add_int.c
add_float.o:add/add_float.c
	gcc -c -o add/add_float.o add/add_float.c
sub_int.o:sub/sub_int.c sub/sub.h
	gcc -c -o sub/sub_int.o sub/sub_int.c
sub_float.o:sub/sub_float.c
	gcc -c -o sub/sub_float.o sub/sub_float.c
clean:
	rm -f cacu add/add_int.o add/add_float.o sub/sub_int.o sub/sub_float.o main.o
