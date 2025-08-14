#include "Token.hpp"
#include <sstream>

Token::Token(const TokenType& type, const std::string& lexeme, const LoxObject* literal, size_t line)
    : m_type(type)
    , m_lexeme(lexeme)
    , m_literal(std::make_unique<LoxObject>(*literal))
    , m_line(line)
{

}

Token::Token(const Token& other)
    : m_type(other.m_type)
    , m_lexeme(other.m_lexeme)
    , m_literal(std::make_unique<LoxObject>(*other.m_literal))
    , m_line(other.m_line)
{
}
Token& Token::operator=(const Token& rhs) {
    if (this != &rhs) {
        m_type = rhs.m_type;
        m_lexeme = rhs.m_lexeme;
        m_literal = std::make_unique<LoxObject>(*rhs.m_literal);
        m_line = rhs.m_line;
    }
    return *this;
}
void Token::setLiteral(std::unique_ptr<LoxObject> u_ptr_loxObject)
{
    m_literal = std::move(u_ptr_loxObject);
}
std::string Token::toString() const
{
    std::ostringstream oss;
    oss << TokenTypeToStringMap[m_type] << " " << m_lexeme << " " << (m_literal != nullptr ? m_literal->toString() : "nullptr");
    return oss.str();
}
