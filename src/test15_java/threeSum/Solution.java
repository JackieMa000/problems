package threeSum;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

//SortFind. Two Points
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        int n = nums.length;
        if (n < 3) return res;

        Arrays.sort(nums);
        for (int i = 0; i < n - 2; i++) {
            if (i >= 1 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = n - 1;
            while (left < right) {
                int s = nums[i] + nums[left] + nums[right];
                if (s == 0) {
                    res.add(new ArrayList<>(Arrays.asList(nums[i], nums[left], nums[right])));
                    while (left < right && nums[left] == nums[left + 1]) left += 1;
                    while (left < right && nums[right] == nums[right - 1]) right -= 1;
                    left += 1;
                    right -= 1;
                } else if (s < 0) left += 1;
                else right -= 1;
            }
        }
        return res;
    }
}
