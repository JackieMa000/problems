#pragma once

#include <dsa/config.h>

namespace dsa {

template<class T>
struct equal {
    T val;

    explicit equal(T val) : val(val) {}

    CONSTEXPR
    bool operator()(T x) const {
        return x == val;
    }
};

//Compare the size of two objects. They should have size() method.
template<class T1, class T2>
struct lessSize {
    CONSTEXPR
    bool operator()(T1 &x, T2 &y) const {
        return x.size() < y.size();
    }
};

}
