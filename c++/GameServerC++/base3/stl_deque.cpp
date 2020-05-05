#include <deque>
#include <vector>

//deque是c++98中引入的动态数组(dynamic array)
//namespace std {
//template<typename T, typename Allocator = allocator<T>>
//class deque;
//}
//特点:随机访问元素, 末端和头部添加删除元素效率高,中间删除和添加元素效率低
//而vector仅仅操作尾部效率高
//元素的访问和迭代比vector要慢,迭代器不能是普通的指针

using Group = std::deque<float>;
static void dequePart() {
Group a;
Group b = a;
Group c(a);
Group d(10);
Group e(10, 1.0f);
Group f(e.begin(), e.end());
Group g({1.0f, 2.0f, 3.0f});
Group h = {1.0f, 2.0f, 3.0f};
Group i {1.0f, 2.0f, 3.0f};

if(!a.empty()) a.pop_back();

d.empty();
d.size();
d.max_size();

//和vector不同, deque不提供以下的函数 
//d.capacity();
//d.reserve(100);
d.shrink_to_fit(); //c++11

//交换
b.swap(a); 
std::swap(a, b);

//元素访问
b[0];
b.at(0);
b.front();
b.back();

//迭代器相关
a.begin();
b.end();
a.cbegin();
a.cend();
a.rbegin();
a.rend();
a.crbegin();
a.crend();


a.pop_back();
a.push_back(1.0f);
a.push_front(1.2f); //vector没有
b.emplace_front(1.0f);


auto iter = b.insert(b.end(), 100.0f); //在某个位置插入元素
b.insert(b.end(), 10, -10.0f);
b.insert(b.end(), h.begin(), h.end());
b.emplace(b.end(), 10.0f);
b.emplace_back(10.0f);
b.resize(10);
b.resize(100, 10.0f);
b.clear();
b.shrink_to_fit(); //释放适当的内存

//异常
//1 push_back push_front 不会抛出异常
//2 move /copy 没有异常的话
//insert emplace emplace_back push_back emplace_front
//pop_back pop_front erase swap clear　不会抛出异常

//应用场景: 可以来储存网络消息的连聊天包机制,分别发包机制

//using Buffer = std::vector<char>;
//using BufferGroup = std::deque<Buffer>;
//BufferGroup group;
//Buffer buffer;
//
//auto ok = readFromClinet(socket, &buffer);
//if(ok) {
//	group.emplace_back(std::move(buffer));
//}else {
//	//handle error
//}
//while(!group.empty()) {
//	auto ok = sendToClient(socket, group.front());
//	if(ok) {
//		group.pop_front();	
//	}else {
//		//handle error	
//	}
//}

}

int main(void) {

	return 0;
}
