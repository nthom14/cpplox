#include "Scanner.hpp"
#include "LoxTypes.hpp"
#include "Lox.hpp"
#include <stdexcept>

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

Scanner::Scanner(const std::string& code_source) 
    : source(code_source)
    , tokens()
    , start(0)
    , current(0)
    , line(1) {
}
bool Scanner::isAtEnd() {
    return (current >= source.size());
}
std::list<std::unique_ptr<Token>> & Scanner::scanTokens()
{
    while (!isAtEnd()) {
        start = current;
        scanToken();
    }
    //tokens.push_back(Token(EOF, std::string(""), nullptr, line));
    return tokens;
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
                multilineComment();
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
            if (isDigit(ch)) {
                number();
            }
            else if (isAlpha(ch)) {
                identifier();
            }
            else {
                Lox::error(line, "Unexpected character.");
            }
    }
    return;
}
char Scanner::advance() {
    current++;
    return source[current - 1];
}
void Scanner::addToken(TokenType type)
{
    addToken(type, nullptr);
}
void Scanner::addToken(TokenType type, LoxObject* literal)
{
    std::string text = source.substr(start, current-start);
    tokens.push_back(std::make_unique<Token>(Token(type, text, literal, line)));
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
    while (peek() != '*' && !isAtEnd()) {
        if (peek() == '\n') {
            line++;
        }
        advance();
    }
    if (isAtEnd()) {
        Lox::error(line, "Unterminated /* comment - no * is found.");
    } else if (peekNext() != '/') {
        Lox::error(line, "Unterminated /* comment - no / is found.");
    } else {
        advance();
    }
}
void Scanner::string() {
    char ch = peek();
    while (ch != '"' && !isAtEnd()) {
        if (ch == '\n') {
            line++;
        }
        advance();
        ch = peek();
    }
    if (isAtEnd()) {
        Lox::error(line, "Unterminated string.");
        return;
    }
    advance();
    addToken(STRING, nullptr);
    std::string strval = source.substr(start + 1, current - start - 2);
    tokens.back()->setLiteral(std::make_unique<LoxString>(strval));
    return;
}
bool Scanner::isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}
bool Scanner::isAlpha(char ch)
{
    return ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch == '_';
}
void Scanner::number()
{
    while (isDigit(peek())) {
        advance();
    }
    if (peek() == '.' && isDigit(peekNext())) {
        // consume '.' and continue scanning after the '.' character.
        advance();
        while (isDigit(peek())) {
            advance();
        }
    }
    try {
        std::string val_str = source.substr(start, current - start);
        double double_val = std::stod(val_str);
        addToken(NUMBER, nullptr);
        tokens.back()->setLiteral(std::make_unique<LoxDouble>(double_val));
    }
    catch (std::out_of_range& oor) {
        Lox::error(line, "double value out of range");
    }
    catch (std::invalid_argument& ia) {
        Lox::error(line, "invalid argument for double value conversion");
    }
}
char Scanner::peekNext()
{
    if (current + 1 >= source.length()) {
        return '\0';
    }
    return source[current + 1];
}
void Scanner::identifier() {
    while (isAlphaNumeric(peek())) {
        advance();
    }
    TokenType type = IDENTIFIER;
    std::string text = source.substr(start, current - start);
    const auto it = keywords.find(text);
    if (it != std::cend(keywords)) {
        type = it->second;
    }
    addToken(type);
}
bool Scanner::isAlphaNumeric(char ch) {
    return isAlpha(ch) || isDigit(ch);
}


