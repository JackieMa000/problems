#include "arraylist.h"

namespace dsa::lib::lists {

ArrayList::ArrayList() : lst(new int[DEFAULT_LENGTH]) {}
ArrayList::~ArrayList() { delete[] lst; }
length_t ArrayList::length() {
//    ToDo: Waiting for the DSA container
    return 0;
}

}  // namespace dsa