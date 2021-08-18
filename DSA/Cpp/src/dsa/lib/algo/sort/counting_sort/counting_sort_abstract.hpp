#pragma once

#include <vector>

#include <dsa/dsadef.h>
#include <dsa/lib/utils/algorithm.hpp>
#include <dsa/lib/utils/out.hpp>

namespace dsa::lib::algo::sort {

template<class T>
class CountingSortAbstract {
 public:
    std::vector<T> &ary;
    const size_t size;
    int min{}, max{};

    int *counts{};
    int COUNTS_SIZE{};

 public:
    explicit CountingSortAbstract(std::vector<T> &ary) : ary(ary), size(ary.size()) {}
    virtual ~CountingSortAbstract() { delete[] counts; }

 public:
    void sort() {
        if (size < 2) return;

        initFields();
        storeCounts();
        accumulateCounts();
        produceSorted();
    }

 public:
    virtual void initMinMax() = 0;
    virtual pos_t countsIndexOf(T e) = 0;

 public:
    void initFields() {
        initMinMax();
        COUNTS_SIZE = max - min + 1;
        initCounts();
    }

    void initCounts() {
        counts = new int[COUNTS_SIZE];
        dsa::fill(counts, counts + COUNTS_SIZE, 0);
    }

    void storeCounts() {
        for (const T e : ary) ++counts[countsIndexOf(e)];
    }

    void accumulateCounts() {
        for (int i = 1; i < COUNTS_SIZE; ++i) counts[i] += counts[i - 1];
    };

    void produceSorted() {
        T *r = new T[size];
        generateResult(r);
        dsa::copy(r, r + size, ary.begin());
        delete[] r;
    }

    void generateResult(T *res) {
        for (int i = size - 1; i >= 0; --i) {
            const T e = ary[i];
            const int ci = countsIndexOf(e);
            const int index = counts[ci] - 1;

            res[index] = e;
            --counts[ci];
        }
    }
};

class CountingSortIntAbstract : public CountingSortAbstract<int> {
 public:
    explicit CountingSortIntAbstract(std::vector<int> &nums) : CountingSortAbstract(nums) {}
};
}