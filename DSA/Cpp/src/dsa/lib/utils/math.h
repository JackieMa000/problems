#ifndef DSA_SRC_DSA_LIB_UTILS_MATH_H_
#define DSA_SRC_DSA_LIB_UTILS_MATH_H_

#include <dsa/config.h>

namespace dsa {

INTERN CONSTEXPR
bool isOdd(int x) { return ((x & 1) == 1); }

INTERN CONSTEXPR UNUSED
bool isEven(int x) { return ((x & 1) == 0); }

struct equal {
    int val;

    explicit equal(int val) : val(val) {}

    CONSTEXPR
    bool operator()(int x) const {
        return x == val;
    }
};

}
#endif //DSA_SRC_DSA_LIB_UTILS_MATH_H_
