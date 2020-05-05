#include <iostream>
using namespace std;

void operator_1(void);
void operator_2(void);
void operator_3(void);
int main(void) {

	/*
	-x = ~x+1 = ~(x-1)
	~x = -x-1
	-(~x) = x+1
	~(-x) = x-1


	x+y = x - ~y-1 = (x|y) + (x&y)
	x-y = x + ~y+1 = (x|~y) - (~x&y)
	x^y = (x|y) - (x&y)
	x|y = (x& ~y) + y
	x&y = (~x|y) - ~x


	x==y :  ~(x-y|y-x)
	x!=y :  x-y|y-x
	x<y  :  (x-y) ^ ((x^y) & ((x-y) ^x))
	x<=y :  (x|~y) & ((x^y) | ~(y-x))
	x<y  :  (~x&y) | ((~x|y) & (x-y))   //unsigned
	x<=y :  (~x|y) & ((x^y) | ~(y-x))   //unsigned

	*/
	operator_1();
	operator_2();
	operator_3();
	return 0;
}
void operator_1(void) {
	int x = 1;
	cout << "-x = " << -x << "   ~x+1 = " << ~x + 1 << endl;
	cout << "~x = " << ~x << "   -x-1 = " << -x - 1 << endl;
	cout << "-(~x) = "<< -(~x) << "   x+1 = " << x + 1 << endl;
	cout << "-(~x) = "<< -(~x) << "   x-1 = " << -x -1 << endl;
}
void operator_2(void) {
	int x = 3, y = 5;
	cout << endl;
	cout << "x: " << x << "y: " << y << endl;
	cout << "x+y=" << x+y << "   x- ~y-1= " << x - ~y - 1
	<< "  (x|y)+(x&y) = " << (x|y) + (x&y) << endl;
	cout << "x-y=" << x-y << "   x+ ~y+1= " << x + ~y + 1
	<< "  (x|~y) - (~x&y) = " << (x|~y) - (~x|y) << endl;

	cout << "x^y=" << (x^y) << " (x|y) - (x&y)" << (x|y) - (x&y) << endl;
	cout << "x|y=" << (x|y) << " (x& ~y) + y = " << (x& ~y) + y << endl;
	cout << "x&y=" << (x&y) << " (~x|y) - ~x = " << (~x|y) - ~x << endl;
}
void operator_3(void) {
	int x = -3, y = -5;	
	unsigned int x_t = -1, y_t = -5;
	cout << "x: " << x << "y: " << y << endl;
	cout << "x==y =" << (x==y) << "  ~(x-y|y-x) =" << ~(x-y|y-x) << endl;
	cout << "x!=y =" << (x!=y) << "  x-y|y-x =" << (x-y|y-x) << endl;
	cout << "x<y =" << (x<y) << "  (x-y) ^ ((x^y) & ((x-y)^x))=" << ((x-y) ^ ((x^y) & ((x-y)^x))) << endl;
	cout << "x<=y =" << (x<=y) << "  (x|~y) & ((x^y) |~ (y-x))=" << ((x|~y) & ((x^y) |~ (y-x))) << endl;
	cout << "unsigned: x<y =" << (x_t<y_t)
	<< "  (~x&y) | ((~x|y) & (x-y))" << ((~x_t&y_t) | ((~x_t|y_t) & (x_t-y_t))) << endl;

	cout << "unsigned: x<=y =" << (x_t<=y_t)
	<< " (~x|y) & ((x^y) | ~(y-x) =" << ((~x_t|y_t) & ((x_t^y_t) |~ (y_t-x_t))) << endl;

}
