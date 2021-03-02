#pragma once

#include "quick_sort.hpp"
#include <dsa/lib/utils.hpp>

namespace dsa::lib::algo::sort {

// Treats vector as array, tracks the size of vector manually.
class BucketSort {
 public:
    typedef std::vector<int> bucket_t;

    std::vector<int> &nums;
    int min{}, max{};

    std::vector<bucket_t> *buckets{};
    size_t bucketCount{};
    std::vector<size_t> *bucketSizes{};

    const size_t INIT_BUCKET_CAPACITY = 2;
    const size_t capacity;

    explicit BucketSort(std::vector<int> &nums) : nums(nums), capacity(INIT_BUCKET_CAPACITY) {}
    BucketSort(std::vector<int> &nums, const size_t capacity) : nums(nums), capacity(capacity) {}

    virtual ~BucketSort() {
        delete buckets;
        delete bucketSizes;
    }

    void sort() {
        if (nums.size() < 2) { return; }

        initFields();
        scatterToEachBucket();
        sortEachBucket();
    }

 private:
    void initFields() {
        initMinMax();
        initBucketCount();
        initBuckets();
        initBucketSizes();
    }

    void initMinMax() {
        min = nums[0], max = nums[0];
        for (const int &num : nums) {
            if (num < min) {
                min = num;
            } else if (num > max) {
                max = num;
            }
        }
    }

    void initBucketCount() { bucketCount = (max - min) / capacity + 1; }

    void initBuckets() { buckets = new std::vector<bucket_t>(bucketCount, bucket_t(capacity)); }

    void initBucketSizes() { bucketSizes = new std::vector<size_t>(bucketCount, 0); }

    void scatterToEachBucket() {
        for (const int &num : nums) {
            pos_t index = bucketIndexOf(num);
            bucket_t &bucket = (*buckets)[index];
            size_t size = (*bucketSizes)[index];

            size_t cap = bucket.capacity();
            if (size > cap) { bucket.reserve(cap * 1.5f); }

            bucket[size] = num;
            ++(*bucketSizes)[index];
        }
    }

    pos_t bucketIndexOf(const int &num) const { return (num - min) / capacity; }

    void sortEachBucket() {
        pos_t k = 0;
        for (pos_t i = 0; i < buckets->size(); ++i) {
            bucket_t &bucket = (*buckets)[i];
            size_t size = (*bucketSizes)[i];

            if (!size) { continue; }

            quickSort(bucket.data(), size);
            utils::vectorcopy(bucket, 0, nums, k, size);
            k += size;
        }
    }

    static void quickSort(int *nums, size_t n) { QuickSort().sort(nums, n); }
};

}
