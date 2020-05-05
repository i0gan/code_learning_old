#include <iostream>
#include <set>
#include <string>
#include <algorithm>

	//如何把这个Person 类储存到set容器中, 按照年龄或则名字进行排序和比较

class Person {
	private:
		int m_age;
		std::string m_name;
	public:
		Person(int a, std::string n) : m_age{a}, m_name{std::move(n)} {}
		int age() const { return m_age;}
		const std::string &name() const { return m_name;}
		void print() const { std::cout << m_age << " : " << m_name << std::endl;}
		bool operator == (const Person& p) const {
			return m_age == p.m_age && m_name == p.m_name;	
		}
		void changeAge(int age) {
			m_age = age;
			std::cout << "Set age as: " << m_age << std::endl;
		};
};

struct CompareAge {
template <typename T>
	bool operator() (const T &t1, const T &t2) const {
		return t1.age() < t2.age();	
	}
};

struct CompareName {
template <typename T>
	bool operator() (const T &t1, const T &t2) const {
		return t1.name() < t2.name();	
	}
};

void test_Compare() {
	Person a {14, "Smith"};
	Person b {18, "Logan"};
	Person c {11, "Bob"};
	Person d {16, "Jonesy"};

	std::cout << "Order of age: " << std::endl;
	using AgeOrderSet = std::set<Person, CompareAge>;
	AgeOrderSet aSet;
	aSet.insert(a);
	aSet.insert(b);
	aSet.insert(c);
	aSet.insert(d);

	for(auto &v : aSet) {
		v.print();	
	}

	std::cout << std::endl;
	std::cout << "Order of Name: " << std::endl;
	using NameOrderSet = std::set<Person, CompareName>;
	NameOrderSet nSet;
	nSet.insert(a);
	nSet.insert(b);
	nSet.insert(c);
	nSet.insert(d);

	for(const auto &v : nSet) {
		v.print();	
	}
	std::cout << std::endl;


	//自定义排序方式查找问题
	auto iter = aSet.find(Person(14, "XXX")); 
	if(iter == aSet.end()) {
		//not found	
	}else {
		//找到的话也不一定是存在在容器里的, 查找的规则根据设定
		//的排序方式有关, 这里则是,只要年龄相同的就能查到, 不管名字相不相同
		//若以名字进行排序,则名字相同就能找到
		//found	
		std::cout << "Age test found!" << std::endl;
		static_cast<Person>(*iter).print();
	}

	auto iter2 = nSet.find(Person(434, "Logan")); 
	if(iter2 == nSet.end()) {
		//not found	
	}else {
		std::cout << "Name test found!" << std::endl;
		static_cast<Person>(*iter2).print();
	}

	//如何解决以上问题: 采用stl中的算法库. std::find(a,b,c);
	//算法复杂度 O(n)
	//a 代表迭代器的起始
	//b 代表迭代器的末尾
	//c 代表查找的元素
	//这个函数会根据Person类的operator ==() 函数来判断是否相等
	//所以就很好的避免了以上问题
	auto iter3 = std::find(aSet.begin(), aSet.end(), Person(14, "XXX"));
	if(iter3 == aSet.end()) {
		std::cout << "not found\n";
	}else {
		std::cout << "std::find() found\n";	
		static_cast<Person>(*iter3).print();
	}

	//尝试改变set容器的值问题
	//本质上,set容器是不允许用户去修改所储存的值
	//我们可以调用自己内部函数实现修改
	//修改的是栈里的内容, 不是堆的,还是不能修改
	auto iter4 = std::find(aSet.begin(), aSet.end(), Person(14, "Smith"));
//	auto iter4 = nSet.find(Person(41, "Logan")); 
	if(!(iter4 == aSet.end())) {	
		std::cout << "Logan found" << std::endl;
		static_cast<Person>(*iter4).changeAge(666);
		static_cast<Person>(*iter4).print();
	}
	std::cout << "Last name set" << std::endl;
	for(const auto &v : nSet) {
		v.print();	
	}

	std::cout << std::endl;

}

int main(int, char**) {
	test_Compare();
}
