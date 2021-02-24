#pragma once

#include "quick_sort.hpp"
#include <dsa/lib/utils.hpp>

namespace dsa::lib::algo::sort {

// Treats vector as array, tracks the size of vector manually.
class BucketSort {
 private:
    typedef std::vector<int> bucket_t;
    typedef std::vector<bucket_t> buckets_t;
    typedef std::vector<size_t> sizes_t;

    std::vector<int> &nums;
    size_t initBucketCapacity = 2;

    int min{}, max{};
    buckets_t *buckets{};
    sizes_t *bucketSizes{};
    size_t bucketCount{};

 public:
    explicit BucketSort(std::vector<int> &nums) : nums(nums) {}

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
        for (int &num : nums) {
            if (num < min) {
                min = num;
            } else if (num > max) {
                max = num;
            }
        }
    }

    void initBucketCount() { bucketCount = (max - min + 1) / initBucketCapacity + 1; }

    void initBuckets() {
        bucket_t _bucket(initBucketCapacity);
        buckets = new buckets_t(bucketCount, _bucket);
    }

    void initBucketSizes() { bucketSizes = new sizes_t(bucketCount, 0); }

    void scatterToEachBucket() {
        for (int &num : nums) {
            pos_t idx = bucketIndexOf(num);
            bucket_t &bucket = (*buckets)[idx];
            size_t size = (*bucketSizes)[idx];

            size_t cap = bucket.capacity();
            if (size > cap) { bucket.reserve(cap * 1.5f); }

            bucket[size] = num;
            ++(*bucketSizes)[idx];
        }
    }

    pos_t bucketIndexOf(const int &num) const {
        return (num - min) / initBucketCapacity;
    }

    void sortEachBucket() {
        pos_t k = 0;
        for (pos_t i = 0; i < buckets->size(); ++i) {
            bucket_t &bucket = (*buckets)[i];
            size_t size = (*bucketSizes)[i];

            if (!size) { continue; }

            quickSort(bucket, size);
            utils::vectorcopy(bucket, 0, nums, k, size);
            k += size;
        }
    }

    static void quickSort(bucket_t &bucket, size_t n) {
        QuickSort qs;
        qs.sort(bucket.data(), n);
    }
};

}
