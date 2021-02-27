#ifndef DSA_LIB_UTILS_HPP
#define DSA_LIB_UTILS_HPP

#include "dsa/dsadef.h"

namespace dsa::lib::utils {

/**
 * Remove all the trailing 0s from an array
 * Rule:
 * 1. array length is 0 -> return empty array
 * 2. array length is 1, the element is 0 -> return empty array
 * 3. array last element is not 0 -> return array
 * 4. array length is bigger than 1, last element is 0 -> remove the trailing 0s by loop
 */
static length_t arrayRstrip(const int *ary, const length_t length) {
    if (!length || (length == 1 && *(ary) == 0)) return 0;
    if (*(ary + (length - 1)) != 0) return length;

    auto newLength = length - 1;
    while (newLength > 0 && *(ary + (newLength - 1)) == 0) --newLength;
    return newLength;
}

template<typename T>
static void arraycopy(const T *ary, pos_t srcPos, T *des, pos_t desPos, length_t length) {
    for (int i = 0; i < length; ++i) {
        des[desPos + i] = ary[srcPos + i];
    }
}

template<typename T>
static void vectorcopy(const std::vector<T> &src, pos_t srcPos, std::vector<T> &des, pos_t desPos, length_t length) {
    for (int i = 0; i < length; ++i) {
        des[desPos + i] = src[srcPos + i];
    }
}

template<typename T>
static void arraySwap(T *ary, pos_t i, pos_t j) {
    int tmp = ary[i];
    ary[i] = ary[j];
    ary[j] = tmp;
}
}  // namespace dsa

#endif