#include <stdio.h>

void byteorder() {
	union {
		short value;
		char union_bytes[sizeof(short)];
	} test;
	test.value = 0x0102;
	if((1 == test.union_bytes[0]) && (2 == test.union_bytes[1])) {
		printf("big endian\n");
	}else if((2 == test.union_bytes[0]) && (1 == test.union_bytes[1])) {
		printf("little endian\n");
	}else {
		printf("unknown\n");
	}
}

int main(void) {
	byteorder();
	return 0;
}
