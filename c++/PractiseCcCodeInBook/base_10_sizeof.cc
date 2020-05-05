#include <iostream>
using namespace std;
void testSizeof() {
	//sizeof 计算个种类型的字节长度
	cout << "sizeof('$') " << sizeof('$') << endl;
	cout << "sizeof(1)" << sizeof(1) << endl;
	cout << "sizeof(1.5)" << sizeof(1.5) << endl; 
	cout << "sizeof(\"Good!\") = " << sizeof("Good!") << endl;

	//用sizeof计算各种类型变量的字节长度
	int i = 100;
	char c = 'A';
	float x = 3.1416;
	double p = 0.1;
	cout << "sizeof(i)" << sizeof(i) << endl;
	cout << "sizeof(c)" << sizeof(c) << endl;
	cout << "sizoef(x)" << sizeof(x) << endl;
	cout << "sizeof(p)" << sizeof(p) << endl;

	//用sizeof计算表达式的字节长度
	cout << "sizeof(x + .1732) = " << sizeof(x + 1.732) << endl;

	//用sizeof计算各种类型的字节长度
	cout << "sizeof(char) =" << sizeof(char) << endl;
	cout << "sizeof(shrot) =" << sizeof(short) << endl;
	cout << "sizeof(int) = " << sizeof(int) << endl;
	cout << "sizeof(float) =" << sizeof(float) << endl;
	cout << "sizeof(double) = " << sizeof(double) << endl;

	//用sizeof计算数组的字节长度
	char str[] = "This is a test";
	char a[10];
	double xy[10];

	cout << "sizoef(str) = " << sizeof(str) << endl;
	cout << "sizeof(a) =" << sizeof(a) << endl;
	cout << "sizeof(xy) = " << sizeof(xy) << endl;

	struct st {
		short num;	
		float math_grade;
		float Chinese_grade;
		float sum_grade;
	};

	st student1;
	cout << "sizeof(st) = " << sizeof(st) << endl;
	cout << "sizeof(student1) = " << sizeof(student1) << endl;

}
int main(void) {
	testSizeof();
	return 0 ;
}
