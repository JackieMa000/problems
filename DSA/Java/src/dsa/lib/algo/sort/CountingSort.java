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

        Arrays.copy(result, 0, nums, 0, result.length);
    }

    private void initFields() {
        initMinMax();
        initCounts();
    }

    private void initMinMax() {
        min = max = nums[0];
        for (int i = 1; i < this.size; i++) {
            if (nums[i] < min) min = nums[i];
            else if (nums[i] > max) max = nums[i];
        }
    }

    private void initCounts() {
        counts = new int[max - min + 1];
        Arrays.fill(counts, 0);
    }

    private void storeCounts() {
        for (int num : nums) ++counts[countsIndexOf(num)];
    }

    int countsIndexOf(int num) {
        return num - min;
    }

    private void accumulateCounts() {
        for (int i = 1; i < counts.length; ++i) counts[i] += counts[i - 1];
    }

    private void generateResult(int[] result) {
        for (int i = this.size - 1; i >= 0; --i) {
            int index = counts[countsIndexOf(nums[i])] - 1;
            result[index] = nums[i];
            --counts[countsIndexOf(nums[i])];
        }
    }
}
