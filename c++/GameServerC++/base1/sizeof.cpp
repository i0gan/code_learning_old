#include <iostream>
using namespace std;

class A {};
class B { char m_data;};
class C {
	char m_data[100];
};
class D {
	char* m_data;
	D() : m_data(new char[100]) {}
	~D() {delete [] m_data;}
};
static void testSizeof() {
	cout << "bool sizeof 1 " << sizeof(bool) << endl;
	cout << "char sizeof 1 " << sizeof(char) << endl;
	cout << "int sizeof 4 " << sizeof(int) << endl;
	char data[10];
	char* pData = data;
	cout << "char data[10] sizeof 10 " << sizeof(data) << endl;
	cout << "char*  sizeof 4 " << sizeof(pData) << endl;

	cout << "A sizeof 0 " << sizeof(A) << endl;
	cout << "B sizeof 4 " << sizeof(B) << endl;
	cout << "C sizeof 100 " << sizeof(C) << endl;
	cout << "D sizeof 4 " << sizeof(D) << endl;
	cout << "size_t sizeof 4 " << sizeof(size_t) << endl;
}
static void unsignedAndSigned() {
	size_t a = 10;
	int b = -1;	
	if(b < a) {
		cout << "-1 < 10";
	}else {
		cout << "10 < -1";	
	}
}

int main(void) {
	testSizeof();
	unsignedAndSigned();
	return 0;
}
