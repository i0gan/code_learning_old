#include <iostream>
using namespace std;
void testSwitch() {
	int x, y, z;
	char c1;
	cin >> x >> c1 >> y; //c1

	//多路选择语句选着不同表达式计算语句
	switch(c1) {
		case '+': cout << x << " + " << y << " = " << x + y << endl;
		case '-': cout << x << " - " << y << " = " << x - y << endl;
		case '*': cout << x << " * " << y << " = " << x * y << endl;
		case '/': cout << x << " / " << y << " = " << x / y << endl;
		case '%': cout << x << " % " << y << " = " << x % y << endl;
		default:
				  cout << "error!" << endl;
	}

}
int main(void) {

	return 0;
}
