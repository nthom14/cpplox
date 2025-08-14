#pragma once

#include <string>

class Lox {
public:
    static bool hadError;
    static void runFile(const std::string& path);
    static void runPrompt();
    static void run(const std::string& source);
    static void error(size_t line, const std::string& message);
    static void report(size_t line, const std::string& where, const std::string& message);
};
