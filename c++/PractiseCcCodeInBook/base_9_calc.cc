#include <iostream>
using namespace std;

void calc_1 () {
	int a = 1, b = 1, c = 3;
	cout << "a = " << "b = " << "c = " << c << endl; 

	//计算显示(1) b+= a + 2 * c % 5的结构
	b += a + 2 * c % 5;
	cout << "(1) b = " << b << endl;

	//计算显示(2) a << c - 2 * b;的结果
	a = 1, b = 1, c = 3;
	a <<= c - 2 * b;
	cout << "(2) a = " << a << endl;

	//计算显示(3) a *= b = c = 3;的结果
	a = 1, b = 1, c = 3;
	a *= b = c = 3;
	cout << "(3) a = " << a << "  b = " << b << " c = " << c << endl;
	
	//计算显示(4) a += b+= c; 的结果
	a = 1, b = 1, c = 3;
	a += b += c;
	cout << "(4)a = " << a << "  b = " << b  << " c = " << c << endl;
	
	//计算显示(5) a -= b= ++c + 2的结果
	a = 1, b= 1, c = 3;
	a -= b = ++ c + 2;
	cout << "(5) a= "	 << a << " b =" << b << "  c=" << c << endl;
}
int main(void) {
	return 0;	
}
