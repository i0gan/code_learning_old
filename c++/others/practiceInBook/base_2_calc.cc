#include <iostream>
using namespace std;

void plus() {
	double s1, s2, s3;
	s1 = 1.5;
	cout << "s1= " << s1 << endl;
	s2 = 2.5;
	cout << "s2= " << s2 << endl;
	s3 = 3.5;
	cout << "s3= " << s3 << endl;
	cout << "s1 + s2 + s3 = " << s1 + s2 + s3 << endl;
}
void calc() {
	double r = 1.0;
	cout << "r = " << r << endl;
	double l;
	l = 2 * 3.1416 * r;
	cout << "l = " << l << endl;
	double s = 3.1416 * r * r;
	cout << "s = " << s << endl;

	cout << "R = ";
	cin >> r;
	l = 2 * 3.1416 * r;
	cout << "l = " << l << endl;
	s = 3.1416 * r * r;
	cout << "s = " << s << endl;
}
int main(void) {
	calc();
	return 0;
}
