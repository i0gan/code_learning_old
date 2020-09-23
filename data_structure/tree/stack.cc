#include<iostream>
#include<initializer_list>

template<class T>
struct s_value {
	T value_;
	s_value<T> *next_;
};

template<class T>
class stack {
public:
	stack() {}
	~stack() {}
	inline void push(const T &t) {
		length_ ++;
		s_value<T> *t_v = value_;
		while(value_) {
			t_v = value_->next_;	
		}
		t_v = new s_value<T>;	
		t_v->value_ = t;
		t_v->next_  = nullptr;
	}
	inline void pop() {
		
	}
	inline T get_top() {
		
	}
	inline bool empty() {
		return length_ == 0;	
	}
	inline void print_all() {
		s_value<T> *t;
		t = value_;
		while(t) {
			std::cout << t->value_;	
			t = t->next_;
		}
	}

private:
	int length_ = 0;
	s_value<T> *value_ = nullptr;
};

int main(int, char**) {
	stack<int> a;
	a.push(1);
	a.push(1);
	a.push(4);
	a.push(2);
	a.print_all();
	return 0;
}
