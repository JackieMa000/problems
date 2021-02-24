package dsa.lib.algo.sort;

import dsa.lib.Utils;

public class BucketSort {

    private int[] nums;
    private final int initBucketCapacity = 2;

    private int min, max;
    private int[][] buckets;
    private int[] bucketSizes;
    private int bucketCount;

    public BucketSort(int[] nums) {
        this.nums = nums;
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
        for (int i = 1; i < nums.length; ++i) {
            if (nums[i] < min) min = nums[i];
            else if (nums[i] > max) max = nums[i];
        }
    }

    private void initBucketCount() {
        bucketCount = (max - min + 1) / initBucketCapacity + 1;
    }

    private void initBuckets() {
        buckets = new int[bucketCount][initBucketCapacity];
    }

    private void initBucketSizes() {
        bucketSizes = new int[bucketCount];
    }

    private void scatterToEachBucket() {
        for (final int num : nums) {
            int idx = bucketIndexOf(num);
            int[] bucket = buckets[idx];
            final int size = bucketSizes[idx];

            int cap = bucket.length;
            if (size > cap) resize(idx, (int) (cap * 1.5f));

            bucket[size] = num;
            ++bucketSizes[idx];
        }
    }

    private int bucketIndexOf(int num) {
        return (num - min) / initBucketCapacity;
    }

    private void resize(int bucketIdx, int newSize) {
        int[] bucket = buckets[bucketIdx];
        int[] newBucket = new int[newSize];
        Utils.arraycopy(bucket, 0, newBucket, 0, bucket.length);
        buckets[bucketIdx] = newBucket;
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

    private void quickSort(int[] bucket, int size) {
        new QuickSort().sort(bucket, size);
    }
}
