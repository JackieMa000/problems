#include "arraylist.h"

namespace dsa::lib::lists {

ArrayList::ArrayList() : lst(new int[DEFAULT_LENGTH]) {}
ArrayList::~ArrayList() { delete[] lst; }
length_t ArrayList::length() {
    return 0;
}

}  // namespace dsa