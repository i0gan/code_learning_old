#include <unordered_map>
#include <iostream>


//提供了hash算法区分unordered_map的各个元素, 若hash一样,则比较key
//unordered_map,有五个参数,平常的话就只是用两个.

// unordered_multiset unorderd_set
// unorderd_map unorderd_multimap 是c++11中以hash table为基础的, 内部元素没有明确的顺序的容器
// namespace std {
// template<typename Key, typename T, typename Hash = hash<Key>, typename
// EqPred = equal_to<Key>, typename Allocator = allocator<pair<const Key>, T>>>
// class unordered_map {
// template<typename Key, typename T, typename Hash = hash<Key>, typename
// EqPred = equal_to<T>, typename Allocator = allocator<pair<const Key, T>>>
// }
// class multimap; 
// template<typename T, typename Hash = hash<T>, typename
// EqPred = equal_to<T>, typename Allocator = allocator<T> >
// class unordered_multiset;
// }



int main(void) {

//	multimap<int, string> a;

	return 0;
}

