#include <algorithm>
#include <dsa/dsadef.h>
#include "utils.h"

namespace dsa::lib::utils {

/**
 * Remove all the trailing 0s from an array
 * Rule:
 * 1. array length is 0 -> return empty array
 * 2. array length is 1, the element is 0 -> return empty array
 * 3. array last element is not 0 -> return array
 * 4. array length is bigger than 1, last element is 0 -> remove the trailing 0s by loop
 */
std::tuple<size_t, int *> arrayRstrip(int *srcAry, size_t size, int *desAry) {
    length_t length = size / 4;
    if (!size || (length == 1 && *(srcAry) == 0)) return std::tuple<size_t, int *>();
    if (*(srcAry + (length - 1)) != 0) return {size, srcAry};

    auto newLength = length - 1;
    while (newLength > 0 && *(srcAry + (newLength - 1)) == 0) newLength--;
    std::copy(srcAry, srcAry + newLength, desAry);
    return {newLength * 4, desAry};
}

}  // namespace dsa