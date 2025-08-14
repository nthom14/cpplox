#include "LoxTypes.hpp"
#include <sstream>

LoxString::LoxString(const std::string& value) : LoxObject(), m_value(value)
{
}
std::string LoxString::toString()
{
    return m_value;
}

LoxDouble::LoxDouble(const double& value) : LoxObject(), m_value(value)
{
}

std::string LoxDouble::toString()
{
    std::ostringstream oss;
    oss << m_value;
    return oss.str();
}
