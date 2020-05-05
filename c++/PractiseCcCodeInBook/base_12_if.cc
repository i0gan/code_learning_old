#include <iostream>
using namespace std;

void testIf_1() {
	int x, y;	
	cout << "x = ";
	cin >> x;
	if(x <= 0) {
		y = 2 * x;	
		cout << "y = " << y << endl;
	}else {
		y = x * x;
		cout << "y = " << y << endl;
	}
}
void testIf_2() {
	int a, b, c;
	int smallest;
	cout << "a  b  c" << endl;
	cin >> a >> b >> c;
	if(a <= b) {
		if(a <= c)
			smallest = a;	
		else
			smallest = c;
	} else {
		if(b <= c)
			smallest = b;	
		else  
			smallest = c;
	}
	cout << "Smallest = " << smallest << endl;
}
void testIf_3() {
	int score;

	//从键盘上输入分数
	cout << "score = ";
	cin >> score;

	//用带else if的条件语句判断处理
	if(score < 0 || score > 100) {
		cout << "The score is out of range!" << endl;
	}else if(score >= 90)
		cout << "Your grade is a A." << endl;
	else if(score >= 80)
		cout << "Your grade is a B." << endl;
	else if(score >= 70)
		cout << "Your grade is a C." << endl;
	else if(score >= 60)
		cout << "Your grade is a D." << endl;
	else
		cout << "Your grade is a E." << endl;
}
void testIf_4() {
	int n;
	cout << "n = ";
	cin >> n;
	if(n >= 0 && n <= 100 && n % 2 == 0)
		cout << "n = " << n << endl;
	else
		cout << "The " << n << "is out of range!" << endl;
}
void testIf_5() {
	int a, b, Max;
	//输入数据
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	//找出较大值
	Max = a > b ? a : b;
	cout << "Max = " << Max << endl;
}
void testIf_6() {
	int a, b;
	//输入数据
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;

	//除法判断
	if(b != 0 && a % b == 0) {
		cout << b << " divides" << a << endl;
		cout << "a / b" << a / b << endl;
	}else {
		cout << b << "does not divide" << a << endl;
	}
}

int main(void) {

	return 0;
}
