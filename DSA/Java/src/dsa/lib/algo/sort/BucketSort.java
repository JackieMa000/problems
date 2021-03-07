package dsa.lib.algo.sort;

import dsa.lib.Utils;

class BucketSort {
    private int[] nums;
    int min, max;

    private int[][] buckets;
    private int[] bucketSizes;
    int bucketCount;
    private final int capacity;

    public BucketSort(int[] nums) {
        this.nums = nums;
        this.capacity = 2;
    }

    public BucketSort(int[] nums, int capacity) {
        this.nums = nums;
        this.capacity = capacity;
    }

    public void sort() {
        if (nums.length < 2) return;

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
        for (final int num : nums) {
            if (num < min) min = num;
            else if (num > max) max = num;
        }
    }

    private void initBucketCount() {
        bucketCount = (max - min + 1) / capacity + 1;
    }

    private void initBuckets() {
        buckets = new int[bucketCount][capacity];
    }

    private void initBucketSizes() {
        bucketSizes = new int[bucketCount];
    }

    private void scatterToEachBucket() {
        for (final int num : nums) {
            int index = bucketIndexOf(num);
            int size = bucketSizes[index];

            int cap = buckets[index].length;
            if (size >= cap) resizeBucket(index, (int) (cap * 1.5f));

            buckets[index][size] = num;
            ++bucketSizes[index];
        }
    }

    private int bucketIndexOf(int num) {
        return (num - min) / capacity;
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

