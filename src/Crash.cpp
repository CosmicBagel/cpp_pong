#include "Crash.hpp"

#include <cpptrace/cpptrace.hpp>
#include <cstddef>
#include <cstdlib>
#include <iostream>

void stacktrace_and_crash(std::string errorMessage, size_t skip) {
    std::cerr << "Panic!!!" << std::endl;
    std::cerr << errorMessage << std::endl;
    cpptrace::generate_trace(skip).print();
    std::quick_exit(1);
}

void Crash::panic(std::string errorMessage) {
    stacktrace_and_crash(errorMessage, 2);
}

void Crash::not_implemented() {
    stacktrace_and_crash("Method/function not not_implemented", 2);
}
