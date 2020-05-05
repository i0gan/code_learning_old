#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct Base {
	virtual void f() { std::cout << "base" << std::endl; }
	virtual void init() {}
	Base() {
		init();	
	}
};

struct Derived : Base { //结构体默认为public 继承, 类默认为 private
	void f() override { //加入override关键字,表示重写基类的f()虚函数
		std::cout << "derived overide" << std::endl;
	}
	void init() override { std::cout << "virtual init" << std::endl; }
} ;

struct Derived2 : Derived {
	public:
		void f() {}
		void init() {}
};

Base* factoryBase(int type) {
	Base* ret = nullptr;
	if(type == 0) {
		ret = new Base();	
	}else if(type == 1) {
		ret = new Derived();	
	}else if(type == 2) {
		ret = new Derived2();	
	}

	if(ret) ret->init();
	return ret;
}

void testVirtual() {
	//Base b;
	//Derived d;
	////虚函数调用通过引用
	////virtual funciton call through reference
	//Base& br = b;  //the type of br is Base&
	//Base& dr = d;  //the type of dr is Base& as well
	//br.f();
	//dr.f(); //在Derived类中已经对fun() 重写.
	//
	////虚函数调用通过指针
	////virtual function call through pointer
	//Base* bp = &b;
	//Base* dp = &d;
	//bp->f();
	//dp->f();

	////直接调用.
	////non-virtual function call
	//b.Base::f();
	//d.Derived::f(); //派生类
	//d.Base::f(); //基类
	////若在构造函数中或者析构函数中调用虚函数, 则会调用自身类中的虚函数,而不是派生类的重写的虚函数
	////虚函数特性还没体现
	Derived d;
}
int main(void) {
	testVirtual();
	return 0;
}
