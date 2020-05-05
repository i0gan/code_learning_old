#include <iostream>
class Object {
public:
	Object() {}
	~Object() {}
private:
	int m_data[100];
};
char info[10000];
int main(void) {
	//代表在info这个内存里new
	Object *s = new(info)Object();
	//right ?
	//s->~Object();
	//or
	delete s;
	return 0;
}

/*
    memmory_pool, object_pool;
	采用自己的内存来储存new出来的东西 
	那该如何删除内存里的值呢?
	调用析构函数.为正确
	调用delete会出错,应为内存资源不是系统分配管理的
 */
