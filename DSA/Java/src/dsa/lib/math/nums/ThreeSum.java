package dsa.lib.math.nums;

import java.util.*;

//LeetCode15
class ThreeSum {
    public List<List<Integer>> threeSum(int[] nums) {
        return threeSum1(nums);
    }

    /*
     * Rule: SortFind. Double Pointers
     * remove duplicates for a
     * remove duplicates for b, c
     *
     * sort(nums)
     * loop a:
     *  double pointers for b, c
     *  b = nums[left]
     *  c = nums[right]
     *  sum = a + b + c
     *  sum > 0 -> right--
     *  sum < 0 -> left++
     *  sum == 0 -> 1)remove duplicates. 2)save result 3)left++, right--
     */
    public List<List<Integer>> threeSum1(int[] nums) {
        final int n = nums.length;
        List<List<Integer>> result = new LinkedList<>();

        Arrays.sort(nums);
        for (int i = 0; i < n - 2; i++) {
            if (i >= 1 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    result.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    left++;
                    right--;
                } else if (sum < 0) left++;
                else right--;
            }
        }

        return result;
    }

    /*
     * Rule: Hash Table.
     * Sort, result hash set, remove duplicates from the result
     * Hash Table bSet for finding the result by b
     * a + b + c = target -> b = -(a + c)
     *
     * loop a:
     *  loop c:
     *      cur = c
     *      b = -(a + c)
     *      if find b in hash table, save result
     *      else, save cur to hash table
     */
    public List<List<Integer>> threeSum2(int[] nums) {
        Set<List<Integer>> result = new HashSet<>();
        final int n = nums.length;

        Arrays.sort(nums);
        Set<Integer> bSet;
        for (int i = 0; i < n - 2; i++) {
            bSet = new HashSet<>();
            for (int j = i + 1; j < n; j++) {
                int b = -(nums[i] + nums[j]);
                if (bSet.contains(b)) result.add(Arrays.asList(nums[i], b, nums[j]));
                else bSet.add(nums[j]);
            }
        }

        return new LinkedList<>(result);
    }


}
