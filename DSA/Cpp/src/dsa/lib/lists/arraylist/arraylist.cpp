#include "arraylist.h"

namespace dsa::lib::lists {

ArrayList::ArrayList() {
    int ary[DEFAULT_LENGTH];
    this->lst = ary;
}
ArrayList::ArrayList(const int ary[]) {
    this->lst = ary;
}
ArrayList::~ArrayList() {
    delete[] lst;
}
length_t ArrayList::length() {
//    ToDo
    return 0;
}

}  // namespace dsa