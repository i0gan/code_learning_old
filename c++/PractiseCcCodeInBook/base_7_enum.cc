#include <iostream>
using namespace std;

void testEnum() {
	enum color { red = 3, yellow = 6, blue = red + 4 };
	enum class color2 { red = 2, yellow, blue};
	
	//声明枚举变量a 和 b,并为枚举变量a赋值
	enum color a = red;
	color2 b = color2::red;

	cout << "RED" << red << endl;
	cout << "YELLOW" << yellow << endl;
	cout << "BLUE" << blue << endl;

	//枚举变量的赋值和输出
	b = static_cast<color2>(a);
	a = blue;
	cout << "a = " << a << endl;
	cout << "b = " << int(b) << endl;
	// a = 100; 错误
	// a = 6; 也错误

	//枚举变量关系运算
	b = color2::blue;
	cout << "a < b : " << (int(a) < int(b)) << endl;
}

int main(void) {
	
	testEnum();
	return 0;
}
