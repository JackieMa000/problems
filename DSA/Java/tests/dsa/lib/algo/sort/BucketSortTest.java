package dsa.lib.algo.sort;

import org.junit.Test;

import static org.junit.Assert.*;

public class BucketSortTest {
    private static void bucketSort(int[] nums) {
        new BucketSort(nums).sort();
    }

    @Test
    public void minMax() {
        assertMinMax(new int[]{1, 1}, 1, 1);
        assertMinMax(new int[]{2, 1}, 1, 2);
        assertMinMax(new int[]{1, 2, 3}, 1, 3);
        assertMinMax(new int[]{1, 1, 1}, 1, 1);
        assertMinMax(new int[]{4, 2, 8}, 2, 8);
    }

    private void assertMinMax(int[] nums, int min, int max) {
        BucketSort bs = new BucketSort(nums);
        bs.sort();
        assertEquals(min, bs.min);
        assertEquals(max, bs.max);
    }

    @Test
    public void bucketCount() {
        assertBucketCount(new int[]{1, 2, 3}, 2, 2);
        assertBucketCount(new int[]{1, 4, 5}, 2, 3);
        assertBucketCount(new int[]{2, 4, 9}, 3, 3);
    }

    private void assertBucketCount(int[] nums, int capacity, int count) {
        BucketSort bs = new BucketSort(nums, capacity);
        bs.sort();
        assertEquals(count, bs.bucketCount);
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