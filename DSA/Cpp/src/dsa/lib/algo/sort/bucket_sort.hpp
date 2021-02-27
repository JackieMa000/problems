#pragma once

#include "quick_sort.hpp"
#include <dsa/lib/utils.hpp>

namespace dsa::lib::algo::sort {

class BucketSort {
 private:
    typedef std::vector<int> bucket_t;
    typedef std::vector<bucket_t> buckets_t;

    std::vector<int> &nums;
    const size_t INIT_BUCKET_CAPACITY = 2;

    int min{}, max{};
    buckets_t *buckets{};
    size_t bucketCount{};

 public:
    explicit BucketSort(std::vector<int> &nums) : nums(nums) {}

    virtual ~BucketSort() { delete buckets; }

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

    void initBucketCount() { bucketCount = (max - min + 1) / INIT_BUCKET_CAPACITY + 1; }

    void initBuckets() {
        bucket_t _bucket;
        buckets = new buckets_t(bucketCount, _bucket);
    }

    void scatterToEachBucket() {
        for (int &num : nums) {
            bucket_t &bucket = (*buckets)[bucketIndexOf(num)];
            size_t cap = bucket.capacity();
            if (bucket.size() > cap) { bucket.reserve(cap * 1.5f); }
            bucket.push_back(num);
        }
    }

    pos_t bucketIndexOf(const int &num) const {
        return (num - min) / INIT_BUCKET_CAPACITY;
    }

    void sortEachBucket() {
        pos_t k = 0;
        for (bucket_t &bucket : *buckets) {
            size_t size = bucket.size();
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
