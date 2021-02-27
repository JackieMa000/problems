package dsa.lib.algo.sort;

import dsa.lib.Utils;

class BucketSort {
    private int[] nums;
    private final int length;
    private final int INIT_BUCKET_CAPACITY = 2;

    private int min, max;
    private int[][] buckets;
    private int[] bucketSizes;
    private int bucketCount;

    public BucketSort(int[] nums, int n) {
        this.nums = nums;
        this.length = n;
    }

    public void sort() {
        if (this.length < 2) return;

        initFields();
        scatterToEachBucket();
        sortEachBucket();
    }

    private void initFields() {
        initMinMax();
        initBucketCount();
        initBuckets();
        initBucketSizes();
    }

    private void initMinMax() {
        min = nums[0];
        max = nums[0];
        for (int i = 1; i < this.length; ++i) {
            if (nums[i] < min) min = nums[i];
            else if (nums[i] > max) max = nums[i];
        }
    }

    private void initBucketCount() {
        bucketCount = (max - min + 1) / INIT_BUCKET_CAPACITY + 1;
    }

    private void initBuckets() {
        buckets = new int[bucketCount][INIT_BUCKET_CAPACITY];
    }

    private void initBucketSizes() {
        bucketSizes = new int[bucketCount];
    }

    private void scatterToEachBucket() {
        for (final int num : nums) {
            int index = bucketIndexOf(num);
            int[] bucket = buckets[index];
            int size = bucketSizes[index];

            int cap = bucket.length;
            if (size > cap) resizeBucket(index, (int) (cap * 1.5f));

            bucket[size] = num;
            ++bucketSizes[index];
        }
    }

    private int bucketIndexOf(int num) {
        return (num - min) / INIT_BUCKET_CAPACITY;
    }

    private void resizeBucket(int index, int newSize) {
        int[] newBucket = new int[newSize];
        int[] oldBucket = buckets[index];
        Utils.arraycopy(oldBucket, 0, newBucket, 0, oldBucket.length);
        buckets[index] = newBucket;
    }

    private void sortEachBucket() {
        int k = 0;
        for (int i = 0; i < buckets.length; ++i) {
            int[] bucket = buckets[i];
            int size = bucketSizes[i];

            if (size == 0) continue;

            quickSort(bucket, size);
            Utils.arraycopy(bucket, 0, nums, k, size);
            k += size;
        }
    }

    private void quickSort(int[] nums, int n) {
        new QuickSort().sort(nums, n);
    }
}

