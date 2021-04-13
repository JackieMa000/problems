package dsa.lib.algo.sort;

import org.junit.Test;

import static org.junit.Assert.*;

public class SelectionSortTest {
    @Test
    public void oneNum() {
        int[] ary = {1};
        final int[] expected = {1};
        SelectionSort.sort(ary);
        assertArrayEquals(expected, ary);
    }

    @Test
    public void case1() {
        int[] ary = {4, 5, 6, 3, 2, 1};
        final int[] expected = {1, 2, 3, 4, 5, 6};
        SelectionSort.sort(ary);
        assertArrayEquals(expected, ary);
    }

}