package dsa.lib.math.ds;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class MedianTest {
    public static class FindMedianSortedArrayTest {
        @Test
        public void case1() {
            assertEquals(2.0, findMedianSortedArray(new int[]{1, 3}, new int[]{2}), .1);
            assertEquals(2.5, findMedianSortedArray(new int[]{1, 2}, new int[]{3, 4}), .1);
        }

        private double findMedianSortedArray(int[] nums1, int[] nums2) {
            return new Median().findMedianSortedArrays(nums1, nums2);
        }
    }
}
