package dsa.lib.algo.sort;

import org.junit.Test;

import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;

public class CountingSortTest {

    @Test
    public void minMax() {
        assertMinMax(new int[]{1, 1}, 1, 1);
        assertMinMax(new int[]{2, 1}, 1, 2);
        assertMinMax(new int[]{1, 2, 3}, 1, 3);
        assertMinMax(new int[]{1, 1, 1}, 1, 1);
        assertMinMax(new int[]{4, 2, 8}, 2, 8);
    }

    private void assertMinMax(int[] nums, int min, int max) {
        CountingSort cs = getCountingSort(nums);
        assertEquals(min, cs.min);
        assertEquals(max, cs.max);
    }

    @Test
    public void countsSize() {
        assertCountsSize(new int[]{0, 0}, 1);
        assertCountsSize(new int[]{1, 1}, 1);
        assertCountsSize(new int[]{0, 1, 1}, 2);
        assertCountsSize(new int[]{2, 4, 8}, 7);
    }

    private void assertCountsSize(int[] nums, int expected) {
        assertEquals(expected, getCountingSort(nums).counts.length);
    }

    @Test
    public void countsIndexOf() {
        assertCountsIndexOf(new int[]{1, 2, 3}, 2, 1);
        assertCountsIndexOf(new int[]{1, 4, 1}, 4, 3);
        assertCountsIndexOf(new int[]{3, 4, 2}, 2, 0);
    }

    private void assertCountsIndexOf(int[] nums, int num, int expectedIndex) {
        assertEquals(expectedIndex, getCountingSort(nums).countsIndexOf(num));
    }

    private CountingSort getCountingSort(int[] nums) {
        CountingSort cs = new CountingSort(nums);
        cs.sort();
        return cs;
    }

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
        assertCountingSort(new int[]{1, 1, 0}, new int[]{0, 1, 1});
        assertCountingSort(new int[]{3, 2, 1}, new int[]{1, 2, 3});
        assertCountingSort(new int[]{4, 5, 6, 3, 2, 1}, new int[]{1, 2, 3, 4, 5, 6});
        assertCountingSort(new int[]{12, 11, 13, 5, 6, 7}, new int[]{5, 6, 7, 11, 12, 13});
        assertCountingSort(new int[]{2, 5, 3, 0, 2, 3, 0, 3}, new int[]{0, 0, 2, 2, 3, 3, 3, 5});
    }

    private void assertCountingSort(int[] nums, int[] expected) {
        countingSort(nums);
        assertArrayEquals(expected, nums);
    }

    private static void countingSort(int[] ary) {
        new CountingSort(ary).sort();
    }
}