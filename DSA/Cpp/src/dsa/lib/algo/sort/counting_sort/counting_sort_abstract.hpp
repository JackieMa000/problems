#pragma once

#include <vector>

#include <dsa/dsadef.h>
#include <dsa/lib/utils/algorithm.hpp>
#include <dsa/lib/utils/out.hpp>

namespace dsa::lib::algo::sort {

template<class T>
class CountingSortAbstract {
#ifdef DSA_TEST
    friend class CountingSortIntTest;
#endif

 protected:
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

 protected:
    virtual void initMinMax() = 0;
    virtual pos_t countsIndexOf(T e) = 0;

 protected:
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
        std::unique_ptr<T[]> p(new T[size]);
        auto first = p.get();
        generateResult(first);
        dsa::copy(first, first + size, ary.begin());
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
