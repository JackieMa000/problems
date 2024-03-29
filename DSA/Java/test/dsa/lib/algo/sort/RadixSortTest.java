package dsa.lib.algo.sort;

import org.junit.Test;

import static org.junit.Assert.assertArrayEquals;

public class RadixSortTest {
    @Test
    public void emptyArray() {
        assertRadixSort(new int[]{}, new int[]{});
    }

    @Test
    public void oneElement() {
        assertRadixSort(new int[]{1}, new int[]{1});
    }

    @Test
    public void sorts() {
        assertRadixSort(new int[]{1, 23, 45, 121, 432, 564, 788}, new int[]{121, 432, 564, 23, 1, 45, 788});
    }

    private void assertRadixSort(int[] expected, int[] nums) {
        radixSort(nums);
        assertArrayEquals(expected, nums);
    }

    private static void radixSort(int[] nums) {
        RadixSort.sort(nums);
    }
}