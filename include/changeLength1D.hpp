#ifndef CHANGELENGTH1D_HPP
#define CHANGELENGTH1D_HPP

#include <algorithm>
#include <cmath>

#include "../Exception/Exception.h"

template <typename T>
void changeLength1D(T *&a, int oldLength, int newLength) {
    if (newLength < 0) {
        throw IllegalParameterValue("new length must be >= 0");
    }

    T *temp = new T[newLength];
    int number = std::min(oldLength, newLength);
    std::copy(a, a + number, temp);
    delete[] a;
    a = temp;
}

#endif  // CHANGELENGTH1D_HPP
