#include <iostream>
#include <typeinfo>
#include <cassert>
#include <map>
//#include <algorithm>
//#include <vector>
//#include <list>
//#include <stack>
//#include <future>
//#include <functional>
using namespace std;
/*
	keywords of c++ 

	alignas(c++11)	 //声明结构体或类的对齐数
	alignof(c++11)	 //查看结构体或类的对齐数
	and				 //等价于 &&
	and_eq			 //等价于 &&=
	asm				 //汇编语句
	auto			 //自动类型
	bitand			 //等价于  &
	bitor			 //等价于　|
	bool			 //bool类型
	break			 //跳出当前循环,或switch
	case			 //结合switch使用
	catch			 //捕获异常
	char			 //1字节变量
	short			 //2字节变量
	signed			 //声明为有符号类型
	unsigned		 //声明为无符号类型
	char16_t(c++11)  //常使用于Unicode字符
	char32_t(c++11)	 //常使用于Unicode字符
	int				 //默认４字节
	long			 //不比int类型小的类型
	class			 //类,或者声明模板类型
	compl			 //等价于 ~
	concept(概念Ts)	 //专家级别使用
	const			 //声明常变量
	constexpr(c++11) //用作函数时,是在编译是进行函数调用的,类似与宏
	const_cast		 //常变量强制转化为其他变量类型
	continue		 //结合循环来使用	
	decltype(c++11)  //与auto差不多,可以用于某个不确定多个参数类型的模板函数
	default			 //结合switch来使用
	delete			 //释放new出来的东西
	new				 //开辟内存
	do				 //配合 while构成循环
	explicit		 //不能隐式构造
	export			 //专家级别使用...
	extern			 //改变某个变量的作用域,常用在不同文件中使用同一个变量
	float			 //4字节的浮点类型
	double			 //８字节的浮点类型
	for				 //for循环
	goto			 //跳转
	if				 //判断
	friend			 //给类中的一些函数使用,可以访问类中的私有成员变量
	inline			 //内联声明, 编译器对该函数进行优化,类中函数和模板函数默认代这个参数
	mutable			 //在lambda表达式中使用表示为传递进来的变量可以被赋值
	namespace		 //声明命名空间　
	noexcept(c++11)  //声明为不抛出异常,利于编译器的优化 
	not				 //等价与 !
	not_eq			 //等价于 !=
	nullptr(c++11)	 //c++11以后声明空指针类型,主要解决模板函数中的参数问题
	operator		 //操作运算重载
	or				 //等价与 |
	or_eq			 //等价于 |=
	private			 //声明成员为私有的
	public			 //声明成员为公共的
	protected		 //声明成员为保护的
	register		 //声明在寄存器里的变量
	reinterpret_cast //常用在　一个类型的指针转化为另一个类型的指针
	requires(概念TS) //一个概念,目前还没有编译器实现
	return	 //函数的返回
	static	 //声明变量为静态的
	sizeof	 //获取某个变量的大小
	static_assert(c++11) //静态断言, 常用
	static_cast //静态转化
	struct	 //结构体类型
	switch	 //switch分支判断结构
	template //声明模板
	this	 //this指针, 常用在class和struct
	thread_local(c++11)  //结合线程来使用
	throw	 //抛出异常
	true	 //bool类型的真
	false	 //bool类型的假
	try		 //异常尝试
	typedef	 //改变变量名称
	typeid	 //获取类型的id号
	typename //声明模板类型
	union	//联合体
	using  //可以替换typedef的功能
	virtual //虚函数
	void   //空类型
	volatile //直接声明为定死的常量
	wchar_t //表示宽字符的
	while   //循环
	xor		//异或 ^
	xor_eq  //　^=

*/
//---------------------------------------------------------------
//alignas
struct alignas(8) S {};
struct alignas(1) U {S s; }; //bad
struct Foo {
	int i;
	float f;
	char c;
};
struct Empty {};
struct alignas(64) Empty64 {};
struct alignas(1) Double { double d; };
struct Obj {char a; int b;};
//sizeof(Obj) == 8
//alignof(Obj) == 4
void alignInfo() {
	cout << "Alignment of" << endl
		<<"_char			 : " << alignof(char) << endl
		<<"_pointer          : " << alignof(int*) << endl
		<<"_class Foo        : " << alignof(Foo) << endl;
}
//---------------------------------------------------------------
//and
void showAnd() {
	int a = 3;
	int b = 4;
	if(a == 3 && b == 4) {
		cout << "&& a = 3, b = 4";
	}
	if(a == 3 and b == 4) {
		cout << "and a = 3, b = 4";
	}
}
//---------------------------------------------------------------
//and_eq   <=>  &=
void testAnd_eq() {
	bool a = false;
	bool b = true;
	b = b and_eq a;
	cout << b << endl;
	bool c = true;
	c and_eq a;
	cout << "c: " << c << endl;
}
//---------------------------------------------------------------
//not <=> !
void testNot() {

	bool a = true;	
	bool b = not(a);
	cout << b;
}
//---------------------------------------------------------------
//not_eq <=> !=
void testNot_eq() {
	bool a = true;
	a not_eq(a);
	cout << a;
}
//---------------------------------------------------------------
//or <=> |
void testOr() {
	int a = 3;
	cout << a or 2;
}
//---------------------------------------------------------------
//or <=> |=
void testOr_eq() {
	int a = 3;
	a or_eq 4;
	cout << a;
}
//---------------------------------------------------------------
void showAsm() {
	asm (
	"movq $60, %rax\n\t" //the exit syscall number on linux
	"movq $2,  %rdi\n\t" //this program returns 2
	"syscall"
	);
}
//---------------------------------------------------------------
int get_fun(int x) {
	return x + 1;
}
double add(double a, double b) {
	return a + b;
}
void showAuto() {
	auto a = 1 + 2;
	cout << "type of a: " << typeid(a).name() << endl;
	auto b = add(1, 1.2);
	cout << "type of b: " << typeid(b).name() << endl;
	auto c = {1, 2}; //初始化列表
	cout << "type of c: " << typeid(c).name() << endl;

	auto my_lambda = [](int x) { return x + 3; };
	cout << "type of my_lambda: " << typeid(my_lambda).name() << endl;

	auto my_fun = get_fun;
	cout << "my_fun: " << my_fun(3) << endl;

	cout << "type of my_fun: " << typeid(my_fun).name() << endl;

}
//---------------------------------------------------------------
void showBitAndOr() {
	auto a = 3l; //long int
	auto b = 4;
	auto c = a bitand b;
	auto d = a bitor b;
	cout << "c: " << c << "d: " << d;
}
//---------------------------------------------------------------
void testBool() {
	bool a = true;
	bool b = false;
	*(reinterpret_cast<char *>(&a)) = -1;
	cout << a << " " << b << endl;
	if(a == true) {
		cout << "i'm true";
	}else if(a == false){
		cout << "i'm false";
	}else {
		cout << "What?";
	}
}
//---------------------------------------------------------------
void testBreak() {
	int a = 10;
	for(;;) {
		for(;;) {
			++a;	
			if(a > 1000) break;
		}	
		if(a > 100000000) break;
	}
}
//---------------------------------------------------------------
void testCompl() {
	int a = -3;
	int b = compl(a); // compl(a) <=> ~a
	cout << b;
}
//---------------------------------------------------------------
int fact(int n) {
	return n < 1 ? 1 : (n * fact(n - 1));
}
constexpr int factorial(int n) {
	return n < 1 ? 1 : (n * factorial(n - 1));
}
template<int N>
struct NN{
	void print() { cout << N << endl;}
};
void testConstExpr() {
	auto a = fact(4); //运行时计算
	auto b = factorial(4); //编译时计算, 类似于宏定义计算
	cout << "a: " << a << " b: " << b << endl;
	char group[factorial(5)];
	NN<factorial(8)> nn;
	nn.print();
}
//---------------------------------------------------------------
/*
void testThread(const int &a) {
	cout << "thread"	
}*/
void testConst_cast() {
	const int i = 3;
	//const int*
	int *p = const_cast<int*>(&i);
//	std::thread aa([&i](){ testThread(i); });
	*p = 5;
	cout << p << endl << &i << endl;
	cout << i << "  " << *p << endl;
}
//---------------------------------------------------------------
//decltype 与 auto 十分相近
struct A {A(int n) : x(n) {} double x;};
void testDecltype() {
	const A* a = new A(0);
	auto aa = a->x;
	decltype(a->x) y; // 相当于auto  aa = a->x
	decltype((a->x)) z = y; //相当于 auto & z = y, 引用
	y = 3;
//	z = 4;
	cout << y << endl << z;
}
// 写一个相加函数, 实现不确定类型相加的函数
template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) { //decltype(a + b) 推导出返回值类型
	return a + b;
}
/*
//陷阱: auto 
template<typename T, typename U>
auto add(Ta, Ub) {}
	return a + b;
	// return a + b 与 return (a + b) 可能表示的意义不同, 后者可能代表引用
}*/
//---------------------------------------------------------------
struct Base { virtual ~Base() {} };
struct Drive : Base {
	virtual void name() {}
};
void testDynamic_cast() {
	Base *b1 = new Base;
	//这里会调用不成功
	if(Drive *d = dynamic_cast<Drive *>(b1)) {
		std::cout << "downcast from b1 to d successful" << std::endl;	
		d->name(); //safe to call
	}
	
	Base *b2 = new Drive;
	//这里会调用成功
	if(Drive *d = dynamic_cast<Drive *>(b2)) {
		std::cout << "downcast from b2 to d successful" << std::endl;	
		d->name(); //safe to call
	}
	//对于dynamic_cast转换引用,若转化失败,则会抛出异常
	//dynamic_cast 在运行期进行检查 
	/*
	Base bb; 
	Drive& cc = dynamic_cast<Drive&>(bb);
	*/
}
//---------------------------------------------------------------
enum Color { red, green, blue };
//老的版本中,若出现 enmu Color2 {red, green, blue}; 就会出先重复的元素,就会报错
void testOldEnum() {
	Color r = red;
	switch(r) {
		case red:
			std::cout << "red" << std::endl;
		break;
		case green:
			std::cout << "green" << std::endl;
		break;
		case blue:
			std::cout << "blue" << std::endl;
		break;
		default:
			std::cout << "what ?" << std::endl;
	}
}
enum class NewColor {red, green, blue = green + 12};
enum class MyColor : short {black}; //通过short指定元素的类型为short

//若以bool作为函数参数, 建议使用enum来代替bool参数.
enum class IsGood {Yes, No};
enum class IsOk {Yes, No};
void enumBoolTest(IsGood isGood, IsOk isOk) {
}

void testNewEnum() {
	NewColor r = NewColor::blue;
	switch(r) {
		case NewColor::blue: {
			cout << "new blue" << endl;						 
		} break;
		case NewColor::red: {
			cout << "new red" << endl;						 
		} break;
		case NewColor::green: {
			cout << "new green" << endl; 
		} break;
		default:
			cout << "new what?" << endl;
	}

	int i = static_cast<int>(blue) + static_cast<int>(NewColor::blue);
	cout << "blud + NewColor::blue = " << i << endl;
	enumBoolTest(IsGood::Yes, IsOk::No);
}
//---------------------------------------------------------------
//test explicit
struct AA {
	AA(int) {}
	AA(int, int) {}
	operator int() const { return 0; } //AA可以默认的转化为int类型
};
struct BB {
	explicit BB(int) {}
	BB(int, int) {}
	explicit operator int() const { return 0; }
};
void testExplicit() {
	AA a1 = 1; //等价于 AA a1 = AA(1);
	//而BB就不能 BB b = 1;
	AA a2 = {3, 5}; //等价于 AA a1 = AA(3, 5);
	BB b2 = {3, 5}; //BB中B(int, int)没有加explicit
	int i = a1; //能通过
	//而BB就不能 int i = b2;
	//将BB强转.
	int na2 = static_cast<int>(a1);
	int nb2 = static_cast<int>(b2); //强转explicit　可以
	AA a4 = (AA)3;
	BB b3 = (BB)4; //通过C语言方式强制转换, 可以
}
//---------------------------------------------------------------
//friend
class MyClass {};
class Friend {
	private:
		int data; //private member
	friend std::ostream &operator << (std::ostream &out, const Friend &o);
	//Mycla　类是Fried类的好友, 只是单向
	template <typename T> friend class MyCla;  //every MyClass<T> is a friend of Friend
	template <typename T> friend void f(T) {} //every f<T> if a friend of Firend
	public:
	Friend(int x) : data(x) {}
	operator int() const { return this->data; }
};
//这样可以拿这个函数当公共函数访问私有成员
std::ostream &operator << (std::ostream &out, const Friend &f) {
	return out << f.data;
}
//若发生继承关系, MyCla不是, Friend2 的好友.
class Friend2 : public Friend { };

void testFriend() {
		Friend a = 44;
	cout << a;
}
//---------------------------------------------------------------
//goto
void testGoto() {
	auto i = 0;
NO:
	if(i < 5) {
		cout << i;
		i ++;
		goto NO;	
	}
}
//---------------------------------------------------------------
//inline
//尽量的减少栈空间开辟和回收操作
//类和模板函数,默认会加上inline进行优化.
//但不一定快
//inline 也可以与 namespace一起用， inline namespace
inline int plus(int a, int b) {
	return a + b;
}
class Inline {
	//在类中的函数里,编译器会默认加上inline进行优化
	public:
		void Member() const { std::cout << "hello\n"; }
		int vlaue() const { return this->m_value; }
	private:
		int m_value;
};
//---------------------------------------------------------------
//namespace
namespace XGroup {
	class A_ {
		int value;	
	};
}
namespace YGroup {
	class A_ {
		int value;	
	};
	class B_ {
		int value;	
	};
}
void testNmaespace() {
	XGroup::A_ a;	
	YGroup::A_ b;	
}
void testNamespace2() {
	using namespace XGroup;
	A_ a;
	using namespace YGroup;
	B_ b; //可以不用写 YGroup::B_
}
void testNamespace3() {
	namespace CGroup = XGroup;	
	CGroup::A_ a;
	using YGroup::B_;
	B_ b;
}
//没有名字的namespace
namespace {
	std::string astring("long"); //相当于　static std::string astirng
}
void testNamespace4() {
	cout << astring; //打印astring
}
//---------------------------------------------------------------
//noexcept
void noexCept() noexcept { //声明确定不会抛出异常,可以减轻编译器压力,利于优化代码.
	std::cout << "hello" << std::endl;
	//std::terminate(); abort(); exit(0);
}
void noexCept2() noexcept(false) { //等价于没写
	std::cout << "hello" << std::endl;
}
//---------------------------------------------------------------
void nullPointer(int *a) {
}
template<typename T, typename U>
void func(T t, U u) {
	t(u);
}
void testNullPointer() {
	//三者直接调用,结果一样
	nullPointer(0);
	nullPointer(NULL); //(void*)0
	nullPointer(nullptr); //std::nullptr_t 在c++11中有专有的类型
	//利用模板函数之后, NULL 模板函数推导为int
	func(nullPointer, nullptr);
	//不能调用　
//	func(nullPointer, NULL);
//	func(nullPointer, 0);
	//若想调用,需要强制转换　
	func(nullPointer, (int*)0);
	func(nullPointer, (int*)NULL);
}
//---------------------------------------------------------------
//operator
struct Operator {
	public:
		Operator(int x) : data(x) { }
//	operator int() const { return this->data; }
	int operator << (Operator const& o) const {
		return data + o.data;
	}
	int operator & () const { return data; }
	private:
	int data;
};
void testOperator() {
	Operator a = 10;
	Operator b = 5;
	Operator c = a << b; //实际实现相加
	cout << &c << endl; //采用去地址符号实现返回里面的值
}
//实例应用:
/*
struct AClass {
	~AClass() { delete m_value}
	AClass() : m_value(new int()) {}
	private:
	int *m_value;
}
void test() {
	Aclass A;
	Aclass B;
	A = B; //这种情况,里面的值m_value,会发生直接赋值,A和B直接指向同一块内存,
	//会发生两次析构,内存会错误.
	
} */
//使用操作符重载 = 来避免:
struct AClass {
	~AClass() { delete m_value;}
	AClass(const AClass& rhs) : m_value(new int(*(rhs.m_value))) {}
	AClass& operator = (const AClass& rhs) {
		*m_value = *(rhs.m_value);
		return *this;
	}
	private:
		int *m_value;
};
//---------------------------------------------------------------
//reinterpret_cast
void testReinterpret_cast() {
	//reinterpret_cast
	//static_cast
	//const_cast
	//dynamic_cast
	//c like cast　可以实现以上的大部分, 而dynamic_cast c语言这种方式不能实现的

	int a = 1;
	// 也相当于 char* p = (char*)&a;
	auto p = reinterpret_cast<char *>(&a); //转化为char*
	//不能char* b = static_cast<char*> &b;
	if(p[0] = 1) {
		std::cout << "the system is little endian\n";
	}else {
		std::cout << "the system is big endian\n";
	}
}
//---------------------------------------------------------------
//sizeof, before c++11
struct SizeofEmpty {};
struct SizeofBase { int a;};
struct SizeofDerived : Base{ int b;};
struct SizeofBit {unsigned bit : 1;};
void testSizeof() {
	SizeofEmpty e;
	SizeofDerived d;
	SizeofBase b;
	SizeofBit bit;
	cout << "sizeof empty: " << sizeof e << endl;
	cout << "sizeof derived: " << sizeof d << endl;
	cout << "sizeof base: " << sizeof(b) << endl;
	cout << "sizeof bit: " << sizeof(SizeofBit) << endl;
//	cout << "szieof void" << sizeof(void) << endl;
//	cout << "szieof int[]" << sizeof(int[]) << endl;
}
//---------------------------------------------------------------
//static
//最好要这么用
static int globalA = 0;
void printInfo() {
	static int localStatic = 0; //多线程不要这么用
	++ localStatic;
	cout << "globalA: " << globalA << " " << "localStatic: " << localStatic << endl;
}
struct Static {
	static int s; //注意: sizeof(Static) == 1, s的空间已经分配
};
int Static::s = 10;

struct HeHe {};
struct Static2 {
	static int a[];
	static HeHe foo;
	static Static2 ss;
};
//对成员进行实例化
int Static2::a[10];
HeHe Static2::foo;
Static2 Static2::ss;

//---------------------------------------------------------------
//static_assert c++11的一个宏, 在编译期进行检测
//assert 是在运行的时候进行检测
void testStaticAssert() {
	static_assert(sizeof(int) == 4, "only work for int of 32bit");
	static_assert(sizeof(long) == sizeof(long long),
			"only work for int of 32bit");
	int a = 5; //判断变量 a == b 采用assert
	int b = 5;
	assert(a != b && "error"); 
}
template<typename T>
void static_assertFun() {
	static_assert(alignof(T) ==4, "only for alignof 4");
}
//---------------------------------------------------------------
//typedef , 换名称
typedef unsigned long ulong;
class Comp {
	typedef std::map<int, ulong> Group;
	Group a; //相当于 std::map<int, ulong> a;
	void aa() {
		//std::map<int, ulong>::iterator iter = a.find(10)
		Group::iterator iter = a.find(10);
		//也可以使用: auto iter = a.fine(10);
	}
};
//---------------------------------------------------------------
//using 
//可以使用与namespace,也可以替换typedef
using newGroup = std::map<int, ulong>;

//using namespace std;

//---------------------------------------------------------------

int main(void) {
//	showAuto();
//	showBitAndOr();
//	showAsm();
//	testAnd_eq();
//	testNot();
//	testNot_eq();
//	testBool();
//	testBreak();
//	testCompl();
//	testConstExpr();
//	testConst_cast();
//	testDecltype();
//	testDynamic_cast();
//	testOldEnum();
//	testNewEnum();
//	testExplicit();
//	testFriend();
//	testGoto();
//	testNamespace4();
//	testOperator();
//	testReinterpret_cast();
//	testSizeof();
	testStaticAssert();

	return 0;
}
