#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
/*
	建议: 在类的构造函数中抛出异常 
 */
class A {
	public:
		A() {}
};
class B : public A {
	public:
		B() {}
		~B() { /*std::cout << "byebye B\n";*/ }
	private:
		std::string m_value;
};
class GoodB : public B {
	public:
		GoodB() : m_v(new char(10000000)) {}
		GoodB(const char* f) : m_file(f, std::ios_base::in) {
			//在构造器里进行抛出异常,而不是一直判断是否有错误来避免错误.
			if(!m_file.is_open()) throw std::string("Couldn't open file..\n");

			std::string line;	
			while(std::getline(m_file, line)) {
				m_info.push_back(line);
			}
		}
		void doIt( GoodB const&b) {
			if(b.isOpen()) {
				//do	
			}
		}
		//通过析构来提示.
		~GoodB() { assert((!isOpen()) && "open file: "); }
	private:
		char *m_v;
		std::fstream m_file; //外部文件 
		std::vector<std::string> m_info;
		//若作为状态判断,一般声明为私有函数, 通过assert来提示.
		bool isOpen() const { return !m_info.empty(); }
};
//循环构造, 内存崩溃
//想实现一个 std::out_of_memory 异常
void test() {
	int i = 0;
	for(;;) {
		try {
			++i;	
			if(i % 10000 == 0) std::cout << "count i: " << i << std::endl;
			GoodB b;	
		} catch(...) {
			return ;	
		}
	}
}

void test2(char *filename) {
	try {
//在构造时候进行抛出异常,重复抛出, 不会出现问题, 而在析构函数中抛出,程序则会崩溃
		GoodB b(filename);	
		GoodB d(filename);
		b.doIt(b);
		//std::swap(b, d) //也不要抛出异常
	} catch(std::string msg) {
		std::cout << msg;
	}
}
int main(int argc, char** argv) {
	if(argc <= 1) return 1;
//	test();
	test2(argv[1]);
	std::cout << "exit!!!\n";
	return 0;
}
