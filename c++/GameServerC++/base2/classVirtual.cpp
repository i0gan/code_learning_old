#include <map>
#include <iostream>
/*
	类虚函数遇到构造和析构就退化了
 */

class Event; //类的前置声明
class Event {};
class Base {
	public:
		virtual ~Base() {} //why? virtual
		Base(int _id) : m_id(_id) {}
		virtual void act(Event const&) = 0;
		virtual void print() const = 0;
		int id() const { return m_id; } 
	private:
		int m_id;
};
class Drived : public Base { //why public?
	public:
		void act (Event const&);
		void print() const;
		Drived(int id);
		~Drived();
	private:

};
class Grouped : public Base {
	public:
		void act(Event const&);
		void print() const;
		void addBase(Base* b);
		void removeBase(int id);
		Grouped(int id);
		~Grouped();
	private:
		std::map<int, Base *> m_info;
};
void test() {
	//int a = 1;
	/*
	Drived *info = new Drived(1);	
	Grouped *group = new Grouped();

	group->print();
	group->act(ev);
	group->addBase(info);
	group->removeBase(info->id());
	group->id();

	Base *baseGroup = group;
	baseGroup->act(ev);
	baseGroup->print();
	baseGroup->id();
	//removeBase()
	//addBase()
	//而基类的指针baseGroup中强制把派生类转换,而基类在虚函数中干的事,与派生类的一样
	//相当于派生类来实现函数,而不是基类.这就实现了指针对接口进行编程.
	delete group; //delete baseGroup;没有内存泄露,　与delete group等价
	delete info;
	*/
}


int main(void) {
	test();
	return 0 ;
}
