#include <map>

//map multimap 是c++98中引入的二叉树数据结构, 使用频率很高
//namespace std {
//template <typename Key, typename T, typename Compare = less<Key>,
//		 typename Allocator = allocator<pair<const Key, T>>>;
//class map;
//
//template <typename Key, typename T, typename Compare = less<Key>,
//		 typename Allocator = allocator<pair<const Key, T>>>;
//class multimap;
//}

//特点: 自动将元素进行排序
//插入和删除查找的算法复杂度为:O(logn)
//Key元素必须支持严格的弱顺序
// 1. x < y == true, y < x = false
// 2. x < y == true, y < z == true
// 3. x < x == false
// 4. a == b, b == c, c == a
//不能改变Key元素的值
template <class Map>
typename Map::mapped_type get_defualt (
	const Map &map, const typename Map::key_type &key,
	const typename Map::mapped_type &dflt = typename Map::mapped_type());


using Group = std::map<int, std::string>;
void mapPart() {
Group a;
Group b = a;
Group c(a);
Group d(c.begin(), c.end());
Group e({{1, "a"}, {2, "b"}, {3, "What?"}});
Group f = {{1, "a"}, {2, "b"}, {3, "What?"}};
Group i {{1, "a"}, {2, "b"}, {3, "What?"}};

d.empty();
d.size();
d.max_size();

//operator == != < > <= >=
//special
auto keycomp = c.key_comp();
auto valuecom = c.value_comp();

//赋值:
b = c;

//交换
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

//算法函数
auto lnum = a.count(1); //map count()  return 0 1
//auto num = a.count(1); //multimap count return >= 0;
auto findIter = a.find(1);
if(findIter == a.end()) {
	//not found
}else {
	//found
	*findIter; // 返回 std::pair<const int, std::string>&
	std::pair<int, std::string> obj;
	obj = *findIter; //会生成一个临时变量, 他是把const int, 类转化为int,则还需一次拷贝构造
}

auto lower = a.lower_bound(1);
if(lower != a.end()) {
	//if(*lower.second == 1) {
		//has 1	
	//}
}

auto high = a.upper_bound(1);
auto range = a.equal_range(1);

auto eraseIter = b.erase(b.begin());
eraseIter = b.erase(b.begin(), b.end());

//插入方式
auto state = b.insert(std::make_pair(100, "good")); //state is a pair<iteraotr, bool>

b.insert(c.begin(), c.end());

b.emplace(std::make_pair(10, "has it"));

//=> b.emplace (std::pair<const int, std::string>(10, std::string("again")));
b.emplace(11, std::string("again"));
b.emplace(12, "third"); //b.emplace (std::pair<const, const char*>(11, "third"));
b.emplace_hint(b.end(), 13, "haha");

auto &info = b[10]; //找到该值时,返回了一个string引用, 若找不到,则
//[] -> auto  iter = b.insert(std::make_pair(13, std::string)).first; return *(iter).second


b[13];
//使用at的话,采用try catch监控是否这个值没有
try {
	auto &findInfo = b.at(10); //有的话,返回引用, 没有则抛出异常
}catch(...) {

}


//可以将一下方式代替上面那种at方式,这个方式也可以被自定义类来辅助一下
auto findIter2 = b.find(10);
if(findIter2 != std::end(b)) {
//	auto &v = (*finIter2).second;
} else {
	
}

//采用以下方式,实现了对以上的再次包装
//auto info2 = get_defualt(b, 10);
//if(info2.empty()) {
  //not found
//}else {
  //found
//}


}
template <class Map>
typename Map::mapped_type get_defualt (
	const Map &map, const typename Map::key_type &key,
	typename Map::mapped_type &dflt = typename Map::mapped_type()) {
	auto pos = map.find(key);
	return (pos != map.end() ? pos->second : dflt);
}

int main(void) {

	return 0;
}

