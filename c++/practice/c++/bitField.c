#include <stdio.h>
typedef struct bs {
	int a:2;
	int b:1;
	int c:12;	
	unsigned d:4

}bs;
struct bit_2 {
	unsigned a:2;
	unsigned :2;  //It can't use
	unsigned :0;  //NULL

	unsigned b:4;
	unsigned c:4;
	
};
int main(void) {
	bs bit;
	printf("sizeof(%d) \n",sizeof(struct bs));
	bit.a = 4;
	bit.b = 1;
	bit.c = 34235;
	printf("a: %d   b: %d  c: %d\n", bit.a, bit.b, bit.c);

	return 0;
}
