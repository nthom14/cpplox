#pragma once

#include <memory>
#include <string>
#include "TokenType.hpp"
#include "LoxObject.hpp"

class Token
{
private:
    TokenType m_type;
    std::string m_lexeme;
    std::unique_ptr<LoxObject> m_literal;
    size_t m_line;
public:
    Token(const TokenType& type, const std::string& lexeme, const LoxObject* literal, size_t line);
    Token(const Token& other);
    Token& operator=(const Token& rhs);
    std::string toString();
};

//final TokenType type;
//final String lexeme;
//final Object literal;
//final int line;
//
//Token(TokenType type, String lexeme, Object literal, int line) {
//    this.type = type;
//    this.lexeme = lexeme;
//    this.literal = literal;
//    this.line = line;
//}
//
//public String toString() {
//    return type + " " + lexeme + " " + literal;
//}