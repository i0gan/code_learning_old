#include <atomic>
#include <thread>
#include <mutex>
#include <iostream>
void atomic_type() {
	::std::atomic_char a;  // char
	::std::atomic_schar b; // signed char
	::std::atomic_uchar c; // unsigned char
	::std::atomic_short d; // short
	::std::atomic_ushort e;// unsigned short
	::std::atomic_int f;
	::std::atomic_uint g;
	::std::atomic_long h;
	::std::atomic_ulong i;
	::std::atomic_llong j; // long long
	::std::atomic_ullong k;
	::std::atomic_char16_t l; // char16_t
	::std::atomic_char32_t m; // char32_t
	::std::atomic_wchar_t nn;  // wchar_t

	//atoimic_int_least8_t dd;
}

::std::atomic<int> a_num(0);
::std::mutex mu;
int num(0);
void v_add() {
	for(int i = 0; i < 10000000; ++i)
		++num;
}
void a_add() {
	for(int i = 0; i < 10000000; ++i)
		++a_num;
}
void l_add() {
	for(int i = 0; i < 10000000; ++i) {
		mu.lock();	
		++num;
		mu.unlock();
	}
}

void test_atomic_add() {
	clock_t start_clock = std::clock();	
	std::thread t1(a_add);
	std::thread t2(a_add);
	std::thread t3(a_add);
	t1.join();
	t2.join();
	t3.join();
	clock_t end_clock = std::clock();
	std::cout << "atomic\n";
	std::cout << "time: " << end_clock - start_clock << " " << CLOCKS_PER_SEC << " num: " << a_num << std::endl;
}
void test_lock_add() {
	clock_t start_clock = std::clock();	
	std::thread t1(l_add);
	std::thread t2(l_add);
	std::thread t3(l_add);
	t1.join();
	t2.join();
	t3.join();
	clock_t end_clock = std::clock();
	std::cout << "mutex lock\n";
	std::cout << "time: " << end_clock - start_clock << " " << CLOCKS_PER_SEC << " num: " << a_num << std::endl;
}

void test_void_add() {
	clock_t start_clock = std::clock();	
	std::thread t1(v_add);
	std::thread t2(v_add);
	std::thread t3(v_add);
	t1.join();
	t2.join();
	t3.join();
	clock_t end_clock = std::clock();
	std::cout << "void add\n";
	std::cout << "time: " << end_clock - start_clock << " unit: " << CLOCKS_PER_SEC << " num: " << a_num << std::endl;
}


::std::atomic<int64_t> value(0);
void atomic_operator() {
	value ++;
	// 读取变量
	int64_t x = value.load(std::memory_order_relaxed);
	std::cout << x << std::endl;
	x = 10;
	// 更新变量
	value.store(x, std::memory_order_relaxed);
	std::cout << x << std::endl;
}

int main(void) {
	//test_atomic_add();	
	//test_void_add();
	//test_lock_add();
	atomic_operator();
	return 0;
}

