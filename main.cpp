#include <filesystem>
#include <iostream>
#include <string>

#include "Scanner.hpp"

using std::cout;
using std::endl;

void runFile(const std::string& path);
void runPrompt();
void run(const std::string& source);

int main(int argc, char* argv[]) {
    if (argc > 2) {
        std::cout << "Invalid number of arguments: " << argc << '\n';
        std::cout << "Usage: lox [script]" << '\n';
        return 1;
    }
    else if (argc == 2) {
        std::cout << "runFile()" << '\n';
    }
    else if (argc == 1) {
        runPrompt();
    }
    return 0;
}

void runFile(const std::string& path) {

}
void runPrompt() {
    std::cout << "Running lox in REPL mode. Press CTRL-C to exit..." << '\n';
    std::string line("");
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, line);
        run(line);
    }
}
void run(const std::string& source) {
    std::cout << "source code: " << source << '\n';
    Scanner scanner(source);
    std::list<Token> & tokens = scanner.scanTokens();

    for (Token token : tokens) {
        std::cout << token.toString() << '\n';
    }
    
}
