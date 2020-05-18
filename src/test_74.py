# https://leetcode-cn.com/problems/search-a-2d-matrix/

import unittest
from typing import List


class Solution:
    # Binary Search. Treat the matrix like an array.
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]: return False
        m, n = len(matrix), len(matrix[0])
        left, right = 0, m * n - 1
        while left <= right:
            mid = left + (right - left) // 2
            pivot = matrix[mid // n][mid % n]
            if pivot == target:
                return True
            elif pivot < target:
                left = mid + 1
            else:
                right = mid - 1
        return False

    def searchMatrix_1(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]: return False
        last_column = [matrix[i][-1] for i in range(len(matrix))]
        row = self.greater_than(last_column, target)
        return False if row == len(matrix) else self.binary_search(matrix[row], target)

    def binary_search(self, nums: List[int], target: int) -> bool:
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return True
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return False

    def greater_than(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return left

    def less_than(self, nums: List[int], target: int):
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return right


class MyTestCase(unittest.TestCase):
    def test_less_than(self):
        self.assertEqual(1, Solution().less_than([4, 8, 12], 10))
        self.assertEqual(2, Solution().less_than([1, 4, 8, 12], 10))
        self.assertEqual(-1, Solution().less_than([4, 8, 12], 3))

    def test_something(self):
        matrix = [[1, 2, 3, 4],
                  [5, 6, 7, 8],
                  [9, 10, 11, 12]]
        self.assertEqual(True, Solution().searchMatrix(matrix, 7))
        matrix = [
            [1, 3, 5, 7],
            [10, 11, 16, 20],
            [23, 30, 34, 50]
        ]
        self.assertEqual(True, Solution().searchMatrix(matrix, 5))
        matrix = [
            [1, 3, 5, 7],
            [10, 11, 16, 20],
            [23, 30, 34, 50]
        ]
        self.assertEqual(False, Solution().searchMatrix(matrix, 13))
        matrix = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 50]]
        self.assertEqual(True, Solution().searchMatrix(matrix, 3))
        matrix = []
        self.assertEqual(False, Solution().searchMatrix(matrix, 3))
        matrix = [[]]
        self.assertEqual(False, Solution().searchMatrix(matrix, 3))
        matrix = [[1]]
        self.assertEqual(False, Solution().searchMatrix(matrix, 3))


if __name__ == '__main__':
    unittest.main()
