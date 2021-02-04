package dsa.lib.algo.sort;

import org.junit.Test;

import static org.junit.Assert.*;

public class MergeSortTest {
    private static void mergeSort(int[] ary) {
        new MergeSort().sort(ary, ary.length);
    }

    @Test
    public void oneNum() {
        int[] ary = {1};
        final int[] expected = {1};
        mergeSort(ary);
        assertArrayEquals(expected, ary);
    }

    @Test
    public void case1() {
        int[] ary = {4, 5, 6, 3, 2, 1};
        final int[] expected = {1, 2, 3, 4, 5, 6};
        mergeSort(ary);
        assertArrayEquals(expected, ary);
    }

    @Test
    public void case2() {
        int[] ary = {12, 11, 13, 5, 6, 7};
        final int[] expected = {5, 6, 7, 11, 12, 13};
        mergeSort(ary);
        assertArrayEquals(expected, ary);
    }
}