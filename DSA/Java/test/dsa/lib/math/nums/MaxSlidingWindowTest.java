package dsa.lib.math.nums;

import org.junit.Test;

import static org.junit.Assert.assertArrayEquals;

public class MaxSlidingWindowTest {
    private int[] maxSlidingWindow(int[] nums, int k) {
        return new MaxSlidingWindow().maxSlidingWindow(nums, k);
    }

    @Test
    public void case1() {
        assertArrayEquals(new int[]{4}, maxSlidingWindow(new int[]{4, -1}, 2));
        assertArrayEquals(new int[]{11}, maxSlidingWindow(new int[]{9, 11}, 2));
        assertArrayEquals(new int[]{1, -1}, maxSlidingWindow(new int[]{1, -1}, 1));
        assertArrayEquals(new int[]{1}, maxSlidingWindow(new int[]{1}, 1));
        assertArrayEquals(new int[]{3, 3, 5, 5, 6, 7}, maxSlidingWindow(new int[]{1, 3, -1, -3, 5, 3, 6, 7}, 3));
    }
}