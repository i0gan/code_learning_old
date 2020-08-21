#include <iostream>

int main(void) {
	int a = 0xFF;
	int b = a << 33;
	std::cout << "b is: " << b << std::endl;
	return 0;
}
