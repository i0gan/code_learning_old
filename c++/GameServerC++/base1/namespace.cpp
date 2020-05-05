#include <iostream>
namespace A {
	struct X {};
	struct Y {};
	void f(int) {std::cout << "A::f\n";}
	void g(X) {std::cout << "A::g\n";}
}
namespace B {
	void f(int i) {
		f(i);//调用自身的f(int)
	}
	void g(A::X x) {
//	g(x); //调用namespace A中的g(X)
	}
	void h(A::Y y) {
		h(y); //调用自身
	}
}
//using namespace A;
using namespace B;
int main(int argc, char **argv) {

	f(1);	
	return 0;
}
