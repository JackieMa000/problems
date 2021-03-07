package dsa.lib.algo.sort;

import org.junit.Test;

import static org.junit.Assert.assertArrayEquals;

public class CountingSortTest {
    private static void countingSort(int[] ary) {
        new CountingSort().sort(ary);
    }

    @Test
    public void oneNum() {
        int[] ary = {1};
        countingSort(ary);
        final int[] expected = {1};
        assertArrayEquals(expected, ary);
    }

    @Test
    public void case1() {
        int[] ary = {4, 5, 6, 3, 2, 1};
        countingSort(ary);
        final int[] expected = {1, 2, 3, 4, 5, 6};
        assertArrayEquals(expected, ary);
    }

    @Test
    public void case2() {
        int[] ary = {12, 11, 13, 5, 6, 7};
        countingSort(ary);
        final int[] expected = {5, 6, 7, 11, 12, 13};
        assertArrayEquals(expected, ary);
    }

    @Test
    public void case3() {
        int[] ary = {2, 5, 3, 0, 2, 3, 0, 3};
        countingSort(ary);
        final int[] expected = {0, 0, 2, 2, 3, 3, 3, 5};
        assertArrayEquals(expected, ary);
    }
}