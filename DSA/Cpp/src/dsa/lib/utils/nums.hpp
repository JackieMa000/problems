#ifndef DSA_SRC_DSA_LIB_UTILS_NUMS_HPP_
#define DSA_SRC_DSA_LIB_UTILS_NUMS_HPP_

#include <dsa/config.h>
namespace dsa::nums {

INTERN CONSTEXPR
int lastDigitOf(int num) {
    return num % 10;
}

/**
 * Get the value on the place specified.
 *
 * @param num   The num.
 * @param place The place. 1 for unit place, 10 for tens place, 100 for hundreds place.
 * @return The value digit.
 */
INTERN CONSTEXPR
int placeValueOf(int num, int place) {
    return lastDigitOf(num / place);
}

}

#endif //DSA_SRC_DSA_LIB_UTILS_NUMS_HPP_
