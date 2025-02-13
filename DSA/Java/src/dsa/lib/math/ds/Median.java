package dsa.lib.math.ds;

public class Median {
    // LeetCode4
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
//        merge two sorted array into one sorted array
        int[] sortedArray = merge(nums1, nums2);

//        return the median from the final merged sortedArray
        final int n1 = nums1.length, n2 = nums2.length;
        int n = n1 + n2;

        int mid = (n1 + n2) / 2;
        boolean isOdd = (n & 1) == 1;
//        isOdd: return mid element
//        isEven: return (midLeft + mid) / 2.0 element
        return isOdd ? sortedArray[mid] : (sortedArray[mid - 1] + sortedArray[mid]) / 2.0;
    }

    private int[] merge(int[] nums1, int[] nums2) {
//        populate the nums array by comparison.
        int n1 = nums1.length, n2 = nums2.length;
        int n = n1 + n2;
        int[] nums = new int[n];

//        traverse each array by comparison
//        loop with condition
        int i = 0, i1 = 0, i2 = 0;
        while (i1 < n1 && i2 < n2) {
            if (nums1[i1] <= nums2[i2]) nums[i++] = nums1[i1++];
            else nums[i++] = nums2[i2++];
        }

        if (i < n) {
//          nums1 is not done
            while (i1 < n1) nums[i++] = nums1[i1++];
//          nums2 is not done
            while (i2 < n2) nums[i++] = nums2[i2++];
        }

        return nums;
    }
}
