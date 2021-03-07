package dsa.lib.algo.sort;

import org.junit.Test;

import static org.junit.Assert.assertArrayEquals;

public class RadixSortTest {
    private static void radixSort(int[] ary) {
        new RadixSort().sort(ary);
    }

    @Test
    public void oneNum() {
        int[] ary = {1};
        final int[] expected = {1};
        radixSort(ary);
        assertArrayEquals(expected, ary);
    }

    @Test
    public void case1() {
        int[] ary = {121, 432, 564, 23, 1, 45, 788};
        final int[] expected = {1, 23, 45, 121, 432, 564, 788};
        radixSort(ary);
        assertArrayEquals(expected, ary);
    }
}