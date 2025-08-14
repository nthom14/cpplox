#pragma once

#include "LoxObject.hpp"
#include <string>

class LoxString : public LoxObject {
private:
    std::string m_value;
public:
    LoxString(const std::string& value);
    ~LoxString() = default;
    LoxString(const LoxString& other) = default;
    LoxString& operator=(const LoxString& rhs) = default;
    LoxString(LoxString&& other) noexcept = default;
    LoxString& operator=(LoxString&& other) noexcept = default;
    std::string toString() override;
};

class LoxDouble : public LoxObject {
private:
    double m_value;
public:
    LoxDouble(const double& value);
    ~LoxDouble() = default;
    LoxDouble(const LoxDouble& other) = default;
    LoxDouble& operator=(const LoxDouble& rhs) = default;
    LoxDouble(LoxDouble&& other) noexcept = default;
    LoxDouble& operator=(LoxDouble&& other) noexcept = default;
    std::string toString() override;
};

