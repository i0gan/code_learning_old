#include <iostream>
#include <array>
#include <cstring>

//c++ 11

template<typename C>
void checkSize(C &c) {
	if(c.size() > 3) {
		c[3] = 10; //单线程OK,多线程可能出错
	}
	c.at(3) = 10;
}


void arrayPart() {
	//array 实际上是对c/c++语言中的原生数组进行了封装
	//namespace std {
	//template<typename T, size_t N>
	//	class array;
	//}
	
	//特点: 内存分配在栈(stack), 绝不会重写分配.随机访问元素
	std::array<int, 100> a; //不进行初始化, 只管分配内存
	std::array<int, 100> b = {}; //初始化为 0 
	//以上两者的区别.

	std::array<int, 5> obj = {1, 2, 3, 4, 5};
	std::array<int, 5> obj2 = {1}; //第一个为1, 后面不0

	//接口
	a.empty(); //never be true if size > 0
	a.size();
	a.max_size();

	//operator == < != > <= >=
	auto aa = a;
	aa.swap(a); //array的swap是交换每一个元素都需要做交换,因为它是在stack中储存的.不是通过堆来管理
	//访问元素
	a[1]; //不进行检查,越界出错
	a.at(1); //进行检查,越界抛出异常
	a.front(); //返回头部元素的引用
	a.back();  //返回最后元素的引用
	checkSize(a);

	//迭代器相关的:
	a.begin(); //可以对begin减引操作, 但不能堆end进行此操作
	a.end();
	a.cbegin(); //const　引用
	a.cend();
	
	a.rbegin(); //从尾部遍历到头部,与以上相反
	a.rend();

	a.crbegin(); //const 方式从尾部遍历到头部
	a.crend();


	//和C的接口互用
	std::array<char, 100> carr;
	strcpy(&carr[0], "hello world\n");
	printf("%s", &carr[0]); //更好的使用 carr.data();
	printf("%s", carr.data());
	//错误用法
	printf("%s", carr.begin());


	//特殊的地方
	auto info = std::get<1>(carr); //与 carr[1] 一样
	printf("%c\n", info); //
	carr.fill(0); //对所有元素赋予0

	//异常 exception
	//c.at(pos)
	//copy move swap, 进行操作时,可能触发异常

}
int main(void) {

	arrayPart();
	return 0;
}
