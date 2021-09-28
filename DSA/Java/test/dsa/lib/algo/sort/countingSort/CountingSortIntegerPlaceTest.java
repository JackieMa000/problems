package dsa.lib.algo.sort.countingSort;

import org.junit.Test;

import static org.junit.Assert.assertArrayEquals;

public class CountingSortIntegerPlaceTest {
    private void assertCountingSortPlace(Integer[] nums, int place, Integer[] expected) {
        countingSort(nums, place);
        assertArrayEquals(expected, nums);
    }

    private static void countingSort(Integer[] nums, int place) {
        new CountingSortIntegerPlace(nums, place).sort();
    }

    @Test
    public void emptyArray() {
        assertCountingSortPlace(new Integer[]{}, 1, new Integer[]{});
        assertCountingSortPlace(new Integer[]{}, 10, new Integer[]{});
    }

    @Test
    public void oneElement() {
        assertCountingSortPlace(new Integer[]{1}, 1, new Integer[]{1});
        assertCountingSortPlace(new Integer[]{1}, 10, new Integer[]{1});
    }

    @Test
    public void placeExceeds_noSort() {
        assertCountingSortPlace(new Integer[]{2, 1, 3}, 10, new Integer[]{2, 1, 3});
        assertCountingSortPlace(new Integer[]{2, 11, 31}, 10, new Integer[]{2, 11, 31});
        assertCountingSortPlace(new Integer[]{22, 11, 31}, 100, new Integer[]{22, 11, 31});
    }

    @Test
    public void unitPlace() {
        assertCountingSortPlace(new Integer[]{2, 1, 3}, 1, new Integer[]{1, 2, 3});
        assertCountingSortPlace(new Integer[]{22, 11, 31}, 1, new Integer[]{11, 31, 22});
        assertCountingSortPlace(new Integer[]{121, 432, 564, 23, 1, 45, 788}, 1,
                new Integer[]{121, 1, 432, 23, 564, 45, 788});
    }

    @Test
    public void tensPlace() {
        assertCountingSortPlace(new Integer[]{22, 11, 31}, 10, new Integer[]{11, 22, 31});
        assertCountingSortPlace(new Integer[]{121, 1, 432, 23, 564, 45, 788}, 10,
                new Integer[]{1, 121, 23, 432, 45, 564, 788});
    }

    @Test
    public void hundredsPlace() {
        assertCountingSortPlace(new Integer[]{222, 111, 311}, 100, new Integer[]{111, 222, 311});
        assertCountingSortPlace(new Integer[]{1, 121, 23, 432, 45, 564, 788}, 100,
                new Integer[]{1, 23, 45, 121, 432, 564, 788});
    }

}