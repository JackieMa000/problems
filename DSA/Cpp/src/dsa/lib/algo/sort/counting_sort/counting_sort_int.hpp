#pragma once

#include <vector>

#include <dsa/dsadef.h>
#include <dsa/lib/utils/nums.hpp>

#include "counting_sort_abstract.hpp"

namespace dsa::lib::algo::sort {

class CountingSortInt : public CountingSortIntAbstract {
    friend class CountingSortIntTest;

 public:
    explicit CountingSortInt(std::vector<int> &nums) : CountingSortIntAbstract(nums) {}

 protected:
    void initMinMax() override {
        if (this->size == 0) return;

        min = max = this->ary[0];
        for (const int num: this->ary) {
            if (num < min) min = num;
            else if (num > max) max = num;
        }
    }

    pos_t countsIndexOf(int e) override {
        return e - min;
    }
};

class CountingSortIntPlace : public CountingSortIntAbstract {
 private:
    const int place;

 public:
    CountingSortIntPlace(std::vector<int> &nums, int place) : CountingSortIntAbstract(nums), place(place) {
    }

 protected:
    void initMinMax() override {
        min = 0;
        max = 9;
    }

    pos_t countsIndexOf(int e) override {
        return nums::placeValueOf(e, place) - min;
    }

};

}
