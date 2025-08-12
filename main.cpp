#include <filesystem>
#include <iostream>
#include <string>

#include "Lox.hpp"

int main(int argc, char* argv[]) {
    if (argc > 2) {
        std::cout << "Invalid number of arguments: " << argc << '\n';
        std::cout << "Usage: lox [script]" << '\n';
        return 1;
    }
    if (argc == 2) {
        std::cout << "runFile()" << '\n';
        Lox::runFile(std::string(argv[1]));
    }
    else if (argc == 1) {
        Lox::runPrompt();
    }
    return 0;
}
