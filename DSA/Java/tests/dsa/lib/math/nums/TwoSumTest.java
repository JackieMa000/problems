package dsa.lib.math.nums;

import org.junit.Test;

import static org.junit.Assert.*;

public class TwoSumTest {

    @Test
    public void case1() {
        assertArrayEquals(new int[]{0, 1}, twoSum(new int[]{2, 7, 11, 5}, 9));
        assertArrayEquals(new int[]{1, 2}, twoSum(new int[]{3, 2, 4}, 6));
        assertArrayEquals(new int[]{0, 1}, twoSum(new int[]{3, 3}, 6));
        assertArrayEquals(new int[]{}, twoSum(new int[]{1, 2}, 6));
    }

    private int[] twoSum(int[] nums, int target) {
        return new TwoSum().twoSum(nums, target);
    }
}