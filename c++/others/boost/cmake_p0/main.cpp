#include <boost/thread/thread.hpp>
#include <iostream>
// cd build && cmake .. && make
void task1() {
    for (int i = 0; i < 10; ++i) {
        std::cout << "task1 doing: " << i << '\n';
    }
}

int main() {
    std::cout << "hello world!\n";
    boost::thread thr = boost::thread(task1);
    thr.join();
    return EXIT_SUCCESS;
}