#include <iostream>
using namespace std;

const float PI = 3.1416;
float fCir_L(float);
float fCir_S(float);

int main() {
	float r, l, s;

	cout << "R=";
	cin >> r;
	l = fCir_L(r);
	s = fCir_S(r);
	cout << "l = " << l;
	cout << "\ns= "<< s;
}

float fCir_L(float x) {
	float z = -1.0;
	if(x >= 0.0) {
		z = 2 * PI *x;	
		return z;
	}
	return 0.0;
}
float fCir_S(float x) {
	float z = -1.0;	
	if(x >= 0.0) {
		z = PI * x * x;	
		return z;
	}
	return 0.0;
}
