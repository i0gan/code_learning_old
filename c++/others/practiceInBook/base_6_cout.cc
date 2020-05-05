#include <iostream>
using namespace std;

void cout_1() {
	char c1 = 'A';
	char c2;

	//字符数据的运算及输出
	c2 = c1 + 32;
	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;

	//输出字符及ASCII码
	cout << c1 << ":" << int(c1) << endl;
	cout << c2 << ":" << int(c2) << endl;
	cout << '$' << ":" << int('$') << endl;

	//输入字符
	cout << "c1 c2 " << endl;
	cin >> c1 >> c2;
	cout << "c1 = " << c1 << "  c2 = " << c2 << endl;
}

void cout_2() {

	char c1 = '\a', TAB = '\t';
	//震铃一声
	cout << "ok";
	cout << c1 << endl;
	
	//使用水平制表符
	cout << 1 << TAB << 2 << TAB << 3 << TAB << 4 << endl;

	//使用双引号
	cout << "He said:\"Thank you\"." << endl;
	cout << "abc\n" << "def" << "\n";
}
void boolCout() {
	bool flag1 = false, flag2 = true;
	
	//输出布尔常量和变量
	cout << "false: " << false << endl;
	cout << "true: " << true << endl;
	cout << "flag1: " << flag1 << endl;
	cout << "flag2: " << flag2 << endl;

	//布尔变量的赋值和输出
	int x = 1;
	flag1 = x > 0;
	cout << "flag1 = " << flag1 << endl;
	flag2 = flag1;
	cout << "flag2 = " << flag2 << endl;

	//布尔变量超界处理
	flag1 = 100;
	cout << "flag1 = " << flag1 << endl;
	flag2 = -100;
	cout << "flag2 = " << flag2 << endl;
}

int main(void) {

//	cout_2();
	boolCout();
	return 0;
}
