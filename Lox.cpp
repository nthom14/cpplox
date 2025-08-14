#include "Lox.hpp"
#include <iostream>
#include <string>
#include "Scanner.hpp"

bool Lox::hadError = false;

void Lox::runFile(const std::string& path) {

}
void Lox::runPrompt() {
    std::cout << "Running lox in REPL mode. Press CTRL-C to exit..." << '\n';
    std::string line("");
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, line);
        run(line);
    }
}
void Lox::run(const std::string& source) {
    std::cout << "source code: " << source << '\n';
    Scanner scanner(source);
    std::list<std::unique_ptr<Token>>& tokens = scanner.scanTokens();

    for (const auto & token : tokens) {
        std::cout << token->toString() << '\n';
    }
}
void Lox::error(size_t line, const std::string& message)
{
    report(line, "", message);
}
void Lox::report(size_t line, const std::string& where, const std::string& message)
{
    std::cerr << "[line " << line << "] Error" << where << ": " << message << '\n';
    hadError = true;
}
