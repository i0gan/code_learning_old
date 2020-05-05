#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
class INT {
public:
	INT(int x):n(x){}
	friend bool operator < (const INT & int_l, const INT & int_2);
	friend bool operator == (const INT & int_1, const INT & int_2);
	friend ostream & operator << (ostream & out, const INT & int_x);
private:
	int n;
};

bool operator < (const INT & int_1, const INT & int_2) {
	return int_1.n < int_2.n;
}

bool operator == (const INT & int_1, const INT & int_2) {
	return int_1.n == int_2.n;
}

ostream & operator << (ostream & out, const INT & int_x) {
	out << int_x.n;
	return out;
}

template <class T>
void Plist(T begin, T end) {
	for(; begin != end; ++begin)
		cout << *begin << " ";
	cout << endl;
}
int main(void) {
	INT a[6] = {1, 4, 5, 2, 9, 2};
	int b[7] = {11, 32, 23, 35, 2, 4, 4};
	list<INT> lst1(a,  a+6), lst2(b, b+7);

	lst1.sort(); //顺序排序
	cout << "1. "; Plist(lst1.begin(), lst1.end());
	lst1.remove(2); //删除所有与2相等的元素
	cout << "2. "; Plist(lst1.begin(), lst1.end());

	lst2.pop_front(); //删除第一个元素
	cout << "3. "; Plist(lst2.begin(), lst2.end());
	lst2.unique(); //删除所有和前一个元素相等的元素
	cout << "4. "; Plist(lst2.begin(), lst2.end());

	lst2.sort();
	lst1.merge(lst2); //合并lst2到lst1并清空lst2
	cout << "5. "; Plist(lst1.begin(), lst1.end());
	cout << "6. "; Plist(lst2.begin(), lst2.end());
	
	lst1.reverse(); //将lst1倒置
	cout << "7. "; Plist(lst1.begin(), lst1.end());
	lst2.insert(lst2.begin(), a + 1, a + 4); //在lst2中插入3, 2, 4三个元素
	cout << "8. "; Plist(lst2.begin(), lst2.end());
	list<INT>::iterator p1, p2, p3; // 定义三个迭代器
	p1 = find(lst1.begin(), lst1.end(), 23); //查找元素
	p2 = find(lst2.begin(), lst2.end(), 4);
	p3 = find(lst2.begin(), lst2.end(), 5);
	
	lst1.splice(p1, lst2, p2, p3); //将p2, p3插入p1之前，并从lst2中删除p2, p3

	cout << "9. "; Plist(lst1.begin(), lst1.end());
	cout << "10. "; Plist(lst2.begin(), lst2.end());

	return 0;
}

