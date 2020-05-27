#include <iostream>
#include <memory>
#include <cassert>

//auto ptr
//shared_ptr
//unique_ptr
//weak_ptr

class Parent; //采用前置声明

using ParentPtr = std::shared_ptr<Parent>;
typedef std::weak_ptr<Parent> WeakParentPtr;

class Child {
	public:
//		ParentPtr father; //内存泄露
		WeakParentPtr father; //采用弱指针,则可以释放内存,不造成内存泄露
		Child() { std::cout << "Child!!" << std::endl; }
		~Child();
};

typedef std::shared_ptr<Child> ChildPtr;
typedef std::weak_ptr<Child> WeakChildPtr;

class Parent {
	public:
		Parent() { std::cout << "Parent!!" << std::endl; }
		ChildPtr son;
//		WeakChildPtr son;

		void print() const { std::cout << "use_count: " << this->son.use_count() << std::endl;}
		~Parent();
};

class Object {
	public:
		Object(int id) : m_id(id) { std::cout << "init obj " << m_id << std::endl; };
		~Object() { std::cout << "bye bye " << m_id << std::endl; }
		int id() const { return m_id; }
	private:
		int m_id = 0;
};
using ObjectPtr = std::shared_ptr<Object>;

Child::~Child() { std::cout << "bye child!" << std::endl; }
Parent::~Parent() { std::cout << "bye parent!" << std::endl; }
//----------------------------------------------
void testParentAndChild() {
	ParentPtr p(new Parent());
	ChildPtr c(new Child());

//采用这种方式,造成内存泄露
	p->son = c; //智能指针拷贝, use_count + 1, c 的use_count 为 2
	p->print();
	c->father = p; //p 的 use_count 也为 2 了

//智能指针析构之后use_count  -1
//智能指针特性: 只有当use_count 变为0 时,才能释放掉管理的资源
//所以智能指针析构后,use_count 不为0,则造成了内存泄露
	////////////
//只要打破环状的引用,则share_ptr就会很好的管理内存
}
//----------------------------------------------
//为了解决以上问题, 采用weak_ptr来解决
void sharedPtrWithWeakPtr() {
	ObjectPtr obj(new Object(1));
	typedef std::weak_ptr<Object> WeakObjectPtr;
	WeakObjectPtr weakObj(obj);//弱指针依赖于share_ptr,若share_ptr是有效的,则wake_ptr也是有效的.
	WeakObjectPtr weakObj2(obj);
	//而wake_ptr在进行赋值的操作运算的时候,并不影响use_count, 相当于只是作为监听者

	
	std::cout << "obj use count is " << obj.use_count() << std::endl;
	{
		auto p = weakObj.lock(); //相当于返回了一个 ObjectPtr类型,
		std::cout << "expired: " << weakObj.expired() << std::endl; //expierd() 查看监控的资源过期没有过期
		if(p) {
			std::cout << p.unique() << std::endl; //false, use_count >= 2, 因为auto p = ...,进行了一次指针拷贝, 
			//所以use_count + 1, 而weakObj.lock()返回若是有效的话,则use_count >= 1, 否则返回nullptr
			//则总体的就use_count >= 2
			//do what you wanna do	
		}else {
		
		
		}
	}
	obj.reset(); //obj 放弃管理的资源
	std::cout << "endl;";
	auto p2 = weakObj.lock(); //返回空,因为,obj不管理资源了
	
	obj.reset(new Object(2)); //重新管理另一个资源
	{
		auto p = weakObj.lock();
		if(p) {
			assert(false);
		}else {
			//要么资源已经释放,要么obj管理的资源跟换了.
			std::cout << "changed!" << std::endl;
		}

	}
	std::cout << "expired: " << weakObj.expired() << std::endl; //expierd() 查看监控的资源过期没有过期
}
int main(void) {
	testParentAndChild();
//	sharedPtrWithWeakPtr();
	return 0;
}
