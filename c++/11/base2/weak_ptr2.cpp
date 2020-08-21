#include <iostream>
#include <memory>
#include <cassert>
/*
		//this //调用了两次析构函数,
		ParentPtr p(this);
		//智能指针出了作用域后就delete this ,析构了
		//所以错了,为了解决这个问题,就需要自身的类继承于　std::enable_shared_from_this<Type>
		//将ParentPtr p(this) 换成, shared_from_this();
 
 */
class Parent;
typedef std::shared_ptr<Parent> ParentPtr;
typedef std::weak_ptr<Parent> WeakParentPtr;

class Child : public std::enable_shared_from_this<Child> {
	public:
		WeakParentPtr father;
//		ParentPtr father;
		~Child();
		Child();
		void checkRelation();
};

typedef std::shared_ptr<Child> ChildPtr;
typedef std::weak_ptr<Child> WeakChildPtr;

class Parent : public std::enable_shared_from_this<Parent> {
	public:
		WeakChildPtr son;
//		ChildPtr son;
		~Parent();
		Parent();
		void checkRelation();
};

void handleChildAndParentRef(const Parent &p, const Child &c) {
	if(c.father.lock().get() == &p && p.son.lock().get() == &c) {
		std::cout << "right relation" << std::endl;	
	}else {
		std::cout << "oop!!!!!!" << std::endl;
	}
}
void handleChildAndParent(const ParentPtr &p, const ChildPtr &c) {
	assert(c);
	assert(p);
	if(c->father.lock() == p && p->son.lock() == c) {
		std::cout << "right relation" << std::endl;	
	}else {
		std::cout << "oop!!!!!!" << std::endl;
	}
}
Child::Child() { std::cout << "hello child" << std::endl; }
Child::~Child() { std::cout << "bye child" << std::endl; }
Parent::Parent() { std::cout << "hello parent" << std::endl; }
Parent::~Parent() { std::cout << "bye parent" << std::endl; }

void Parent::checkRelation() {
	auto ps = son.lock();
	if(ps) {
		//this //调用了两次析构函数,
//		ParentPtr p(this);
		//handleChildAndParent(p, ps);	

		//智能指针出了作用域后就delete this ,析构了
		//所以错了,为了解决这个问题,就需要自身的类继承于　std::enable_shared_from_this<Type>
		//将ParentPtr p(this) 这种错误形式换成, shared_from_this()
		handleChildAndParent(shared_from_this(), ps);	
	}
		std::cout << "after call checkRelation" << std::endl;
}

void Child::checkRelation() {
	
}
void testParentAndChild() {
	//若Parent 继承于 std::enable_shared_from_this<Type>
	//则 Parent pp; 这种静态的就不推荐
	ParentPtr p(new Parent());
	ChildPtr c(new Child());
	p->son = c;
	c->father = p;
	p->checkRelation();
}

static void interfaceOfSharedPtr();
static void sharedPtrWithWeakPtr();
static void uniquePtr();

int main(void) {
	testParentAndChild();	
	return 0 ;
}
