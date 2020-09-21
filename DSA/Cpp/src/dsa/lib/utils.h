#ifndef LIB_UTILS_H
#define LIB_UTILS_H

#include <tuple>

namespace dsa::lib::utils {

std::tuple<size_t, int *> arrayRstrip(int *srcAry, size_t size, int *desAry);

}  // namespace dsa

#endif