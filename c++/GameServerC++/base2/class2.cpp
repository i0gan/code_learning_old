#include <iostream>
/*
	不要在析构函数中抛出异常 
 */
class A {
	public:
		A() {}
		~A() { std::cout << "A析构了.." << std::endl; }
};

/*
	析构函数调用规则：
	先调用成员析构
	再调用派生类析构
 */
//析构函数绝对不要抛出异常
class B : public A{
	public:
		B() {}
		~B() { std::cout << "B析构了.. " << std::endl; 
		throw std::string("B error"); } // 编译器默认析构函数: inline ~B() noexcept {}
	//编译器默认析构函数实现:
	/*
		inline ~B() noexcept {
			try {
			
			} catch(...) {
				std::terminate();	
				//析构函数绝对不要抛出异常
			}
		} 
	 */
	private:
		std::string m_value;
		/*
			在掉~B() 析构时候, 先调用 m_value的析构,再调用派生类 ~A();
		 */
};
void testClass_1() { //测试析构
	B *b = new B;
	delete b;
}
class EvilB : public B {
	public:
		~EvilB() noexcept(false) { throw std::string("error"); }
};
void testEvilB() {
	try {
		EvilB *b = new EvilB();	
		delete b;
		
	} catch(std::string e) {
		//没有捕获到异常,编译器已经调用std::terminate(),且程序崩溃
		//因为编译器为析构函数默认加入关键字 noexcept,可以加入关键字 noexcept(false) 
		//问题1 : 派生类虽然能够析构,若派生类析构函数也抛出异常,则程序就挂.
		//出现抛出两个异常, 则无法捕获.
		//问题2 : 若声明两次EvilB对象,析构两次时,则程序就会崩溃.
		std::cout << "catch your evil: " << e <<  std::endl;
	}
}
int main(void) {
	testEvilB();
	return 0;
}
