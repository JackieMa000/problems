#ifndef LIB_UTILS_H
#define LIB_UTILS_H

#include <tuple>

namespace dsa::lib::utils {

std::tuple<size_t, int *> arrayRstrip(int *ary, size_t size);
std::tuple<size_t, int *> arrayRstripIt(int ary[], size_t size);
std::tuple<size_t, int *> arrayRstripDfs(int ary[], size_t size);

}  // namespace dsa

#endif