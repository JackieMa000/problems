import unittest
from typing import List


class Solution:
    # Recursion
    def smallest_greater_than_1(self, target: int, nums: List[int]) -> int:
        def dfs(left, right, target, nums):
            # Terminator
            if left > right: return left
            # Recursive case
            mid = left + (right - left) // 2
            if nums[mid] < target:
                return dfs(mid + 1, right, target, nums)
            else:
                return dfs(left, mid - 1, target, nums)

        return dfs(0, len(nums) - 1, target, nums)

    def smallest_greater_than(self, target: int, nums: List[int]) -> int:
        # Find the the position of smallest num in the list which is greater than n by Binary Search
        # Return the size of list if it's not found.
        # nums should be a sorted list
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return left

    # Binary Search. List[lis] is the list of largest increasing sequence. It doesn't mean that it's absolutely
    # increased, but the size of the list should be the same with increasing sequence.
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums: return 0
        lis = [nums[0]]
        for i in range(1, len(nums)):
            pos = self.smallest_greater_than(nums[i], lis)
            if pos < len(lis):
                lis[pos] = nums[i]
            else:
                lis.append(nums[i])
        return len(lis)


class MyTestCase(unittest.TestCase):
    def test_something(self):
        self.assertEqual(0, Solution().lengthOfLIS([]))
        self.assertEqual(4, Solution().lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18]))
        self.assertEqual(5, Solution().lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18, 20]))
        self.assertEqual(4, Solution().lengthOfLIS([10, 11, 12, 13, 1, 2, 3, 4]))

    def test_greater_than(self):
        self.assertEqual(0, Solution().smallest_greater_than(1, []))
        self.assertEqual(0, Solution().smallest_greater_than(9, [10]))
        self.assertEqual(1, Solution().smallest_greater_than(4, [3, 6, 7, 10]))
        self.assertEqual(3, Solution().smallest_greater_than(10, [3, 6, 7, 10]))
        self.assertEqual(4, Solution().smallest_greater_than(11, [3, 6, 7, 10]))
        self.assertEqual(3, Solution().smallest_greater_than(8, [3, 6, 7, 10]))
        self.assertEqual(1, Solution().smallest_greater_than(5, [3, 6, 7, 10]))
