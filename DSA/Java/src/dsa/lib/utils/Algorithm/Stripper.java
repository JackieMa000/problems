package dsa.lib.utils.Algorithm;

import java.util.Arrays;

public class Stripper {
    public static int[] lstripIt(int[] nums) {
        int i = 0;
        while (i < nums.length && nums[i] == 0) ++i;
        return i == 0 ? nums : Arrays.copyOfRange(nums, i, nums.length);
    }

    public static int[] lstripDfs(int[] nums) {
        if (nums.length == 0) return nums;
        return nums[0] != 0 ? nums : lstripDfs(Arrays.copyOfRange(nums, 1, nums.length));
    }

    public static int[] rstripIt(int[] nums) {
        int n = nums.length, i = n;
        while (i > 0 && nums[i - 1] == 0) --i;
        return i == n ? nums : Arrays.copyOfRange(nums, 0, i);
    }

    public static int[] rstripDfs(int[] nums) {
        final int n = nums.length;
        if (n == 0) return nums;
        return nums[n - 1] != 0 ? nums : rstripDfs(Arrays.copyOf(nums, n - 1));
    }

    public static int[] stripIt(int[] nums) {
        int n = nums.length;

        int i = 0, j = n;
        while (i < j && nums[i] == 0) ++i;
        while (i < j && nums[j - 1] == 0) --j;
        return i == 0 && j == n ? nums : Arrays.copyOfRange(nums, i, j);
    }

    public static int[] stripDfs(int[] nums) {
        int n = nums.length;
        if (n == 0) return nums;

        final boolean isFirst0 = nums[0] == 0;
        final boolean isLast0 = nums[n - 1] == 0;
        int i = isFirst0 ? 1 : 0;
        int j = (isLast0 && n > 1) ? n - 1 : n;
        return (!isFirst0 && !isLast0) ? nums : stripDfs(Arrays.copyOfRange(nums, i, j));
    }
}
