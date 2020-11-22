package dsa.lib.math.nums;

import java.util.HashMap;
import java.util.Map;


/**
 * Rule: Hash Table
 * mapNums: {num: index_of_num}
 * x + y = target -> x = target - y
 * generate the hash table for x
 * Loop through the nums
 * cur = nums[i] = y
 * find x in hash table:
 * 1) found, return {index_x, index_y}
 * 2) not found, save cur(y) to the hash table
 * default return {}
 */
//LeetCode1
public class TwoSum {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> mapNums = new HashMap<>();
        for (int i = 0, x; i < nums.length; i++) {
            x = target - nums[i];
            if (mapNums.containsKey(x)) return new int[]{mapNums.get(x), i};
            mapNums.put(nums[i], i);
        }
        return new int[]{};
    }
}
