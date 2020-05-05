#include <vector>
#include <iostream>
#include <A.h>
#include <B.h>
#include <C.h>
#include <D.h>
#include <E.h>

class E;
class Good : public A, private B {
	public:
		Good(const C&);
		~Good();
		B handle(int);
		C action(int, int);
		C& getC(int);
		E caculate(int);
		virtual std::ostream& print(std::ostream& s) const; //came fom A
	private:
		std::vector<C> m_cGroup;
		D m_dObject;
}

/*
	A, B, C, D不可以采用前置声明来避免类的实例, E可以 
 */

