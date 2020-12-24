package dsa.lib.algo.sort;

import org.junit.Test;

import static org.junit.Assert.*;

public class BubbleSortTest {
    @Test
    public void oneNum() {
        int[] ary = {1};
        BubbleSort.sort(ary);
        assertArrayEquals(new int[]{1}, ary);
    }

    @Test
    public void case1() {
        int[] ary = {4, 5, 6, 3, 2, 1};
        BubbleSort.sort(ary);
        assertArrayEquals(new int[]{1, 2, 3, 4, 5, 6}, ary);
    }
}