#include <iostream>
#include <iomanip>

int main(void) {
	float num = 0.0f;	
	std::cin >> num;
	std::cout << std::setprecision(3);
	std::cout << std::setiosflags(std::ios::fixed) << num << std::endl;
	
	return 0;
}
