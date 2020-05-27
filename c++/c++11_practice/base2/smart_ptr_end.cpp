#include <iostream>
#include <memory>
#include <cassert>
//智能指针总结:
/*
	 
 */
void sharedPtrNotice();
class Parent;
typedef std::shared_ptr<Parent> ParentPtr;
typedef std::weak_ptr<Parent> WeakParentPtr;
class Child : public std::enable_shared_from_this<Child> {
	public:	
		WeakParentPtr father;
		Child();
		~Child();
};
class Object {
	public: 
		Object(int x) : m_value(x) { }
	private:
		int m_value = 0;
};
using ObjectPtr = std::shared_ptr<Object>;

void sharedPtrNotice() {
	//1 : 绝对不要自己手动的管理资源 
	//int* a = new int(10);
	//delete a;
	//int *b = malloc(sizeof(int));
	//if(b) free(b);

	//2 :一个裸的指针不要用两个shared_ptr管理, 对于unique_ptr也如此
	//auto pObj = new Object(1);	
	//ObjectPtr obj(pObj);
	//ObjectPtr obj2(pObj);

	//用weak_ptr打破循环引用,parent 和 child
	//当需要在类的内部接口中, 如果需要将this 作为智能指针来使用的话,
	//需要用该类派生自std::enable_shared_from_this
	//
	//使用share_ptr作为函数的接口,如果有可能有const shared_ptr& 的形式
	//多线程模式下使用shared_ptr需注意的事项(....)

	//shared_ptr weak_ptr 和裸指针相比, 会大很多, 并且效率上会有影响.
	//尤其是在多线程模式下

	//shared_ptr 和 weak_ptr彼此互存,智能指针,空间上消耗资源比较大,而且时间效率上也比较低

	//一般情况下 ObejectPtr obj(new Object(2)),　相当于进行了两次new的过程.对于时间和空间上比较消耗
	//官方发现了这个问题,做了如下改正,且实现的功能一样

	//只实现了一次new,将new Object() 和 new 自身的指针归在一起
	ObjectPtr obj5 = std::make_shared<Object>(3); //真正推荐使用...


	//enable_shared_from_this 中shared_from_this()和构造析构函数一样
	//不能在构造或者析构中使用,否则会出错的.

	//某些情况下,会出现内存不会降问题.尤其是使用weak_ptr来处理循环引用问题
	//那是可能因为weak_ptr给勾住了,也要需要weak_ptr释放了,才能解决.

	//如果有可能,优先使用类的实例,其次万不得已 2 使用std::unique_ptr
	//万不得已 3 使用 std::shared_ptr
	Object obj6(4); //优先
	std::unique_ptr<Object> puObj(new Object(1)); //其次
	std::shared_ptr<Object> psObj = std::make_shared<Object>(3); //在其次

}
int main(void) {
	
	return 0;
}
