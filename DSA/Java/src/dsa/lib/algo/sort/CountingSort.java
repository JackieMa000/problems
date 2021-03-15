package dsa.lib.algo.sort;

import dsa.lib.utils.Arrays;

public class CountingSort {

    private int[] nums;
    private final int size;

    int min, max;
    int[] counts;

    public CountingSort(int[] nums) {
        this.nums = nums;
        this.size = nums.length;
    }

    public void sort() {
        if (this.size < 2) return;

        initFields();
        storeCounts();
        accumulateCounts();

        int[] result = new int[this.size];
        generateResult(result);
        Arrays.copy(result, 0, this.nums, 0, result.length);
    }

    private void initFields() {
        initMinMax();
        initCounts();
    }

    public void initMinMax() {
        if (this.size == 0) return;

        min = max = this.nums[0];
        for (final int num : nums) {
            if (num < min) min = num;
            else if (num > max) max = num;
        }
    }

    public void initCounts() {
        counts = new int[max - min + 1];
        Arrays.fill(counts, 0);
    }

    public void storeCounts() {
        for (final int num : this.nums) ++counts[countsIndexOf(num)];
    }

    private int countsIndexOf(int num) {
        return num - min;
    }

    public void accumulateCounts() {
        for (int i = 1; i < counts.length; i++) counts[i] += counts[i - 1];
    }

    private void generateResult(int[] result) {
        for (int i = this.size - 1; i >= 0; --i) {
            int num = this.nums[i];
            final int ci = countsIndexOf(num);
            result[counts[ci] - 1] = num;
            --counts[ci];
        }
    }
}
