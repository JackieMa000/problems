#pragma once

#include "quick_sort.hpp"
#include <dsa/lib/utils.hpp>

namespace dsa::lib::algo::sort {

// Let vector.size() track the bucket size.
class BucketSort {
 public:
    typedef std::vector<int> bucket_t;

    std::vector<int> &nums;
    const size_t size;
    int min{}, max{};

    std::vector<bucket_t> *buckets{};
    size_t bucketCount{};
    const size_t capacity;

 public:
    explicit BucketSort(std::vector<int> &nums) : nums(nums), size(nums.size()), capacity(2) {}
    BucketSort(std::vector<int> &nums, size_t capacity) : nums(nums), size(nums.size()), capacity(capacity) {}

    virtual ~BucketSort() { delete buckets; }

    void sort() {
        if (this->size < 2) { return; }

        initFields();
        scatterToEachBucket();
        sortEachBucket();
    }

 private:
    void initFields() {
        initMinMax();
        initBucketCount();
        initBuckets();
    }

    void initMinMax() {
        if (!this->size) { return; }

        min = max = nums[0];
        for (const int &num : nums) {
            if (num < min) { min = num; }
            else if (num > max) { max = num; }
        }
    }

    void initBucketCount() { bucketCount = (max - min + 1) / capacity + 1; }

    void initBuckets() { buckets = new std::vector<bucket_t>(bucketCount, bucket_t()); }

    void scatterToEachBucket() {
        for (const int &num : nums) {
            bucket_t &bucket = (*buckets)[bucketIndexOf(num)];
            size_t cap = bucket.capacity();
            if (bucket.size() >= cap) { bucket.reserve(cap * 1.5f); }
            bucket.push_back(num);
        }
    }

    pos_t bucketIndexOf(const int &num) const { return (num - min) / capacity; }

    void sortEachBucket() {
        pos_t k = 0;
        for (bucket_t &bucket : *buckets) {
            size_t size = bucket.size();

            if (!size) { continue; }

            quickSort(bucket.data(), size);
            utils::vectorcopy(bucket, 0, nums, k, size);
            k += size;
        }
    }

    static void quickSort(int *nums, size_t n) { QuickSort().sort(nums, n); }
};

}
