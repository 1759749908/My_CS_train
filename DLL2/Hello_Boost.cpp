// File : main.cpp
// 不在 #include <boost/python/...> 之前加上下面的宏定义的话
// 编译器会默认使用 Boost::Python 的动态链接库
#define BOOST_PYTHON_STATIC_LIB

#include <boost/python/module.hpp>
#include <boost/python/def.hpp>


const char* hello_boost() {
    return "Hello Boost::Python!";
}

const char* hello_world() {
    return "Hello World!";
}


// 此处 Hello_Boost 应该与之前设置的目标文件扩展名一致
// 否则想知道后果的话请自行尝试 ╮(╯▽╰)╭
BOOST_PYTHON_MODULE(Hello_Boost) {
    using namespace boost::python;
    def("hello_boost", hello_boost);
    def("hello_world", hello_world);
}