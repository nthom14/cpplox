#pragma once

#include <map>

enum TokenType {
    // Single-character tokens.
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

    // One or two character tokens.
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,

    // Literals.
    IDENTIFIER, STRING, NUMBER,

    // Keywords.
    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,
    LOXEOF
};

static std::map<TokenType, std::string> TokenTypeToStringMap {
    // Single-character tokens.
    {LEFT_PAREN, std::string("LEFT_PAREN")},
    {RIGHT_PAREN, std::string("RIGHT_PAREN")},
    {LEFT_BRACE, std::string("LEFT_BRACE")},
    {RIGHT_BRACE, std::string("RIGHT_BRACE")},
    {COMMA, std::string("COMMA")},
    {DOT, std::string("DOT")},
    {MINUS, std::string("MINUS")},
    {PLUS, std::string("PLUS")},
    {SEMICOLON, std::string("SEMICOLON")},
    {SLASH, std::string("SLASH")},
    {STAR, std::string("STAR")},

    // One or two character tokens.
    {BANG, std::string("BANG")},
    {BANG_EQUAL, std::string("BANG_EQUAL")},
    {EQUAL, std::string("EQUAL")},
    {EQUAL_EQUAL, std::string("EQUAL_EQUAL")},
    {GREATER, std::string("GREATER")},
    {GREATER_EQUAL, std::string("GREATER_EQUAL")},
    {LESS, std::string("LESS")},
    {LESS_EQUAL, std::string("LESS_EQUAL")},
    
    // Literals.
    {IDENTIFIER, std::string("IDENTIFIER")},
    {STRING, std::string("STRING")},
    {NUMBER, std::string("NUMBER")},

    // Keywords.
    {AND, std::string("AND")},
    {CLASS, std::string("CLASS")},
    {ELSE, std::string("ELSE")},
    {FALSE, std::string("FALSE")},
    {FUN, std::string("FUN")},
    {FOR, std::string("FOR")},
    {IF, std::string("IF")},
    {NIL, std::string("NIL")},
    {OR, std::string("OR")},
    {PRINT, std::string("PRINT")},
    {RETURN, std::string("RETURN")},
    {SUPER, std::string("SUPER")},
    {THIS, std::string("THIS")},
    {TRUE, std::string("TRUE")},
    {VAR, std::string("VAR")},
    {WHILE, std::string("WHILE")},
    {LOXEOF, std::string("LOXEOF")}
};