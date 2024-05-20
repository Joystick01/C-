#include "int2.h"

int2::int2() : x(0), y(0) {

}

int2::int2(const int x, const int y) : x(x), y(y) {

}

int2 int2::operator+(const int2 add) {
    return {add.x + x, add.y + y};
}

int2 int2::operator-(int2 sub) {
    return {x - sub.x, y - sub.y};
}

void int2::operator+=(int2 add) {
    this->x += add.x;
    this->y += add.y;
}

void int2::operator-=(int2 sub) {
    this->x -= sub.x;
    this->y -= sub.y;
}

int2 int2::operator*(int2 mul) {
    return {x * mul.x, y * mul.y};
}

int2 int2::operator/(int2 div) {
    return {x / div.x, y / div.y};
}

void int2::operator*=(int2 mul) {
    this->x *= mul.x;
    this->y *= mul.y;
}

void int2::operator/=(int2 div) {
    this->x /= div.x;
    this->y /= div.y;
}

int2 int2::operator*(int mul) {
    return {x * mul, y * mul};
}

int2 int2::operator/(int div) {
    return {x / div, y / div};
}

void int2::operator*=(int mul) {
    this->x *= mul;
    this->y *= mul;
}

void int2::operator/=(int div) {
    this->x /= div;
    this->y /= div;
}

std::ostream &operator<<(std::ostream &os, const int2 &int2) {
    return os << '(' << int2.x << '|' << int2.y << ')';
}
