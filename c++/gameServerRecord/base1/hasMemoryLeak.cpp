#include <iostream>
class ObjectA {
public: 
	ObjectA(int a) : m_value(new int(a)) {}
	~ObjectA() { std::cout << "~ObjectA\n"; delete m_value;}
private:
	int *m_value;
};
class Evil {
public:
	Evil(){ std::cout << "Evil\n"; throw 10; std::cout << "~Evil2";}
	~Evil() {std::cout << "~Evil\n";}
};

class Normal : public ObjectA {
public:
	explicit Normal(int a) : ObjectA(a), m_a(a + 1), m_resource(new int(a + 2)){}
	~Normal() {std::cout << "~normal\n"; delete m_resource;}
private:
	ObjectA m_a;
	Evil m_evil; //m_evil在m_resource之上,所以先抛出异常,因此,整个程序没有内存泄露
	//相当于:  explicit Normal(int a) : ObjectA(a), m_a(a + 1, m_evil(), m_resource(new int(a + )){}
	//若交换 m_evil 与 m_resource的顺序,则会发生内存泄露
	int* m_resource;
};
static void hasMemoryLeak() {
	try {
		Normal n(1);
	} catch(...) {
	}
}
int main(void) {
	hasMemoryLeak();
	return 0;
}
