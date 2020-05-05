#include <forward_list>
#include <iostream>

//forward_list 是c++11中引入的单项串列(singal linked list)
//namespace std {
//template <typename T, typename Allocator = allocator<T>>
//class
//}

//特点: 不支持随机元素访问, 访问头部元素速度快
//"forward_list" 和自己手写的c-style signal linked list相比
//没有任何时间和空间上的额外开销, 任何性质如果和这个目标抵触,我们
//就放弃该特征.
//任何位置插入和删除元素都很快, 常亮时间完成
//插入和删除不会造成迭代器失效 
//对于异常支持好, 出现异常对于forward_lit而言, 要么不成功, 要么没什么影响

static void forwardListPart() {
using Group = std::forward_list<float>;

Group a;
Group b = a;
Group c(a);
Group d(10);
Group e(10, 1.0f);
Group f(e.begin(), e.end());
Group g({1.0f, 2.0f, 3.0f});
Group h = {1.0f, 2.0f, 3.0f};
Group i {1.0f, 2.0f, 3.0f};

d.empty();
//d.size(); //没有size() ,为了效率
d.max_size();
//和vector不同, forward_list不提供以下函数:
//d.capacity();
//d.reserve(100);
//d.shrink_to_fit();

//operator == != < > <= >=

//赋值
b = g;
b.assign(3, 1.0f);
b.assign(g.begin(), g.end());
b.assign({1.0f, 2.0f, 3.0f});

//交换:
b.swap(a);
std::swap(a, b);

//元素访问, 不能随机访问
//b[0];
//b.at(0);
b.front();
//b.back(); 没有提供最后一个

//迭代器相关
a.begin();
a.end();
a.cbegin();
a.cend();
a.before_begin(); //返回第一个元素的前一个位置, 这个位置只是个占位符
a.cbefore_begin();  //const &
//a.rbegin();
//a.rend();
//a.rcbegin();
//a.rcend();

auto iterBegin = a.begin();

//a.pop_back(); 
a.empty();

//b.erase(b.begin()); //不支持erase
b.erase_after(b.begin()); //删除b.begin(), 的下一个元素 
b.erase_after(b.before_begin()); //return void //正确删除第一个元素 
b.erase_after(b.begin(), b.end()); //return void

//b.push_back(10.0f)
//b.pop_back();

b.push_front(1.2f);
b.emplace_front(1.3f);

//b.insert(b.begin(), 3.0f); 不支持insert

auto iter = b.insert_after(b.before_begin(), 100.0f);
iter = b.insert_after(b.before_begin(), 10, -10.0f);
b.insert_after(b.before_begin(), h.begin(), h.end());

//b.emplace(b.end(), 10.0f);
//b.emplace_back(10.0f);
b.resize(10);
b.resize(100, 1.0f);
//算法:
b.remove(1.0f);
b.remove_if([](auto v) { return v > 100.0f; });
//b.reverse(); //1 2 3 4 -> 4 3 2 1
//std::sort(a.begin(), a.end());
b.sort(); // <
g.sort();
b.merge(g); //对于排好顺序的list进行合并,且合并后也是排好顺序的
c.unique(); //对于排好序的进行删除重复元素
c.splice_after(c.before_begin(), b);


}
int main(void) {

//例:在索引为3的位置之前插入一个元素
	std::forward_list<int> forlist = {1, 2, 3, 4, 5, 6};
	auto fiter = forlist.before_begin();
	for(int i = 0; i < 2; ++i, ++fiter);
	forlist.insert_after(fiter, 10);
	for(fiter = forlist.begin(); fiter != forlist.end(); ++fiter) std::cout << *fiter << " " ;
	std::cout << std::endl;

	return 0;
}
