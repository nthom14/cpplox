#pragma once

#include <list>
#include <map>
#include <string>
#include "TokenType.hpp"
#include "Token.hpp"

class Scanner
{
private:
    static std::map<std::string, TokenType> keywords;
    const std::string source;
    std::list<Token> tokens;
    size_t start = 0;
    size_t current = 0;
    size_t line = 1;
    bool isAtEnd();
    void scanToken();
    char advance();
    void addToken(TokenType type);
    void addToken(TokenType type, LoxObject* literal);
    bool match(char expected);
    char peek();
    void multilineComment();
    void string();
public:
    Scanner(const std::string& code_source);
    Scanner(const Scanner& rhs) = delete;
    Scanner(Scanner&& rhs) = delete;
    Scanner& operator=(const Scanner& rhs) = delete;
    Scanner& operator=(Scanner&& rhs) = delete;
    std::list<Token>& scanTokens();
};

