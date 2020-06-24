#include <iostream>
#include <cstdint>
/*
	功能: 判断一个数是否是2的幂数
	原理: 2的幂数在二进制中只有一个1, 那么只需判断是否只存在一个1即可
*/
bool is_power_of_two(uint64_t n) {
	// n != 0,        (n & -n) == n 判断是否只有一个 1
	return (n != 0) && ((n & -n) == n);
}

bool is_power_of_two_2(uint64_t n) {
	// __builtin_popcountll(n) 是一个用于计算二进制值的个数
	return __builtin_popcountll(n) == 1;
}

int main(void) {
	std::cout << is_power_of_two(8) << '\n';
	std::cout << is_power_of_two(10) << '\n';
	std::cout << is_power_of_two_2(8) << '\n';
	std::cout << is_power_of_two_2(9) << '\n';
	return 0;
}
