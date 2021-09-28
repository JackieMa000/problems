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
        assertRadixSort(new String[]{"hac", "hke", "hzg", "iba", "ikf"}, new String[]{"hke", "iba", "hzg", "ikf", "hac"}
        );
    }

    private void assertRadixSort(String[] expected, String[] ss) {
        radixSort(ss);
        assertArrayEquals(expected, ss);
    }

    private static void radixSort(String[] ss) {
        RadixSortString.sort(ss);
    }
}