#include <vector>
#include <iostream>
#include <cstring>
//#include <memory>
//c++ 98

static void vectorPart() {
//vector 是c++98中引入的动态数组(dynamic array)
//namespace std {
//template<typename T, typename Allocator = allocator<T>> //就是用默认的alloctor了,
//	class vector;
//}
//特点随机访问元素, 末端添加删除元素效率最高, 前端和中间删除和添加元素效率最低,
//存在当前容器大小和容量的关系
using Group = std::vector<float>;

Group a;
Group b = a; //拷贝构造
Group c(a); //拷贝构造
Group d(10); //定义容量的大小
Group e(10, 1.0f); //10个初始化为1.0
Group f(e.begin(), e.end()); //传入两个迭代器,中间的所有值都会被拷贝
Group g({1.0f, 2.0f, 3.0f}); //c++11, 把写好的元素直接填
Group h = {1.1f, 2.1f, 3.1f};
Group i {1.2f, 2.2f, 3.2f, 4.2f}; //initialize list

d.empty();
d.size(); //当前的大小
d.max_size(); //max_size()相对于其他容器的要小一些
d.capacity(); //最多能在装入多少个元素,前提没有分配内存的情况下.
d.reserve(100); //预先分配100个内存空间
d.shrink_to_fit(); //c++11 

//operator == != < > <= >=

//赋值
b = g;
b.assign(3, 1.0f); //代表重新分配元素为: {1.0f, 1.0f, 1.0f}
b.assign(g.begin(), g.end());
b.assign({1.0f, 2.0f, 3.0f});

//交换: 交换给vector类中的指针,效率比较高
b.swap(a);
std::swap(a, b); 

//元素访问:
b[0];
b.at(0); //越界抛出异常: std::out_of_range
if(b.empty()) {
	b.front(); //一定要检查, 不然会出现错误, undefined
	b.back();

}
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

//
//去除最后一个元素
//signal thread OK, multthread maybe wrong
a.pop_back(); //maybe wrong

//删除某个特定位置的元素
b.erase(b.begin()); //删除掉迭代器当前位置的元素, 而后面的元素会往前移动, 返回下一个元素的位置
b.erase(b.begin(), b.end()); //删除掉迭代器中间元素
//要检查迭代器是否失效

b.push_back(10.0f); //尾部插入元素
b.pop_back(); //获取尾部元素,且释放

//在某个位置插入元素
//在尾部插入100.0
auto iter = b.insert(b.end(), 100.0f); //返回插入元素所在的迭代器
iter = b.insert(b.end(), 10, -10.0f); //在尾部插入10个 -10.0f
b.insert(b.end(), h.begin(), h.end()); //在尾部插入 两个迭代器之间的元素

b.emplace(b.end(), 10.0f); //c++11
b.emplace_back(10.0f); //c++11  && move copy 右值 拷贝

b.resize(10); //设置vector的大小
// 若改变小了,就会调用元素相应的析构
b.resize(100, 1.0f); //把vector的大小设置为100,若元素个数不足100,以值为:1.0来填充到100
b.clear(); //注意: 并不会让以前所占的内存降低, 只是可以把空间腾出来
b.shrink_to_fit(); //c++11, 降低内存到合适的大小

//和C的接口互用
std::vector<char> carr(100, 0);
strcpy(&carr[0], "hello World\n"); //最好用 carr.data();
printf("%s", carr.data());
//错误用法:
printf("%s", carr.begin());

//异常:
//1. push_back
//2. 元素 move / copy 没有异常的话
//insert
//emplact
//emplce_back
//push_bakc
//pop_back
//erase
//swap
//clear　都不会有异常

//特殊:
//标准化的失误:  不要使用,std::vector<bool>
}
int main(int, char**) {

	return 0;
}
