#include "Scanner.hpp"

std::map<std::string, TokenType> Scanner::keywords {
    {"and", AND},
    {"class", CLASS},
    {"else", ELSE},
    {"false", FALSE},
    {"for", FOR},
    {"fun", FUN},
    {"if", IF},
    {"nil", NIL},
    {"or", OR},
    {"print", PRINT},
    {"return", RETURN},
    {"super", SUPER},
    {"this", THIS},
    {"true", TRUE},
    {"var", VAR},
    {"while", WHILE}
};

Scanner::Scanner(const std::string& code_source) : source(code_source){

}
bool Scanner::isAtEnd() {
    return current >= source.size();
}
std::list<Token> & Scanner::scanTokens()
{
    while (!isAtEnd()) {
        start = current;
        scanToken();
    }
    //tokens.push_back(Token(EOF, std::string(""), nullptr, line));
    return tokens;
    //return std::list<Token>();
}
void Scanner::scanToken()
{
    char ch = advance();
    switch (ch) {
        case '(':
            addToken(LEFT_PAREN);
            break;
        case ')':
            addToken(RIGHT_PAREN);
            break;
        case '{':
            addToken(LEFT_BRACE);
            break;
        case '}':
            addToken(RIGHT_BRACE);
            break;
        case ',':
            addToken(COMMA);
            break;
        case '.':
            addToken(DOT);
            break;
        case '-':
            addToken(MINUS);
            break;
        case '+':
            addToken(PLUS);
            break;
        case ';':
            addToken(SEMICOLON);
            break;
        case '*':
            addToken(STAR);
            break;
        case '!':
            addToken(match('=') ? BANG_EQUAL : BANG);
            break;
        case '=':
            addToken(match('=') ? EQUAL_EQUAL : EQUAL);
            break;
        case '<':
            addToken(match('=') ? LESS_EQUAL : LESS);
            break;
        case '>':
            addToken(match('=') ? GREATER_EQUAL : GREATER);
            break;
        case '/':
            if (match('/')) {
                while (peek() != '\n' && !isAtEnd()) {
                    advance();
                }
            }
            else if (match('*')) {
                //multilineComment();
            }
            else {
                addToken(SLASH);
            }
            break;
        case ' ':
        case '\t':
        case '\r':
            break;
        case '\n':
            line++;
            break;
        case '"':
            string();
            break;
        default:
            ;
    }
    return;
}
char Scanner::advance() {
    ++current;
    return source[current - 1];
}
void Scanner::addToken(TokenType type)
{
    addToken(type, nullptr);
}
void Scanner::addToken(TokenType type, LoxObject* literal)
{
    std::string text = source.substr(start, current);
    tokens.push_back(Token(type, text, literal, line));
}
bool Scanner::match(char expected)
{
    if (isAtEnd()) {
        return false;
    }
    if (source[current] != expected) {
        return false;
    }
    ++current;
    return true;
}
char Scanner::peek() {
    if (isAtEnd()) {
        return '\0';
    }
    return source[current];
}
void Scanner::multilineComment() {
    //TODO
    /*while (peek() != '*' && !isAtEnd()) {
        if (peek() == '\n') {
            line++;
        }
        advance();
    }
    if (isAtEnd()) {
        Lox.error(line, "Unterminated comment.");
    }
    else if (peekNext() != '/') {
        Lox.error(line, "Unterminated comment.");
    }
    else {
        advance();
    }*/
}
void Scanner::string() {
    //TODO
    /*char ch = peek();
    while (ch != '"' && !isAtEnd()) {
        if (ch == '\n') {
            line++;
        }
        advance();
        ch = peek();
    }
    if (isAtEnd()) {
        Lox.error(line, "Unterminated string.");
        return;
    }
    advance();
    String value = source.substr(start + 1, current - 1);
    addToken(STRING, value);*/
    return;
}
//=============================================================================
// //TODO
//default:
//    if (isDigit(c)) {
//        number();
//    }
//    else if (isAlpha(c)) {
//        identifier();
//    }
//    else {
//        Lox.error(line, "Unexpected character.");
//    }
//}
//=============================================================================

