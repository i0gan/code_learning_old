#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

void dummyMalloc(char *p) {
	p = (char*)malloc(8);
}
int main(void) {

	char str[] = "Hello World";
	dummyMalloc(str);
	strcpy(str, "Hi World\n");
	auto n = printf(str);
	printf("n: %d \n", n);

	return 0;
}
