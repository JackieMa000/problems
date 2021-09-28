package dsa.lib.algo.sort.countingSort;

import org.junit.Test;

import static org.junit.Assert.*;

public class CountingSortTest {

    @Test
    public void intArray() {
        int[] nums = {1, 3, 2};
        CountingSort.sort(nums);
        assertArrayEquals(new int[]{1, 2, 3}, nums);
    }

    @Test
    public void intPlaceArray() {
        int[] nums = {13, 32, 21};
        CountingSort.sort(nums, 1);
        assertArrayEquals(new int[]{21, 32, 13}, nums);
    }

    @Test
    public void integerArray() {
        Integer[] nums = {1, 3, 2};
        CountingSort.sort(nums);
        assertArrayEquals(new Integer[]{1, 2, 3}, nums);
    }

    @Test
    public void integerPlaceArray() {
        Integer[] nums = {13, 32, 21};
        CountingSort.sort(nums, 1);
        assertArrayEquals(new Integer[]{21, 32, 13}, nums);
    }

    @Test
    public void stringArray() {
        String[] ss = {"ae", "ce", "be"};
        CountingSort.sort(ss, 0);
        assertArrayEquals(new String[]{"ae", "be", "ce"}, ss);
    }
}