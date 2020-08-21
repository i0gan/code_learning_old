#include <iostream>
#include <chrono>
#include <algorithm>
#include <list>
#include <map>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <deque>

//STL 是一个框架, 将数据结构和算法进一步的抽象
//容器, 迭代器, 算法
//容器: 储存东西的
//类别:
//1 序列式容器 array / vector / deque/list / forward_list		 一般实现方式: 数组 ,指针 链表
//2 关联类有序容器 set / map / multiset / multimap               实现方式: 二叉树, 红黑树
//3 关联类无序容器 unordered_map / unordered_set / unordered_multimap / unordered_multiset		实现方式: hash table, 哈希表
//4 其他容器: stack / queue / priority_queue / string / bitset (存储对或错)

//迭代器: 就是容器的通用接口,可以用来遍历容器的元素
//算法: 查找, 排序, 修改...
//新型: regex (正则表达式), 增强了 rand算法, thread(线程), async, furture, time


//stl 容器的基本知识
//容器内元素的条件
//1. 必须可以复制(copy) 或则搬移(move) (隐含的条件是在拷贝和搬移的过程中应该没有副作用)
// c++ 的基本类型满足以上要求: bool char int int* char*, reference
//2. 元素必须可以被赋值操作,来作为复制或者搬移, (因为容器和算法对复写有要求)
//3. 元素可以被销毁

//针对于不同的容器还有特殊的要求
//对于序列式容器, 元素必须有默认的构造函数
//对于某些操作,元素需要定义 ==
//对于关联式容器, 排序默认准则的是 < 
//无顺序容器,必须要提供一个hash函数
//stl容器里面存的是元素的值而不是引用
//到底我们的容器里面应该存的东西是什么呢?

//STL对于错误怎么处理
//我们要记住的是STL的设计原则是: 效率优先, 安全为次
//异常? STL自己却不怎么用


//多数容器共有的接口:
template<typename T>
void containerAllInterface(T &a, T &b) {
	T c;
	T d(a); //copy
	T e = a; //copy
	T ee {a}; //copy
	T eee = {a}; //copy
	T f(std::move(a)); //move不是转化为右值,是移动数据
	//new
	auto iterB = b.begin();
	auto iterE = b.end();
	//old
	typename T::iterator iterF = b.begin();

	T g(b.begin(), b.end()); //从开始的地方到结束的地方进行拷贝
	T g2(iterB, iterE); //使用迭代器方式,一样


	b.size(); //std::forwad list 不提供size接口,绝大多数都有
	b.empty();  //return b.size() == 0;
	b.max_size();
	if(b == c) {} //先比较数量, 再比较顺序
	if(b != d) {} //
	if(b < e) {}  //unordered_set unordered_map .. 无顺序容器没有
	// b <= e	
	// b > e
	// b >= e

	//赋值
	e = b;
	e = std::move(b);

	e.swap(g); //交换容器所管理的资源, std::arrary 的交换为线性, O(n), 而其他是 O(1)
	//所以其他容器交换很高效,除了array
	std::swap(e, g); //与以上一样

	e.cbegin(); //const_iterator, 返回const iterator的引用
	auto ea = e.cbegin();
	auto eea = e.cbegin();
	*eea; //const &, &
	*ea; // const &
	e.cend();


	e.clear(); //清空容器的所有元素, 有一个容器没有. std::array
	//就是调用所有元素的析构.
}
void test_container() {
	std::vector<int> a;
	std::vector<int> b;
	containerAllInterface<std::vector<int>>(a, b);

	std::list<int> e;
	std::list<int> f;
	containerAllInterface<std::list<int>>(e, f);

	std::deque<int> g;
	std::deque<int> h;
	containerAllInterface<std::deque<int>>(g, h);

	//.......

	//? array, forward_list, unordered_...
}

int main(int, char**) {
	
	return 0;
}

