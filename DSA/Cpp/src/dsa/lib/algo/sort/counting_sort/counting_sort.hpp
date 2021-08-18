#pragma once

#include <dsa/lib/libdef.h>
#include "counting_sort_int.hpp"
#include "counting_sort_str.hpp"

namespace dsa::lib::algo::sort::cs {

INTERN
void sort(std::vector<int> &v) {
    CountingSortInt(v).sort();
}

template<class InputIterator>
void sort(InputIterator first, InputIterator last) {
    std::vector<int> v(first, last);
    CountingSortInt(v).sort();
    dsa::copy(v.begin(), v.end(), first);
}

INTERN
void sort(std::vector<int> &v, int place) {
    CountingSortIntPlace(v, place).sort();
}

template<class InputIterator>
void sort(InputIterator first, InputIterator last, int place) {
    std::vector<int> v(first, last);
    CountingSortIntPlace(v, place).sort();
    dsa::copy(v.begin(), v.end(), first);
}

INTERN
void sort(std::vector<std::string> &ss, pos_t index) {
    CountingSortString(ss, index).sort();
}

template<class InputIterator>
void sortStr(InputIterator first, InputIterator last, pos_t index) {
    std::vector<std::string> v(first, last);
    CountingSortString(v, index).sort();
    dsa::copy(v.begin(), v.end(), first);
}

}
