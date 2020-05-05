#include <iostream>
using namespace std;

void testIncAndDec() {	
	char c;
	double x,y;

	cout << "++E and E++" << endl;
	c = 'B';
	cout << "c: =" << c << endl;
	cout << "++c = " << ++c << endl;
	c = 'B';
	cout << "c: =" << c << endl;
	cout << "c++ = " << c++ << endl;
	
	x = 1.5;
	y = 5+ ++x; //加号后空格不能少
	cout << "y = " << y << endl;
	x = 1.5;
	y = 5 + x++;
	cout << "y = " << y << endl;
	cout << "------------" << endl;

	//测试自减
	cout << "--E and E--:" << endl;
	c = 'B';
	cout << "c: =" << c << endl;
	cout << "--c = " << --c << endl;
	c = 'B';
	cout << "c: =" << c << endl;
	cout << "c-- = " << c-- << endl;

	x = 1.5;
	y = 5+ --x; //加号后空格不能少
	cout << "y = " << y << endl;
	x = 1.5;
	x = 5 + x--;
	cout << "y = " << y << endl;
	cout << "------------" << endl;

}
void testBoolFormulate() {
	int a = 3, b = 2;
	//输出关系表达式
	cout << (a < b) << endl;
	cout << (a < b) << (a > b) << (a == b) << (a != b) << endl;

	bool flag = 2 * a < b + 10;
	cout << "flag = " << flag;
}
void testShiftOper() {
	float a = 3.5, b = 2.1, c = 0;
	cout << "a = " << " b = " << b << " c = " << c << endl;

	//逻辑与运算
	cout << "a && b" << (a && b) << endl;
	cout << "a && c" << (a && c) << endl;

	//逻辑或运算
	cout << "a || b" << (a || b) << endl;
	cout << "a || c" << (a || c) << endl;

	//非运算
	cout << "!a" << !a << endl;

	//关系运算和逻辑运算
	bool flag = a >= 0 && a <= 5;
	cout << "a => 0 && a <= 5 = " << flag << endl;

	//算数运算, 关系运算和逻辑运算
	cout << "a + 5 > 2 * b + 2 || a < b + 3 = " 
		<< (a + 5 > 2 * b + 2 || a < b + 3) << endl;
}
void testShiftOper2() {
	//按位与运算
	cout << "24 & 12 = " << (24 & 12) << endl;

	//按位异或运算
	cout << "24 ^ 12 = " << (24 ^ 12) << endl;

	//按位或运算
	cout << "24 | 12 = " << (24 | 12) << endl;

	//按位取反运算
	cout << "~24 = " << (~24) << endl;

	//左移位运算
	cout << "5 << 3 = " << (5 << 3) << endl;
	cout << "-5 << 3 = " << (-5 << 3) << endl;

	//右移位运算
	cout << "5 >> 3 = " << (5 >> 3) << endl;
	cout << "-5 >> 3 = " << (-5 >> 3) << endl;
}
int main(void) {
//	testIncAndDec();
//	testShiftOper();
//	testShiftOper2();
	return 0;
}
