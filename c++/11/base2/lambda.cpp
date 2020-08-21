#include <functional>
#include <iostream>
//基础函数
void printInfo(int a, int b, int c) {
			std::cout << " a " << a << " b " << b << " c " << c << std::endl;
}

//操作符重载函数
struct Print {
	void operator() (int a, int b, int c) const {
			std::cout << " a " << a << " b " << b << " c " << c << std::endl;
	}
};
//模板函数
template<typename T1, typename T2, typename T3>
void templatePrint(T1 a, T2 b, T3 c) {
			std::cout << " a " << a << " b " << b << " c " << c << std::endl;
}

//操作符重载 + 模板 的函数
struct TemplatePrint {
	template<typename T1, typename T2, typename T3>
		void operator() (T1 a, T2 b, T3 c) const {
			std::cout << " a " << a << " b " << b << " c " << c << std::endl;
	}
};

inline void print(int a, int b, int c) {
	std::cout << " a " << a << " b " << b << " c " << c << std::endl;
}
template<typename Fun>
void printUseFun(Fun fun, int a, int b, int c) {
	fun(a, b, c);
}
void test_1() {
	Print printUseClass;	
	TemplatePrint printUseTempClass;

	printInfo(1, 2, 3);
	printUseClass(1, 2, 3); //operator() (int a, int b, int c)

	templatePrint(1, 2, 3); 
	printUseTempClass(1, 2, 3);
	print(1, 2, 3);

	//以前inline 函数跟普通函数调用差不多
	//lambda就是个inline函数, 只是把 inline 函数作为一个参数或者一个local变量来使用, 

	std::cout << "lamda: " << std::endl;
	auto local = [](int a, int b, int c) {
		std::cout << " a " << a << " b " << b << " c " << c << std::endl;
	};
	printUseFun(local, 1, 2, 3);
	printUseFun([](int a, int b, int c) {
		std::cout << "lamda2:" << std::endl;	
		std::cout << " a = " << a << " b = " << b << " c = " << c << std::endl;
	}, 2, 3, 5);

	int a = 6, b = 7, c = 8;

	auto local2  = [a, b, c]() {
		std::cout << " a = " << a << " b = " << b << " c = " << c << std::endl;
	};
	local2();

	auto local3 = [=]() {
		std::cout << "====" << std::endl;
		std::cout << " a = " << a << " b = " << b << " c = " << c << std::endl;
	};
	local3();

	auto local4 = [=]() mutable {
		std::cout << "====" << std::endl;
		a = 4, b = 4 , c = 4;
		std::cout << " a = " << a << " b = " << b << " c = " << c << std::endl;
	};
	local4();
	
}
int main(void) {
	test_1();
	return 0;
}
