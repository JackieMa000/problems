package dsa.lib.algo.sort;

import org.junit.Ignore;
import org.junit.Test;

import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;

public class CountingSortTest {
    @Test
    public void emptyArray() {
        assertCountingSort(new int[]{}, new int[]{});
    }

    @Test
    public void oneElement() {
        assertCountingSort(new int[]{1}, new int[]{1});
    }

    @Test
    public void sorts() {
        assertCountingSort(new int[]{2, 1}, new int[]{1, 2});
        assertCountingSort(new int[]{1, 1, 0}, new int[]{0, 1, 1});
        assertCountingSort(new int[]{3, 2, 1}, new int[]{1, 2, 3});
        assertCountingSort(new int[]{4, 5, 6, 3, 2, 1}, new int[]{1, 2, 3, 4, 5, 6});
        assertCountingSort(new int[]{12, 11, 13, 5, 6, 7}, new int[]{5, 6, 7, 11, 12, 13});
        assertCountingSort(new int[]{2, 5, 3, 0, 2, 3, 0, 3}, new int[]{0, 0, 2, 2, 3, 3, 3, 5});

        assertCountingSort(new int[]{-1, -2}, new int[]{-2, -1});
        assertCountingSort(new int[]{-2, -4, -5}, new int[]{-5, -4, -2});
        assertCountingSort(new int[]{0, -1, -2}, new int[]{-2, -1, 0});
        assertCountingSort(new int[]{-2, -7, 3}, new int[]{-7, -2, 3});
    }

    private void assertCountingSort(int[] nums, int[] expected) {
        countingSort(nums);
        assertArrayEquals(expected, nums);
    }

    private void countingSort(int[] nums) {
        new CountingSort(nums).sort();
    }

    @Test
    public void minMax() {
        assertMinMax(new int[]{1}, 1, 1);
        assertMinMax(new int[]{1, 1}, 1, 1);
        assertMinMax(new int[]{1, 2, 3}, 1, 3);
        assertMinMax(new int[]{8, 2, 9}, 2, 9);
    }

    private void assertMinMax(int[] nums, int min, int max) {
        CountingSort cs = new CountingSort(nums);
        cs.initMinMax();

        assertEquals(min, cs.min);
        assertEquals(max, cs.max);
    }

    @Test
    public void countsSize() {
        assertCountsSize(new int[]{0, 0}, 1);
        assertCountsSize(new int[]{1, 1}, 1);
        assertCountsSize(new int[]{0, 1, 1}, 2);
        assertCountsSize(new int[]{2, 4, 8}, 7);

        assertCountsSize(new int[]{1, 2, 3}, 3);
        assertCountsSize(new int[]{1, 4, 1}, 4);
        assertCountsSize(new int[]{3, 4, 2}, 3);
    }

    private void assertCountsSize(int[] nums, int size) {
        CountingSort cs = new CountingSort(nums);
        cs.initMinMax();
        cs.initCounts();

        assertEquals(size, cs.counts.length);
    }

    @Test
    public void storeCounts() {
        assertStoreCounts(new int[]{1, 2, 3}, new int[]{1, 1, 1});
        assertStoreCounts(new int[]{1, 4, 1}, new int[]{2, 0, 0, 1});
        assertStoreCounts(new int[]{3, 4, 2}, new int[]{1, 1, 1});
    }

    private void assertStoreCounts(int[] nums, int[] expected) {
        CountingSort cs = new CountingSort(nums);
        cs.initMinMax();
        cs.initCounts();
        cs.storeCounts();

        assertArrayEquals(expected, cs.counts);
    }

    @Test
    public void accCounts() {
        assertAccCounts(new int[]{1, 2, 3}, new int[]{1, 2, 3});
        assertAccCounts(new int[]{1, 4, 1}, new int[]{2, 2, 2, 3});
        assertAccCounts(new int[]{3, 4, 2}, new int[]{1, 2, 3});
    }

    private void assertAccCounts(int[] nums, int[] expected) {
        CountingSort cs = new CountingSort(nums);
        cs.initMinMax();
        cs.initCounts();
        cs.storeCounts();
        cs.accumulateCounts();

        assertArrayEquals(expected, cs.counts);
    }
}
