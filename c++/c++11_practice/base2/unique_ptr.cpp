#include <iostream>
#include <memory>
#include <cassert>

class Object;

typedef std::unique_ptr<Object> UniqueObjectPtr;
using ObjectPtr = std::shared_ptr<Object>;

void print(const UniqueObjectPtr& obj) {}

class Object {
	public:
		Object(int x) : m_id(x) { std::cout << "Hello Obj" << std::endl; };
		~Object() { std::cout << "Bye Obj" << std::endl; };
		int id() { return m_id; }
	private:	
		int m_id = 0;

};
void transfer(UniqueObjectPtr obj) {
	std::cout << obj->id() << std::endl;
}

void uniquePtr() {
	UniqueObjectPtr obj { new Object(1) };
	auto p = obj.get(); //operator bool
	if(p) {
		//do some	
	}
	//better
	if(obj) {
				
	}
	
	std::cout << p->id() << " " << obj->id() << " " << (*obj).id() << " " << std::endl;
	print(obj);
	
	p = obj.release(); //释放所管理的指针
	std::cout << "release: unique_ptr" << std::endl;
	delete p; //直接释放资源

	obj.reset(new Object(2)); //reset 就是将以前所管理的指针释放掉, 管理一个新的指针
	//UniqueObjectPtr (const UniqueObject&) = delete //这种拷贝构造函数不存在
	//UniqueObjectPtr (const UniqueObject&&) = default //
	transfer(std::move(obj)); //采用这种方式传入, 则自己的资源不在管理,而交给了这个参数
	//传入之后, obj 值为null

	assert(obj == nullptr);
//	std::cout << obj->id() << std::endl;

	obj.reset(new Object(3));
	ObjectPtr sharedObj(std::move(obj));
	assert(obj == nullptr);
//boost库
/*
	c++ 智能指针来源于boost库.
	shared_ptr
	weak_ptr
	enable_shared_from_this
	scoped_ptr //与unique_ptr　很类似, 但局限性比较多, 所以c++11没有采用
	unique_ptr
 */
}

int main(void) {
	uniquePtr();
	return 0;
}
