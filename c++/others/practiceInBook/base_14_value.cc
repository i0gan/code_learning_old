#include <iostream>
using namespace std;
void testValue() {
	int x = 1, y = 2;
	double w = x + y;
	{
		double x = 1.414, y = 1.732, z = 3.14;	
		cout << "inner: x = " << x << endl;
		cout << "inner: y = " << y << endl;
		cout << "inner: z = " << z << endl;
		cout << "outer: w = " << w << endl; //访问重名的局部变量
	}
	cout << "outer: x= " << x << endl;
	cout << "outer: y= " << y << endl;
	cout << "outer: w= " << w << endl;

	//cout << "inner: z" << z << endl;
	//访问全局变量
	cout << "::x" << ::x << endl;
}
int main(void) {
	return 0;
}
