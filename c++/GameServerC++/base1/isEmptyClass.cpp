#include <iostream>
using namespace std;

class A {
};
class B {
	char a;
};

template<class T>
class EmptyHelper : T {
	int arr[128];
};
class EmptyHelper2 {
	int arr[128];
};

template<class T>
bool isEmptyClass() {
	return sizeof(EmptyHelper2) == sizeof(EmptyHelper<T>);
}
//判断一个类是否为空
static void testEmptyClass() {
	cout << "Sizeof empty class is: " << sizeof(A) << endl;
	cout << "Sizeof not empty class is: " << sizeof(B) << endl;
	cout << "judge empty class: " << isEmptyClass<A>() << endl;
	cout << "judge not empty class: " << isEmptyClass<B>() << endl;
}
int main(void) {
	testEmptyClass();
	return 0;
}
