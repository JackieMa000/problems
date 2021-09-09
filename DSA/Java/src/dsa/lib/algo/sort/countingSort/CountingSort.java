package dsa.lib.algo.sort.countingSort;

import dsa.lib.utils.Range;

public class CountingSort {
    public static void sort(int[] nums) {
        Integer[] a = Range.integerValueOf(nums);
        new CountingSortInteger(a).sort();
        Range.copy(a, 0, nums, 0, nums.length);
    }

    public static void sort(Integer[] nums) {
        new CountingSortInteger(nums).sort();
    }

    public static void sort(int[] nums, int place) {
        Integer[] a = Range.integerValueOf(nums);
        new CountingSortIntegerPlace(a, place).sort();
        Range.copy(a, 0, nums, 0, nums.length);
    }

    public static void sort(Integer[] nums, int place) {
        new CountingSortIntegerPlace(nums, place).sort();
    }

    public static void sort(String[] nums, int index) {
        new CountingSortString(nums, index).sort();
    }
}
