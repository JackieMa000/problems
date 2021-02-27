package dsa.lib.algo.sort;

import org.junit.Test;

import static org.junit.Assert.assertArrayEquals;

public class BucketSortTest {
    private static void bucketSort(int[] nums) {
        new BucketSort(nums, nums.length).sort();
    }

    @Test
    public void emptyNums() {
        int[] nums = {};
        final int[] expected = {};
        bucketSort(nums);
        assertArrayEquals(expected, nums);
    }

    @Test
    public void oneNum() {
        int[] nums = {1};
        final int[] expected = {1};
        bucketSort(nums);
        assertArrayEquals(expected, nums);
    }

    @Test
    public void case1() {
        int[] nums = {4, 5, 6, 3, 2, 1};
        final int[] expected = {1, 2, 3, 4, 5, 6};
        bucketSort(nums);
        assertArrayEquals(expected, nums);
    }

    @Test
    public void case2() {
        int[] nums = {12, 11, 13, 5, 6, 7};
        final int[] expected = {5, 6, 7, 11, 12, 13};
        bucketSort(nums);
        assertArrayEquals(expected, nums);
    }
}