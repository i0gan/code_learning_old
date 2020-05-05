#include<iostream>
#include<functional>
#include <future> //指的是未来需要运行一些东西
#include <thread>
//g++ c++11.cpp -std=c++11 -pthread
int main(int, char**) {
	//添加未来要运行的东西
	auto f = std::async([](int v){std::cout << "hello world!" << std::endl;}, 10);
	//运行它,是在线程里运行
	f.get();
	//c++11的遍历方式
	int a[5] = {1, 2, 3, 2, 5};
	for(int i : a) {
		std::cout << i;
	}
	return 0;
}
