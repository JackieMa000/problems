#pragma once

#include <vector>
#include <dsa/dsadef.h>
#include "counting_sort_abstract.hpp"

namespace dsa::lib::algo::sort {

class CountingSortString : public CountingSortAbstract<std::string> {
 private:
    const int FIRST_OF_ALPHABET = 97, LAST_OF_ALPHABET = 122;
    const pos_t index;

 public:
    CountingSortString(std::vector<std::string> &ss, pos_t index) : CountingSortAbstract(ss), index(index) {
    }

 protected:
    void initMinMax() override {
        min = FIRST_OF_ALPHABET;
        max = LAST_OF_ALPHABET;
    }

    pos_t countsIndexOf(std::string e) override {
        return getCharFrom(e) - min;
    }

    NODISCARD
    char getCharFrom(std::string s) const {
        const pos_t lastIndex = s.length() - 1;
        return index > lastIndex ? s[lastIndex] : s[index];
    }
};

}