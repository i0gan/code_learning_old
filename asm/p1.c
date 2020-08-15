#include <stdio.h>
void asm_func_1() {
	int a = 2, b = 3;
	asm("add %1, %0" : "+r"(a) : "r"(b));
	printf("result: %d\n", a);
}
void asm_func_2() {


}

int main(void) {
	asm_func_1();
	return 0;
}
