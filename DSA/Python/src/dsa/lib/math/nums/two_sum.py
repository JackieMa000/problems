from typing import List


# LeetCode1
class TwoSum:
    @staticmethod
    def twoSum(nums: List[int], target: int) -> List[int]:
        """
        Rule: Hash Table
        map_nums: {num: index_of_num}
        x + y = target -> x = target - y
        generate the hash table for x.
        find x in hash table:
            1) found, return [index_x, index_y]
            2) not found, save cur(y) to the hash table
        """

        map_nums = {}
        for i in range(len(nums)):
            x = target - nums[i]
            if x in map_nums: return [map_nums.get(x), i]
            map_nums[nums[i]] = i
        return []
