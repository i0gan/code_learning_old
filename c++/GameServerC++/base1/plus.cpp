#include <iostream>
using namespace std;

class A {public: A(){cout << "A";}};
class B {public: B(){cout << "B";}};
void print(A* a, B* b) {
	try {

	}catch(...) {
	}
	delete a;
	delete b;
}

static int callFirst(int a) {
	cout << "callFirst: " << a << endl;
	return ++a;
}
static int callSecond(int a) {
	std::cout << "callSecond " << a << endl;
	return --a;
}
static void print(int a, int b) {
	cout << "a:" << a << endl << "b: " <<  b << endl;
}

int main(void) {
	int a = 10;
	print(callFirst(++a), callSecond(a--));

	print(new A(), new B());
	return EXIT_SUCCESS;	
}
