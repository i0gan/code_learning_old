#include <iostream>
using namespace std;

void testCalc_1() {
	int x, y;
	//计算中使用顺序运算
	x = 50;
	y = (x = x - 5, x / 5);
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
}

void testCalc_2() {
	//测试表达式类型转换	
	int n = 100, m;
	double x = 3.791, y;
	cout << "n * x = " << n * x << endl;

	//赋值类型转换
	m = x;
	y = n;
	cout << "m = " << m << endl;
	cout << "y = " << y << endl;

	//强制类型转换
	cout << "int (x) = " << int(x) << endl;
	cout << "(int)x = " << (int)x << endl;
	cout << "int(1.732 + x) = " << int(1.732 + x) << endl;
	cout << "(int)(1.732 + x) = " << (int)(1.732 + x) << endl;
	cout << "double(100) = " << double(100) << endl;
}
void testCalc_3() {
	float a, b, s;
	cout << "a b" << endl;
	cin >> a >> b;
	s = a;
	if(a < b) s = b;	
	s = s * s;
	cout << "s = " << s;
}
int main(void) {
	testCalc_1();
	testCalc_2();
	return 0;
}
