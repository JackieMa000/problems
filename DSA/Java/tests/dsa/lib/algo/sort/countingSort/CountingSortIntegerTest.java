package dsa.lib.algo.sort.countingSort;

import org.junit.Test;

import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;

public class CountingSortIntegerTest {
    @Test
    public void emptyArray() {
        assertCountingSort(new Integer[]{}, new Integer[]{});
    }

    @Test
    public void oneElement() {
        assertCountingSort(new Integer[]{1}, new Integer[]{1});
    }

    @Test
    public void sorts() {
        assertCountingSort(new Integer[]{2, 1}, new Integer[]{1, 2});
        assertCountingSort(new Integer[]{1, 1, 0}, new Integer[]{0, 1, 1});
        assertCountingSort(new Integer[]{3, 2, 1}, new Integer[]{1, 2, 3});
        assertCountingSort(new Integer[]{4, 5, 6, 3, 2, 1}, new Integer[]{1, 2, 3, 4, 5, 6});
        assertCountingSort(new Integer[]{12, 11, 13, 5, 6, 7}, new Integer[]{5, 6, 7, 11, 12, 13});
        assertCountingSort(new Integer[]{2, 5, 3, 0, 2, 3, 0, 3}, new Integer[]{0, 0, 2, 2, 3, 3, 3, 5});

        assertCountingSort(new Integer[]{-1, -2}, new Integer[]{-2, -1});
        assertCountingSort(new Integer[]{-2, -4, -5}, new Integer[]{-5, -4, -2});
        assertCountingSort(new Integer[]{0, -1, -2}, new Integer[]{-2, -1, 0});
        assertCountingSort(new Integer[]{-2, -7, 3}, new Integer[]{-7, -2, 3});
    }

    private void assertCountingSort(Integer[] nums, Integer[] expected) {
        countingSort(nums);
        assertArrayEquals(expected, nums);
    }

    private void countingSort(Integer[] nums) {
        new CountingSortInteger(nums).sort();
    }

    @Test
    public void minMax() {
        assertMinMax(new Integer[]{1}, 1, 1);
        assertMinMax(new Integer[]{1, 1}, 1, 1);
        assertMinMax(new Integer[]{1, 2, 3}, 1, 3);
        assertMinMax(new Integer[]{8, 2, 9}, 2, 9);
    }

    private void assertMinMax(Integer[] nums, int min, int max) {
        CountingSortInteger cs = new CountingSortInteger(nums);
        cs.initFields();

        assertEquals(min, cs.min);
        assertEquals(max, cs.max);
    }

    @Test
    public void countsSize() {
        assertCountsSize(new Integer[]{0, 0}, 1);
        assertCountsSize(new Integer[]{1, 1}, 1);
        assertCountsSize(new Integer[]{0, 1, 1}, 2);
        assertCountsSize(new Integer[]{2, 4, 8}, 7);

        assertCountsSize(new Integer[]{1, 2, 3}, 3);
        assertCountsSize(new Integer[]{1, 4, 1}, 4);
        assertCountsSize(new Integer[]{3, 4, 2}, 3);
    }

    private void assertCountsSize(Integer[] nums, int size) {
        CountingSortInteger cs = new CountingSortInteger(nums);
        cs.initFields();

        assertEquals(size, cs.counts.length);
    }

    @Test
    public void storeCounts() {
        assertStoreCounts(new Integer[]{1, 2, 3}, new int[]{1, 1, 1});
        assertStoreCounts(new Integer[]{1, 4, 1}, new int[]{2, 0, 0, 1});
        assertStoreCounts(new Integer[]{3, 4, 2}, new int[]{1, 1, 1});
    }

    private void assertStoreCounts(Integer[] nums, int[] expected) {
        CountingSortInteger cs = new CountingSortInteger(nums);
        cs.initFields();
        cs.storeCounts();

        assertArrayEquals(expected, cs.counts);
    }

    @Test
    public void accCounts() {
        assertAccCounts(new Integer[]{1, 2, 3}, new int[]{1, 2, 3});
        assertAccCounts(new Integer[]{1, 4, 1}, new int[]{2, 2, 2, 3});
        assertAccCounts(new Integer[]{3, 4, 2}, new int[]{1, 2, 3});
    }

    private void assertAccCounts(Integer[] nums, int[] expected) {
        CountingSortInteger cs = new CountingSortInteger(nums);
        cs.initFields();
        cs.storeCounts();
        cs.accumulateCounts();

        assertArrayEquals(expected, cs.counts);
    }
}
