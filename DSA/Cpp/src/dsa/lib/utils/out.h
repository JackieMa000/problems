#pragma once

#include <iostream>

namespace dsa {

template<class ForwardIterator>
void print(ForwardIterator first, ForwardIterator last) {
    std::cout << '{';
    while (first != last) {
        std::cout << *first;
        ++first;
        if (first != last) { std::cout << ", "; }
    }
    std::cout << '}';

    std::cout << '\n';
}

}
