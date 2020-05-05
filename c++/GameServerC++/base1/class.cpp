#include <iostream>
using namespace std;

class TestObject {
	public:
		TestObject(int a) : m_value(a) {
		       	cout << "a: m_value: " << this->m_value; }
		TestObject(const TestObject& rhs) : m_value(rhs.m_value) {
			cout << "b: m_value: " << this->m_value;
		}
	private:
		int m_value;
};

int main(void) {
	TestObject a(2);
//	TestObject d = 2;
	TestObject b(a);
//	TestObject c = a;
	return 0;
}
