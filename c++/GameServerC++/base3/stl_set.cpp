#include <set>
#include <iostream>

//set multiset 是c++98中引入的二叉树数据结构
//应用场景: 频繁的插入和查找,并且是按照顺序的.
//namespace std {
//template<typename T, typename Compare = less<T>, typename Allocator = allocator<T>>
//class set; //set容器中只能保留唯一的值
//
//template<typename T, typename Compare = less<T>, typename Allocator = allocator<T>>
//class multiset; //multiset中,可以保留重复的值
//};

//特点: 自动将元素排序
//插入和删除找的算法复杂度为: O(logn)
//必须元素必须支持严格的弱顺序
// 1.如果x < y == true ,则y < x == false
// 2.如果x < y == true, y < z == true, 则 x < z == true
// 3. x < x == false
// 4.如果a == b, b == c,则c == a;
//不能改变元素的值

//辅助的类
//namespace std { //set和map在内部储存是以pair数据结构储存的
//struct pair {
//T1 first;
//T2 second;
//}
//}

//

void setPart() {
using Group = std::set<float>;

Group a;
Group b = a;
Group c(a);
Group d(c.begin(), c.end());
Group g({1.0f, 4.0f, 3.0f});
Group h = {1.0f, 4.0f, 3.0f}; //默认排序: 1.0 3.0 4.0
Group i {1.0f, 3.0f, 4.0f};

d.empty();
d.size();
d.max_size();

//operator == != < > <= >=
//special:
auto keycomp = c.key_comp(); //返回的是构造中默认的 less<T>
auto valuecomp = c.value_comp(); //也是返回 less<T>

//赋值:
b = g;

//交换:
b.swap(a);
std::swap(a, b);

//迭代器相关
a.begin();
a.end();
a.cbegin();
a.cend();
a.rbegin();
a.rend();
a.crbegin();
a.crend();

auto iterBegin = a.begin();

//算法函数:
//对于set来说,count()返回值只有两个.0 和１, 就是1.0值有几个 ,对于multiset 就返回有几个值
auto num = a.count(1.0f); 
auto findIter = a.find(1.0f); //找特定的值,返回一个迭代器, 若找到,则该迭代器为找到符合第一个的元素迭代器
//若没有找到, 则返回一个end()迭代器, 所以还得做一下判断
if(findIter == a.end()) {
	//not found!
} else {
	*findIter; //符合要求的第一个元素
}

auto lower = a.lower_bound(1.0f); //返回一个大于或等于这个插入值的位置迭代器
if(lower != a.end()) {
	if(*lower == 1.0f) {
		//has 1.0f	
	}
}

auto high = a.upper_bound(1.0f); //返回一个总是大于这个插入值的位置的迭代器
auto equal = a.equal_range(1.0f); //返回以上两种情况的一个结构体吧
equal.first; //lower
equal.second; //high

auto eraseIter = b.erase(b.begin());
eraseIter = b.erase(b.begin(), b.end());

auto state = b.insert(100.0f); //state is a pair, 返回一个pair <Iterator, bool>
//auto insertIter = b.insert(c.begin(), c.end());
b.emplace(10.0f);
b.emplace_hint(b.end(), 100.0f);

}




int main(void) {
	return 0;
}
