#pragma once

#include <vector>

#include <dsa/dsadef.h>
#include "counting_sort_abstract.hpp"
#include <dsa/lib/utils/nums.hpp>


namespace dsa::lib::algo::sort {

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

    int countsIndexOf(int e) override {
        return dsa::nums::placeValueOf(e, place) - min;
    }

};

}