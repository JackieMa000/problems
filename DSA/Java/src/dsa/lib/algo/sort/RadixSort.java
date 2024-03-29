package dsa.lib.algo.sort;

import dsa.lib.algo.sort.countingSort.CountingSort;
import dsa.lib.utils.Range;

class RadixSort {
    static void sort(int[] nums) {
        if (nums.length < 2) return;
        final int max = Range.max(nums);
        for (int place = 1; place <= max; place *= 10) CountingSort.sort(nums, place);
    }
}
