#ifndef DSA_SRC_DSA_LIB_UTILS_MATH_H_
#define DSA_SRC_DSA_LIB_UTILS_MATH_H_

#include <dsa/config.h>

namespace dsa {

INTERN
bool isOdd(int x) { return ((x & 1) == 1); }

INTERN UNUSED
bool isEven(int x) { return ((x & 1) == 0); }

struct equal {
    explicit equal(int val) : val(val) {}
    bool operator()(int x) const {
        return x == val;
    }
    int val;
};

}
#endif //DSA_SRC_DSA_LIB_UTILS_MATH_H_
