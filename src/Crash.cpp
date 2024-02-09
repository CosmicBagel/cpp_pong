#include "Crash.hpp"

#include <cpptrace/cpptrace.hpp>
#include <csignal>
#include <cstddef>
#include <cstdlib>
#include <iostream>

void stacktrace_and_crash(std::string errorMessage, size_t skip, int exitCode = 1) {
    std::cerr << "Panic!!!" << std::endl;
    std::cerr << errorMessage << std::endl;
    cpptrace::generate_trace(skip).print();

    // using exit (even tho its not thread safe) so that asan still shows
    // memory leaks found after program exits. asan show no info when using std::quick_exit
    // std::quick_exit(exitCode);
    exit(exitCode);
}

void crash_signal_handler(int signal) {
    std::string message;
    switch (signal) {
        case SIGILL:
            message =
                "SIGILL - Illegal instruction (often happens due to bad "
                "CFLAGS)";
            break;
        case SIGABRT:
            message = "SIGABRT - Abort signal (often triggered by assert)";
            break;
        case SIGBUS:
            message =
                "SIGBUS - Bus error (bad memory access) - can happen when "
                "doing I/O with mmap";
            break;
        case SIGFPE:
            message =
                "SIGFPE - Floating-point exception (often happens due to bad "
                "CFLAGS)";
            break;
        case SIGSEGV:
            message = "SIGSEGV - Invalid memory reference (seg-fault)";
            break;
        case SIGSYS:
            message = "SIGSYS - Bad system call";
            break;
        default:
            message = std::format("Unexpected signal: {}", signal);
    }
    stacktrace_and_crash(message, 2, signal);
}

void Crash::SetupSignalHandler() {
    // usually we disable the signal handler if asan is active
#ifndef DISABLE_CRASH_SIGNAL_HANDLER
    std::signal(SIGILL, crash_signal_handler);
    std::signal(SIGABRT, crash_signal_handler);
    std::signal(SIGBUS, crash_signal_handler);
    std::signal(SIGFPE, crash_signal_handler);
    std::signal(SIGSEGV, crash_signal_handler);
    std::signal(SIGSYS, crash_signal_handler);
#endif
}

void Crash::panic(std::string errorMessage) { stacktrace_and_crash(errorMessage, 2); }

void Crash::not_implemented() { stacktrace_and_crash("Method/function not not_implemented", 2); }
