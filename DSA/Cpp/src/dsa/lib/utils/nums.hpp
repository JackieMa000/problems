#ifndef DSA_SRC_DSA_LIB_UTILS_NUMS_HPP_
#define DSA_SRC_DSA_LIB_UTILS_NUMS_HPP_

namespace dsa::nums {

static int lastDigitOf(int num) {
    return num % 10;
}

static int placeValueOf(int num, int place) {
    return lastDigitOf(num / place);
}

}

#endif //DSA_SRC_DSA_LIB_UTILS_NUMS_HPP_
