#include <iostream>
using namespace std;
//MyVector
template <typename T>
class MyVector {
public:
	typedef T value;
	typedef T *viter;

protected:
	viter m_Data; //The pointer of array
	int m_nLen;   //The length of array
	viter start;  //The start of array
	int finish;   
	int end_of_element;
public:
	MyVector(int nLen=0) : m_nLen(nLen), m_Data(NULL), finish(0) {
		if(nLen > 0) {
			m_Data = new T[nLen];
			start = m_Data;
			end_of_element = nLen;
		}
	}
	~MyVector() {
		delete[] m_Data;
	}

	void push_back(const value &x) {
		if(end_of_element != finish) {
			*(start + finish) = x;
			++finish;
		}else {
			cout << "out of array!" << endl;
		}
	}
	inline value pop_back() {
		--finish;
		return *(start + finish);
	}
	value operator[](int n) {
		if(n == finish || n < finish) {
			return *(start + n);
		}else {
			cout << "Num error!" << endl;
			return -1;
		}
	}

		
};
int main(void) {
	MyVector<int> vec(20);
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	vec.pop_back();
	vec.pop_back();
	vec.pop_back();

	cout << vec[0];
	cout << vec[1];
	cout << vec[2];
}
