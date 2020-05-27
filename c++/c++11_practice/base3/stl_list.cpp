#include <list>
#include <cassert>
#include <iostream>

//list 是c++98中引入的双向串列(double linked list)
//namespace std {
//template<typename T, typename Allocator = allocator<T>>
//class list;
//}
//特点: 不支持随机访问元素,访问头部和尾部元素快
//任何位置插入删除元素都很快,常亮时间内完成
//插入和删除不会造成迭代器的失效
//对于异常支持好, 出现异常对于list而言, 要么不成功, 要么没有影响

static void listPart() {
using Group = std::list<float>;

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
d.size();
d.max_size();
//和vecotr不同, list不提供以下函数
//d.capacity();
//d.reserve(100);
//d.shrink_to_fit();

// operator == != < > <= >=
//赋值
b = g;
b.assign(3, 1.0f);
b.assign(g.begin(), g.end());
b.assign({1.0f, 2.0f, 3.0f});

//交换
b.swap(a);
std::swap(a, b);

//元素访问, 不能随机访问
//b[0];
//b.at(0);
b.front();
b.back();

//迭代器相关:
a.begin();
a.end();
a.cbegin();
a.cend();
a.rbegin();
a.rend();
a.crbegin();
a.crend();

a.resize(10);
auto iterBegin = a.begin();
assert(a.size() >= 10);
//for(int i = 0; i < 5; ++i) ++iterBegin; //改变迭代器
std::advance(iterBegin, 0); //改变迭代器位置2
//遍历元素
for(; iterBegin != a.end(); ++iterBegin) std::cout << *iterBegin << " ";

a.pop_back(); //maybe wrong
if(!a.empty()) a.pop_back();

b.erase(b.begin());
b.erase(b.begin(), b.end());

b.push_back(10.0f);
b.pop_back();
b.push_front(1.2f);
b.emplace_front(1.3f);

auto iter = b.insert(b.end(), 100.0f);
iter = b.insert(b.end(), 10, -10.0f);

b.resize(5);
b.resize(10, 1.2f);

//算法:
b.remove(1.0f); //删除值为1.0f的所有值
//符合某个条件的值把它删除掉, 100.0f的值全部删除掉
b.remove_if([](auto v) { return v > 100.0f; }); //v 是list中元素的值
b.reverse(); //反转list
b.sort(); //默认以 < 

b.merge(g); // 合并两个排好顺序的list在b中,并清空g中的元素,结果b中就也是排好序的
c.unique(); // 前提: 将排好序的list重复的元素去掉
c.splice(c.begin(), b); //在某个位置插入整块的list, 把b作为一块插入c.begin().

}

int main(void) {
	listPart();
	return 0;
}
