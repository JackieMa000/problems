#pragma once

#include <vector>

#include <dsa/dsadef.h>

namespace dsa::lib::algo::sort {

template<class T>
class CountingSortAbstract {
 protected:
    std::vector<T> ary;
    size_t size;

    int min{}, max{};

 protected:
    explicit CountingSortAbstract(std::vector<T> ary) : ary(ary), size(ary.size()) {}

 public:
    virtual void sort() = 0;

 protected:
    virtual void initMinMax() = 0;
    virtual int countsIndexOf(T e) = 0;
};

class CountingSortIntAbstract : public CountingSortAbstract<int> {
 public:
    explicit CountingSortIntAbstract(std::vector<int> &nums) : CountingSortAbstract(nums) {}

    void sort() override {

    }
};
}