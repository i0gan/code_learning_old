#include <iostream>
template<typename  ...T>
void print_noa(T ...args) {
	std::cout << sizeof...(args) << std::endl;
}
void test_print_noa() {
	print_noa();
	print_noa(1);
	print_noa(1, 2, 3);
}

void print() {
	std::cout << std::endl;
}
template<typename T, typename ...Args>
void print(T head, Args ...args) {
	std::cout << head << " ";
	print(args...);
}


int main(void) {
	print("aaa", 1, 1.1f, 4, 1.6);
	return 0;
}
