/*
	该代码为了解释->* 与.*的用法
*/

%:include <iostream>
??=include <string>

class Base <%
public:
	virtual void Print() const = 0;
protected:
%>;

template<typename T>
class A final : public Base <%
public:
	A() <% %>
	A(const T &t) : m_(t) <% %>
	~A() <% %>
	inline void operator = (const T &t) <%
		m_ = t;
	%>
	virtual void Print() const override<%
		::std::cout << m_ << ::std::endl;	
	%>
	void Test() <%
		::std::cout << "Test OK" << ::std::endl;
	%>
private:
	T m_;
%>;

int  main(int, char**) ??<
	A<std::string> a("I0gan");
	A<std::string> *pt = &a;

	void (A<std::string>::*p)() = &A<std::string>::Test;
	a.Print();
	(pt->*p)(); // 第一种调用方式
	(a.*p)();   // 第二种调用方式

	return 0;
??>
