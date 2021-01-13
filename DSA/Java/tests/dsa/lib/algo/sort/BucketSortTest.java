package dsa.lib.algo.sort;

import org.junit.Test;

import static org.junit.Assert.assertArrayEquals;

public class BucketSortTest {
    private static void bucketSort(int[] ary) {
        new BucketSort().sort(ary, ary.length);
    }

    @Test
    public void oneNum() {
        int[] ary = {1};
        bucketSort(ary);
        assertArrayEquals(new int[]{1}, ary);
    }

    @Test
    public void case1() {
        int[] ary = {4, 5, 6, 3, 2, 1};
        bucketSort(ary);
        assertArrayEquals(new int[]{1, 2, 3, 4, 5, 6}, ary);
    }

    @Test
    public void case2() {
        int[] ary = {12, 11, 13, 5, 6, 7};
        bucketSort(ary);
        assertArrayEquals(new int[]{5, 6, 7, 11, 12, 13}, ary);
    }
}