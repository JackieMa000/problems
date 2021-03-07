package dsa.lib.algo.sort;

import org.junit.Test;

import static org.junit.Assert.assertArrayEquals;

public class RadixSortTest1 {
    private static void radixSort(String[] ary) {
        new RadixSort1().sort(ary);
    }

    @Test
    public void case1() {
        String[] ary = {"ab"};
        String[] expected = {"ab"};
        radixSort(ary);
        assertArrayEquals(expected, ary);
    }

    @Test
    public void case2() {
        String[] ary = {"hke", "iba", "hzg", "ikf", "hac"};
        String[] expected = {"hac", "hke", "hzg", "iba", "ikf"};
        radixSort(ary);
        assertArrayEquals(expected, ary);
    }
}