#include <iostream>
using namespace std;

void cin_() {
	//输入输出字符
	char c;
	cin >> c;
	cout << "c = " << c << endl;
	
	//输入输出整型数据
	int n;
	cin >> n;
	cout << "n = " << n << endl;
	//输入输出浮点型数据
	double x;
	cin >> x;
	cout << "x = " << x << endl;
	//输入提示
	cout << "n = ";
	cin >> n;
	cout << "n = " << n << endl;

	//多项输入
	cout << "c n x: " << endl;
	cin >> c >> n >> x;
	cout << "c = " << c << "n = " << "x = " << x << endl;
}
void cin_2() {
	int a, b;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	//整型数的算数运算
	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;
	cout << a << " * " << b << " = " << a * b << endl;
	cout << a << " / " << b << " = " << a - b << endl;
	cout << a << " % " << b << " = " << a % b << endl;

	//测试溢出
	short n = 32767, m; //n取short类型的最大值
	cout << "n = " << n << endl;
	m = n + 1; //溢出
	cout << " n + 1 = " << m  << endl;
}
int main(void) {
	cin_2();
	return 0;
}
