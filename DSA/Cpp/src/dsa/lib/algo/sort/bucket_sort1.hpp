#pragma once

#include "quick_sort.hpp"
#include <dsa/lib/utils.hpp>

namespace dsa::lib::algo::sort {

// Treats vector as array, tracks the size of vector manually.
class BucketSort {
 public:
    typedef std::vector<int> bucket_t;
    typedef std::vector<bucket_t> buckets_t;
    typedef std::vector<size_t> sizes_t;

    buckets_t *buckets{};
    sizes_t *sizes{};

 private:
    std::vector<int> &nums;

    size_t initBucketCapacity = 2;
    int min{}, max{};

 public:
    explicit BucketSort(std::vector<int> &nums) : nums(nums) {}

    virtual ~BucketSort() {
        delete buckets;
        delete sizes;
    }

    void sort() {
        if (nums.size() < 2) { return; }

        setMinMax();
        size_t s = getBucketsSize();
        initBuckets(s);
        initSizesForBuckets(s);

        scatterToBuckets();
        sortEachBucket();
    }

 private:
    void setMinMax() {
        min = nums[0], max = nums[0];
        for (int &num : nums) {
            if (num < min) {
                min = num;
            } else if (num > max) {
                max = num;
            }
        }
    }

    size_t getBucketsSize() const {
        return (max - min + 1) / initBucketCapacity + 1;
    }

    void initBuckets(size_t bucketsSize) {
        bucket_t _bucket(initBucketCapacity);
        buckets = new buckets_t(bucketsSize, _bucket);
    }

    void initSizesForBuckets(size_t bucketsSize) { sizes = new sizes_t(bucketsSize, 0); }

    void scatterToBuckets() {
        for (int &num : nums) {
            pos_t idx = bucketIndexOf(num);
            bucket_t &bucket = (*buckets)[idx];
            size_t size = (*sizes)[idx];

            size_t cap = bucket.capacity();
            if (size > cap) { bucket.reserve(cap * 1.5); }

            bucket[size] = num;
            ++(*sizes)[idx];
        }
    }

    pos_t bucketIndexOf(const int &num) const {
        return (num - min) / initBucketCapacity;
    }

    void sortEachBucket() {
        pos_t k = 0;
        for (pos_t i = 0; i < buckets->size(); ++i) {
            size_t size = (*sizes)[i];
            if (!size) { continue; }

            bucket_t &bucket = (*buckets)[i];
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
