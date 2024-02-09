#pragma once
#include <string>
class Crash {
   public:
    static void SetupSignalHandler();
    static void panic(std::string errorMessage);
    static void not_implemented();
};
