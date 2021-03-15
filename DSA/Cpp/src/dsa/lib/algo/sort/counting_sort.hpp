#pragma once

#include <vector>

#include <dsa/dsadef.h>
#include <dsa/lib/utils.hpp>

namespace dsa::lib::algo::sort {

class CountingSort {

 public:
    std::vector<int> &nums;
    const size_t size;

    int min{}, max{};
    std::vector<int> *counts{};

 public:
    explicit CountingSort(std::vector<int> &nums) : nums(nums), size(nums.size()) {}
    virtual ~CountingSort() { delete counts; }

    void sort() {
        if (this->size < 2) { return; }

        initFields();
        storeCounts();
        accumulateCounts();

        std::vector<int> result(this->size, 0);
        generateResult(result);

        utils::vectorcopy(result, 0, nums, 0, result.size());
    }

 public:
    void initFields() {
        initMinMax();
        initCounts();
    }

    void initMinMax() {
        if (!this->size) { return; }

        min = max = this->nums[0];
        for (const int num: this->nums) {
            if (num > max) { max = num; }
            else if (num < min) { min = num; }
        }
    }

    void initCounts() { counts = new std::vector<int>(max - min + 1, 0); }

    void storeCounts() {
        for (const int &num  : nums) { ++(*counts)[countsIndexOf(num)]; }
    }

    int countsIndexOf(const int &num) const { return num - min; }

    void accumulateCounts() {
        for (int i = 1; i < counts->size(); ++i) { (*counts)[i] += (*counts)[i - 1]; }
    }

    void generateResult(std::vector<int> &result) {
        for (int i = (int) size - 1; i >= 0; --i) {
            int ci = countsIndexOf(nums[i]);
            result[((*counts)[ci] - 1)] = nums[i];
            --(*counts)[ci];
        }
    }
};

}
