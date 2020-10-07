#ifndef LIB_UTILS_H
#define LIB_UTILS_H

#include "dsa/dsadef.h"

namespace dsa::lib::utils {

// Remove all the trailing 0s from an array
length_t arrayRstrip(const int *ary, length_t length);

}  // namespace dsa

#endif