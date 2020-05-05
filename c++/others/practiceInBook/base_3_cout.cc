#include <iostream>
using namespace std;
void print() {
	//输出字符常量,变量和字符串
	char cl = 'A';
	cout << 'W';
	cout << cl << endl;	
	cout << "This is a test" << endl;

	//输出整型常量,变量和表达式
	int n = 100;
	cout << 10;
	cout << n;
	cout << 2 * n << endl;
	cout << "--------------" << endl;

	//输出浮点型常量,变量和表达式
	double pi = 3.1415926, r = 10.0, s = pi * r *r;
	cout << pi << endl;
	cout << r;
	cout << s;
	cout << 2 * r * pi << endl;
	cout << "--------------" << endl;

	//一个cout可以输出多项数据
	cout << "W" << "" << cl << endl;
	cout << "This is a test" << endl;
	cout << "pi = " << pi << "r = " << r << "s = " << s << endl;
}

int main(void) {

	print();
	return 0 ;
}
