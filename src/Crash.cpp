#include "Crash.hpp"

#include <cpptrace/cpptrace.hpp>
#include <cstdlib>
#include <iostream>

void Crash::panic(std::string errorMessage) {
    std::cerr << "Panic!!!" << std::endl;
    std::cerr << errorMessage << std::endl;
    cpptrace::generate_trace().print();
    std::quick_exit(1);
}

void Crash::not_implemented() {
    Crash::panic("Method/function not not_implemented");
}
