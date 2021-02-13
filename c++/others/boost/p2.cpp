#include <boost/python.hpp>
#include <iostream>

struct StructionData {
    void hello() {
        std::cout << "hello, this is boost::python sample!\n";
    }
    void msg() {
        std::cout << "print msg!\n";
    }
};

BOOST_PYTHON_MODULE(Boost_Python_Sqmple) { //为静态编译
    boost::python::class<StructionData>("StructionData")
    .def("hello", &StructionData::hello)
    .def("msg", &StructionData::msg);
}
