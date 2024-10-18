#include "Vect2.h"
#include <iostream>

Vector2::Vector2() : x(0), y(0) {

}

Vector2::Vector2(float x, float y) : x(x), y(y) {
    return x, y;
}

Vector2& Vector2::operator+=(const Vector2& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2 Vector2::operator+(const Vector2& other) const {
    return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator*(float scalar) const {
    return Vector2(x * scalar, y * scalar);
}