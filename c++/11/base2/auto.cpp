#include <typeinfo>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

static void autoValue();
static void autoPointer();
static void newVersionFor();
static void newVersionConstruct();
static void defaultInitValue();
static void leftRefAndRightRef();

//自定义类实现新型for循环
class MyVector {
	public:
		using GroupType = std::vector<int>;
	public:
		GroupType m_group;
		void push_back(int x) {
			m_group.push_back(x);
		}
};

MyVector::GroupType::iterator begin(MyVector &v) {
	return v.m_group.begin();
}
MyVector::GroupType::iterator end(MyVector &v) {
	return v.m_group.end();
}
void testMyClass() {

	MyVector mv;
	mv.push_back(1);
	mv.push_back(2);
	mv.push_back(3);
	for(auto i : mv) {
		std::cout << i << " ";	
	}
	std::cout << std::endl;
}


int main(int /*argc*/, char** /*argv*/) {
	testMyClass();
	//new version auto
	//autoValue();
	//autoPointer();
//	newVersionFor();
	//newVersionConstruct();
//	defaultInitValue();
	leftRefAndRightRef();
	return 0;
}

static void autoValue() {
	auto age = 10;
	auto name = std::string("Yt");
	auto height = 160.0f;
	auto wight = 72.0;
	std::cout << "age is type " << typeid(age).name() << std::endl;
	std::cout << "name is type " << typeid(name).name() << std::endl;
	std::cout << "height is type " << typeid(height).name() << std::endl;
	std::cout << "weight is type " << typeid(wight).name() << std::endl;
}
static void autoPointer() {
	auto age = new int(10);
	auto name = "Yt";
	auto height = new float(160.0f);
	auto wight = new double(72.0);

	std::cout << "age is type " << typeid(age).name() << std::endl;
	std::cout << "name is type " << typeid(name).name() << std::endl;
	std::cout << "height is type " << typeid(height).name() << std::endl;
	std::cout << "weight is type " << typeid(wight).name() << std::endl;
}
static void newVersionFor() {
	int ids[] = {1, 2, 3, 4, 5};
	std::cout << "new version";
	for(auto v : ids) {
		std::cout <<  v << " ";	
	}
	std::cout << std::endl;

	std::cout << "old version";

	for(int i = 0; i < sizeof(ids) / sizeof(ids[0]); ++i) {
		std::cout << ids[i] <<  " ";	
	}
	std::cout << std::endl;

	//vector::
	std::vector<int> group;
	for(int i = 0; i < 4; ++i) group.push_back(i);
	//old version:
	//老版本遍历方式 
	for(std::vector<int>::size_type i = 0, size = group.size(); i < size; ++i) {
		//cout << group[i] << " ";	
	}
	//通过迭代器来遍历
	std::cout << "iterator: " << std::endl;
	//-------对于迭代器自增的时候,要用前置操作符,不要用后置操作符. ++iter, 若使用后置操作符号
	//多了一个步骤,就是把自增前的值先保留起来, 然后在自增.无用功
	for(std::vector<int>::const_iterator iter = group.begin(); iter != group.end(); ++iter) {
		std::cout << *iter << " ";	
	}

	std::cout << std::endl;
	//auto version
	std::cout << "vector old version:" << std::endl;
	for(auto v : group) {
		std::cout << v << " ";
	}

	std::cout << std::endl;
	std::cout << "vector new version:" << std::endl;
	for(auto &v : group) {
		v = 1;
	}
	for(const auto &v : group) {
		std::cout << v << " ";
	}
}

class A {
	public:
		//why explicit ?? 具体含义是什么?
		explicit A(int value) : m_value(value) { }

	private:
	int m_value;
};

static void newVersionConstruct() {

	A a(10);
	A b{3};

	//old
	int avector[] = {1, 2, 3};
	std::vector<int> bv;
	for(auto v : avector) bv.push_back(v);
	
	//new 
	std::vector<int> cv = {1, 2, 3};
	std::vector<int> v {1, 2, 3};

	A c(true);
	A d(false);

	A e(1.0);
	// A f{1.0} //不能做构造, 只能提高精度， 不能丢失
}

class B {
	public:
		B() : m_age(18), m_height(170), m_weight(75) {}
		explicit B(int age) : m_age(age), m_height(170), m_weight(75) {}
		B(int age, int height) : m_age(age), m_height(height) {}
		int age() const { return m_age; }
		int height() const { return m_height; }
		int weight() const { return m_weight; }
	private:
		int m_age;
		int m_height;
		int m_weight;
};

class NewB {
	public:
		NewB() {}
		explicit NewB(int age) : m_age {age} {}
		NewB(int age, int height) : m_age{age}, m_height {height} {}
		int age() const { return m_age; }
		int height() const { return m_height; }
		int weight() const { return m_weight; }
		void p() const { std::cout << m_value << " " << m_fightValue;}

	private:
		int m_age = 18; //初始化, 放置出现bug
		int m_height = 170;
		int m_weight = 75;
		int m_value{}; //代表拿int的默认值来作初始化,也就是0
		double m_fightValue{}; //0.0
};

static void defaultInitValue() {
	B a(10, 20);
	NewB b(10, 20);

	std::cout << "Old a age is" << a.age() << "height " << a.height()
		<< " wight " << a.weight() << std::endl;

	std::cout << "New b age is" << b.age() << "height " << b.height()
		<< " wight " << b.weight() << std::endl;

	b.p();
}

static void leftRefAndRightRef() {
	//什么是引用
	//引用类似与指针,　不同之处在于, 指针可以为nullptr, 但引用不可以
	int a = 10;
	int &refA = a;
	const int &constRefA = a;
	std::cout << " a" << a << " ref of a " << refA << " const ref a "
		<< constRefA << std::endl;
	//this is a error
	// int &refB = 10;
	const int &constRefB = 10; //不管左值还是右值,都能赋给const 引用
	std::cout << "different version const ref " << constRefB << std::endl;

	//auto &&rrB = 20; //与下一样
	int &&rrB = 20;
	const int &&crrB = 20;
	
	rrB = 30; //可以改变右值, 其实只是改变那个值而已
	std::cout << " right ref of b " << rrB << " const right ref b "
		<< crrB << std::endl;
	int b = 20;
	int &&newRRB = std::move(b); //强行转为右值
	const int &&cNewRRB = std::move(b);
	std::cout << " b " << b << " right ref of be " << newRRB << "const right ref b "
		<< cNewRRB << std::endl;
	std::cout << "address " << &b << " ref " << &newRRB << " c ref " << &cNewRRB << std::endl;

}










