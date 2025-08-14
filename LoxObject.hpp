#pragma once 

#include <string>

class LoxObject {
public:
    LoxObject();
    virtual ~LoxObject();
    LoxObject(const LoxObject& other);
    LoxObject& operator=(const LoxObject& rhs);
    LoxObject(LoxObject&& other) noexcept;
    LoxObject& operator=(LoxObject&& rhs) noexcept;
    virtual std::string toString();
};