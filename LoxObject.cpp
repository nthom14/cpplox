#include "LoxObject.hpp"

LoxObject::LoxObject() {

}
LoxObject::~LoxObject() {

}
LoxObject::LoxObject(const LoxObject& other) {

}
LoxObject& LoxObject::operator=(const LoxObject& rhs) {
    if (this != &rhs) {

    }
    return *this;
}
LoxObject::LoxObject(LoxObject&& other) noexcept {

}
LoxObject& LoxObject::operator=(LoxObject&& rhs) noexcept {
    if (this != &rhs) {

    }
    return *this;
}