package dsa.lib.algo.sort;

import org.junit.Test;

import static org.junit.Assert.assertArrayEquals;

public class QuickSortTest {
    private static void mergeSort(int[] ary) {
        new QuickSort().sort(ary, ary.length);
    }

    @Test
    public void oneNum() {
        int[] ary = {1};
        mergeSort(ary);
        assertArrayEquals(new int[]{1}, ary);
    }

    @Test
    public void case1() {
        int[] ary = {4, 5, 6, 3, 2, 1};
        mergeSort(ary);
        assertArrayEquals(new int[]{1, 2, 3, 4, 5, 6}, ary);
    }

    @Test
    public void case2() {
        int[] ary = {12, 11, 13, 5, 6, 7};
        mergeSort(ary);
        assertArrayEquals(new int[]{5, 6, 7, 11, 12, 13}, ary);
    }
}