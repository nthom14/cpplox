#pragma once

#include <string>

class Lox {
public:
    static void runFile(const std::string& path);
    static void runPrompt();
    static void run(const std::string& source);
};
