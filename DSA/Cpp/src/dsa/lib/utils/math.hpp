#ifndef DSA_SRC_DSA_LIB_UTILS_MATH_HPP_
#define DSA_SRC_DSA_LIB_UTILS_MATH_HPP_

#include <dsa/config.h>

namespace dsa {

INTERN CONSTEXPR
bool isOdd(int x) { return ((x & 1) == 1); }

INTERN CONSTEXPR UNUSED
bool isEven(int x) { return ((x & 1) == 0); }

}
#endif //DSA_SRC_DSA_LIB_UTILS_MATH_HPP_
