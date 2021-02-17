#pragma once
#include <dsa/lib/utils.hpp>
#include "array.hpp"
namespace dsa::lib::algo::sort {

class BucketSort {
 public:
    typedef array<int> bucket_t;
    typedef array<array<int>> buckets_t;
    typedef array<int> sizes_t;

    int min;
    int max;
    length_t capacity;

    /**
     * Get the two bounds of the array.
     *
     * @param ary The array.
     * @param n The length of the array.
     * @return The lower bound and upper bound of the array.
     */
    std::pair<int, int> getBounds(int *ary, length_t n) {
        int min = ary[0], max = ary[0];
        for (int i = 1; i < n; ++i) {
            int cur = ary[i];
            if (cur < min) {
                min = cur;
            } else { max = cur; }
        }
        return {min, max};
    }

    void resize(array<array<int>> buckets, pos_t idx, length_t newSize) {
        array<int> bucket = buckets[idx];
        int data[newSize];
        array<int> newBucket = {data, newSize};
        utils::arraycopy(bucket.data, 0, newBucket.data, 0, bucket.length);
        buckets[idx] = newBucket;
    }
    void scatterToBuckets(array<int> ary, array<array<int>> buckets, array<int> sizes) {
        for (int i = 0; i < ary.length; ++i) {
            int cur = ary[i];
            int bucketIdx = (cur - min) / capacity;
            array<int> bucket = buckets[bucketIdx];
            int size = sizes[bucketIdx];

            int curCapacity = bucket.length;
            if (size > curCapacity) { resize(buckets, bucketIdx, curCapacity * 2); }

            bucket[size] = cur;
            ++sizes[bucketIdx];
        }

    }
    /**
     * Bucket Sort the array.
     *
     * @param ary The array to sort.
     * @param n The length of the array.
     * @param capacity  The capacity of each bucket. (aka, how many elements each bucket can hold)
     */
    void bucketSort(int *ary, length_t n) {
        /**
         * get the range of the array_s. (lower bound and upper bound)
         * how many buckets_t it needs for the array_s range.
         * declare the buckets_t.
         * scatter to the buckets_t.
         * sort and combine each bucket_t.
         */
        std::pair<int, int> bounds = getBounds(ary, n);
        min = bounds.first;
        max = bounds.second;

        length_t nBuckets = (max - min + 1) / capacity + 1;
        array<int> bucketsData[nBuckets];
        array<array<int>> buckets = {bucketsData, nBuckets};

        int sizesData[nBuckets];
        array<int> sizes = {sizesData, nBuckets};

        array<int> array_s = {ary, n};

        scatterToBuckets(array_s, buckets, sizes);
//        sortBucket(array_s, buckets, sizes);
    }

    void sort(int *ary, length_t n) {
        bucketSort(ary, n);
    }
};

}
