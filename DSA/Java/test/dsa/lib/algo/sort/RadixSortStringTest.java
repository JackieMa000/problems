package dsa.lib.algo.sort;

import org.junit.Test;

import static org.junit.Assert.assertArrayEquals;

public class RadixSortStringTest {
    @Test
    public void emptyArray() {
        assertRadixSort(new String[]{}, new String[]{});
    }

    @Test
    public void oneElement() {
        assertRadixSort(new String[]{"ab"}, new String[]{"ab"});
    }

    @Test
    public void sorts() {
        assertRadixSort(new String[]{"hke", "iba", "hzg", "ikf", "hac"},
                new String[]{"hac", "hke", "hzg", "iba", "ikf"});
    }

    private void assertRadixSort(String[] ary, String[] expected) {
        radixSort(ary);
        assertArrayEquals(expected, ary);
    }

    private static void radixSort(String[] ary) {
        new RadixSortString().sort(ary);
    }
}