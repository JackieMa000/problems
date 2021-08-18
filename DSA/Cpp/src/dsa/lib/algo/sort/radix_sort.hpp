#pragma once

#include <dsa/config.h>
#include <dsa/lib/utils/algorithm.hpp>
#include <dsa/lib/algo/sort/counting_sort/counting_sort.hpp>

namespace dsa::lib::algo::sort::rs {

INTERN
void sort(std::vector<int> &v) {
    if (v.size() < 2) return;
    const auto max = dsa::max_element(v.begin(), v.end());
    for (int place = 1; place < *max; place *= 10) cs::sort(v, place);
}
template<class InputIterator>
void sort(InputIterator first, InputIterator last) {
    int n = dsa::distance(first, last);
    if (n < 2) return;

    const auto max = dsa::max_element(first, last);
    for (int place = 1; place < *max; place *= 10) cs::sort(first, last);
}

INTERN
void sort(std::vector<std::string> &v) {
    if (v.size() < 2) return;
    auto max = dsa::maxSizeElement(v.begin(), v.end());
    for (int i = (int) (*max).length() - 1; i >= 0; --i) cs::sort(v, i);
}
template<class InputIterator>
void sortStr(InputIterator first, InputIterator last) {
    int n = dsa::distance(first, last);
    if (n < 2) return;

    auto max = dsa::maxSizeElement(first, last);
    for (int i = (int) (*max).length() - 1; i >= 0; --i) cs::sortStr(first, last, i);
}

}
