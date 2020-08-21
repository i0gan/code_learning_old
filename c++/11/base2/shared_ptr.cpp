#include <iostream>
#include <memory>

static void interfaceOfSharedPtr();

int main(void) {
	interfaceOfSharedPtr();
	return 0;
}

class Object {
	public:
		Object(int id) : m_id(id) { std::cout << "init obj " << m_id << std::endl; };
		~Object() { std::cout << "bye bye " << m_id << std::endl; }
		int id() const { return m_id; }
	private:
		int m_id = 0;
};
//目前c++ 的4种指针
// auto_ptr  c++98 智能指针,使用了
// shared_ptr //共享指针
// unique_ptr //只能由一个使用者使用
// weaked_ptr //与share_ptr搭配使用

//使用智能指针
using ObjectPtr = std::shared_ptr<Object>;


//作为参数的obj,相当于拷贝了一次,use_count 会+ 1,但当函数结束时候,智能指针析构,use_count会恢复原来的个数
void print(ObjectPtr obj) {
	//-------------------------智能指针的成员函数
	std::cout << "count " << obj.use_count() << " id " << obj->id() << std::endl;
}
//以引用方式,不会进行copy, use_count不变
void printRef(const ObjectPtr &obj) {
	std::cout << "ref count " << obj.use_count() << "id " << obj->id() << std::endl;
}


static void interfaceOfSharedPtr() {
	ObjectPtr null;
	std::cout << "ref count is " << null.use_count() << std::endl;

	//使用智能指针来储存对象的指针
	ObjectPtr obj (new Object(1));	
	std::cout << "ref count is " << obj.use_count() << std::endl;

	ObjectPtr obj2(obj);
	std::cout << "ref count is " << obj2.use_count() << std::endl;

	ObjectPtr obj3 = obj;
	std::cout << "ref count is " << obj.use_count() << std::endl;

	obj2.reset(); //What dose means of reset ?
	std::cout << "ref count is " << obj.use_count() << std::endl;

	ObjectPtr obj4;
	obj3.swap(obj4); //把obj3的管理资源相互交换
	std::cout << "obj4 ref count is " << obj4.use_count() << std::endl;
	std::swap(obj3, obj4); //采用另一种方式交换 
	std::cout << "obj4 ref count is " << obj4.use_count() << std::endl;

	//把智能指针存储的指针传出来
	auto p = obj.get();
	if(p) {
		std::cout << "id is" << p->id() << std::endl;	
	}
	if(obj) { //重载了 operator bool
		std::cout << "p id is " << obj->id() << std::endl; //重载: operator ->
		std::cout << "ref id is " << (*obj).id() << std::endl; //重载了: operator *
	}
	
	obj4 = nullptr;
	//----------------------------->obj.use_count() == 1 可能效率比较底一点
	std::cout << "only one hold ptr " << obj.unique() << std::endl; //判断是否是一个人在使用
	std::cout << "judge differnt: " << std::endl;
	std::cout << "use_count: " << obj.use_count() << std::endl;
	printRef(obj);
	print(obj);
	std::cout << "use_count: " << obj.use_count() << std::endl;
}

void deleterOfObject(Object *obj) {
	if(obj)
		std::cout << "delete obj " << obj->id()  << std::endl;
	delete obj;
}

void useDeleter() {
	//当智能指针出了作用域后,析构函数就被调用, 哪怕中途抛出异常
	ObjectPtr obj(new Object(2), deleterOfObject);
	ObjectPtr obj2 = obj;
}
