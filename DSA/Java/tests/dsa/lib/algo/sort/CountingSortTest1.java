package dsa.lib.algo.sort;

import org.junit.Test;

import static org.junit.Assert.assertArrayEquals;

public class CountingSortTest1 {
    private static void countingSort(int[] ary, int place) {
        new CountingSort1().sort(ary, place);
    }

    @Test
    public void oneNum() {
        int[] ary = {1};
        countingSort(ary, 1);
        final int[] expected = {1};
        assertArrayEquals(expected, ary);
    }

    @Test
    public void unitPlace() {
        int[] ary = {121, 432, 564, 23, 1, 45, 788};
        countingSort(ary, 1);
        final int[] expected = {121, 1, 432, 23, 564, 45, 788};
        assertArrayEquals(expected, ary);
    }

    @Test
    public void tensPlace() {
        int[] ary = {121, 1, 432, 23, 564, 45, 788};
        countingSort(ary, 10);
        final int[] expected = {1, 121, 23, 432, 45, 564, 788};
        assertArrayEquals(expected, ary);
    }

    @Test
    public void hundredsPlace() {
        int[] ary = {1, 121, 23, 432, 45, 564, 788};
        countingSort(ary, 100);
        final int[] expected = {1, 23, 45, 121, 432, 564, 788};
        assertArrayEquals(expected, ary);
    }
}