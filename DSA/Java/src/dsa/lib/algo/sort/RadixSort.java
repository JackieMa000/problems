package dsa.lib.algo.sort;

import dsa.lib.algo.sort.countingSort.CountingSort;
import dsa.lib.utils.Arrays;

class RadixSort {
    void sort(int[] nums) {
        if (nums.length < 2) return;

        final int max = Arrays.max(nums);
        for (int place = 1; place <= max; place *= 10) new CountingSort(nums, place);
    }
}
