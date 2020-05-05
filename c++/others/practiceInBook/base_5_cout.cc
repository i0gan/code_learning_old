#include <iostream>
//#include <iomainp>
using namespace std;
void cout_ () {
	int a =  010, b = 10, c =0x10;

	//以十进制显示数据
	cout << "DEC:" << endl;
	cout << "a = " << a;
	cout << "b = " << b;
	cout << "c = " << c << endl;

	//以八进制显示数据
	cout << "OCT:" << endl;
	cout << oct;
	cout << "a = " << a;
	cout << "b = " << b;
	cout << "c = " << c << endl;

	//以十六进制显示数据
	cout << "HEX:";
	cout << hex;
	cout << "a = " << a;
	cout << "b = " << b;
	cout << "c = " << c << endl;
	
	//八,十和十六进制混合运算并输出
	cout << " a + b + c = ";
	cout << dec; //恢复为十进制
	cout << a + b + c <<endl;

	//测试,八,十和十六进制输入
	cout << "DEC: a = "; cin >> dec >> a;
	cout << "OCT: b = "; cin >> oct >> b;
	cout << "HEX: b = "; cin >> hex >> c;
	cout << "DEC: " << dec << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}
void cout_2() {
	float fx = 10.0, fy = 6.0;
	float fz = fx / fy;
	double dx = 10.0, dy = 6.0;
	double dz = dx / dy;
	cout << "fz = ";
	//cout << setprecision(20) << dz;  //设置输出的浮点类型精度为小数20位

	//float 型溢出
	float x = 3.5e14;
	cout << "x = " << x << endl;
	cout << "x * x = " << x * x << endl;
	cout << "x * x *x = " << x * x * x << endl;
}

int main(void) {
//	cout_();
	cout_2();
	return 0;
}
