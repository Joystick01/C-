#pragma once

#include <iostream>

struct int2 {
public:
    int x;
    int y;

    int2();

    int2(int x, int y);

    int2 operator+(int2 add);

    int2 operator-(int2 sub);

    void operator+=(int2 add);

    void operator-=(int2 sub);

    int2 operator*(int2 mul);

    int2 operator/(int2 div);

    void operator*=(int2 mul);

    void operator/=(int2 div);

    int2 operator*(int mul);

    int2 operator/(int div);

    void operator*=(int mul);

    void operator/=(int div);
};

std::ostream &operator<<(std::ostream &os, const int2 &int2);