package dsa.lib.utils;

import org.junit.Test;

import static org.junit.Assert.*;

public class ArraysTest {
    @Test
    public void min() {
        assertMin(new int[]{0}, 0);
        assertMin(new int[]{1, 2, 3}, 1);
    }

    private void assertMin(int[] nums, int expected) {
        assertEquals(expected, Arrays.min(nums));
    }

    @Test
    public void max() {
        assertMax(new int[]{0}, 0);
        assertMax(new int[]{1, 2, 3}, 3);
    }

    private void assertMax(int[] nums, int expected) {
        assertEquals(expected, Arrays.max(nums));
    }
}