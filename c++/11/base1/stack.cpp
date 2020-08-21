#include <cassert>
#include <stdexcept>
#include <iostream>
template <typename T>
class Stack {
	public:
		//是不是异常安全的呢?
		Stack() : m_data(0), m_capacity(20), m_used(0) { m_data = new T[m_capacity];}
		//是不是异常安全的呢?
		~Stack() { delete[] m_data;}
		//exception safe?
		int size() const { return m_used; }
		//push object exception safe?
		void push(const T& t) {
			if(m_used >= m_capacity) {
				T *data = newCopy(m_data, m_capacity, m_capacity * 2);
				delete[] m_data;
				m_data = data;
				m_capacity *= 2;
			}
			//the next to line can change to m_data[++m_used] = t;
			m_data[m_used] = t;
			++m_used;
		}
		//we have bad news for this version
		T pop() {
			if(m_used == 0) {
				throw std::runtime_error("empty, bad1 ");	
			}	
			T obj = m_data[m_used - 1];
			--m_used;
			return obj;
		}

		//we have bad news for this version
		void pop(T &object) {
			if(m_used == 0) {
				throw std::runtime_error("empty, bad2 ");	
			}
			object = m_data[m_used - 1];
			--m_used;
		}
		//wel have bad news for this version ????? not so bad
		T& top() {
			if(m_used == 0) {
				throw std::runtime_error("empty, bad3 ");
			}
			return m_data[m_used - 1];
		}
		
		void popTop() {
			if(m_used == 0) {
				throw std::runtime_error("empty, bad4 ");
			}
			--m_used;
		}
	private:
		T* m_data;
		int m_capacity;
		int m_used;
		T* newCopy(const T* old, int oldSize, int newSize) {
			assert(newSize > oldSize);
			T* data = new T[newSize];
			try {
				std::copy( old, old + oldSize, data);	
			}catch(...) {
				delete[] data;	
			}
		}
};
void testStack() {
	Stack<int> s;	
	for(int i = 0; i < 21; i++) {
		s.push(1);	
	}
}
int main(void) {
	testStack();
	return 0;
}
