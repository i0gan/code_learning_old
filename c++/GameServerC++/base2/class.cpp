#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cassert>

class RuleOfFive;  //前置声明class
class Parent;
class Child {
	public:
		explicit Child(Parent *p) : m_parent(p) {}
	private:
		Parent *m_parent;
};
class Parent {
	public:
		//                           等同于: m_children.push_back(child)
		bool addChild(Child* child) {m_children.emplace_back(child); }
	private:
		std::vector<Child*> m_children;

};
//类的基本三大规则:
//类的构造
//类的析构
//类的复制
//若c++98中,不想复制的话,把构造函数设为私有变量, 并不实现构造函数
//不然编译器会自动生成一个对应的构造函数
//c++11 中: RuleOfThree(const RuleOfThree& other) = delete;

class RuleOfThree {
	public:
		RuleOfThree(const char* arg) : cstring(new char[std::strlen(arg) + 1]){ //allocate
			std::strcpy(cstring, arg); //populate	
		}
		~RuleOfThree() {
			delete[] cstring;	
		}
		//c++ 11中,声明该构造不能用, 以防编译器自动生成一个构造函数
		RuleOfThree(const RuleOfThree& other)  = delete;
		//	{//copy constructor
		//		cstring = new char[std::strlen(other.cstring) + 1];
		//		std::strcpy(cstring, other.cstring);
		//	}
		RuleOfThree& operator = (const RuleOfThree& other) {
			char *tmp_cstring = new char[std::strlen(other.cstring) + 1];	
			std::strcpy(tmp_cstring, other.cstring);
			delete[] cstring;
		}
	private:
		char* cstring;

};
//c++11
//类的５大基本原则:
//采用左值或者右值进行构造,编译器会对不同的构造函数进行构造.
class RuleOfFive {
	public:
		//只能针对与右值进行构造
		RuleOfFive(RuleOfFive&& rhs) {
			std::cout << "右值构造.." << std::endl;
			std::cout << rhs.m_value;
			m_value = rhs.m_value;
			rhs.m_value = nullptr;
		};
		RuleOfFive() : m_value(new int(10) ) {}
		//采用右值或者左值进行构造
		RuleOfFive(const RuleOfFive &rhs) : m_value(new int(* (rhs.m_value))) {
			std::cout << "左值或者右值构造.." << std::endl;
		}
		RuleOfFive& operator = (const RuleOfFive &rhs) {
			delete m_value; //删掉以前的
			*m_value = *(rhs.m_value);
			return *this;
		}
		//对= 操作符进行右值重载
		RuleOfFive& operator=(RuleOfFive&& rhs) {
			m_value = rhs.m_value;	
			rhs.m_value = nullptr;
			return *this;
		}
		void print() const {
			assert(m_value && "class print: "); //不推荐使用if来判断
			std::cout << "value: " << *m_value << std::endl;
		}
		~RuleOfFive() { delete m_value; }
	private:
		int *m_value;
};
//左值和右值的定义:
//1. 能够取到地址的值称为左值,否则为右值
void leftOrRight() {
	int a = 0;
	int b;
	int c = 2 + 3;
	int d = a + c;
	auto address = &a;
	//auto address2 = &(2 + 3);
	int& e = a; //左值引用
	//int& e2 = 3; //错误
	int&& e3 = 3; //右值引用.
}
//c++11增加了左值和右值的概念, 所以类的从３大基本原则变为了5大基本原则
void leftAndRight() {
	std::vector<int> a; //left
	for(int i = 0; i < 10; ++i) a.push_back(i);
	auto b = a; //b as left value
	auto &c = b; //c as left value
	//std::vector<int>& c = b; //c as left value
	//move函数啥也不干,就是让编译器把b转换为右值.
	auto d = std::move(b);//std::move(b) 就为右值了
	RuleOfFive f;
	RuleOfFive g(f); //左值构造
	RuleOfFive h (std::move(f)); //右值构造, f已经毫无意义
//	f.print(); //m_value 已经为nullptr
}

int main(void) {

	leftAndRight();
	return 0;
}
