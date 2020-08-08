# https://leetcode-cn.com/problems/search-a-2d-matrix-ii/

import unittest
from typing import List


class Solution:
    def binary_search(self, nums: List[int], target: int) -> int:
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

    # 对角线遍历矩阵,从左上角开始遍历, binary_search变体,
    def searchMatrix_3(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]: return False
        m, n = len(matrix), len(matrix[0])
        x, y = 0, 0
        while x < m and y < n:
            row = [matrix[x][j] for j in range(y, n)]
            if self.binary_search(row, target): return True
            column = [matrix[i][y] for i in range(x, m)]
            if self.binary_search(column, target): return True
            x += 1
            y += 1
        return False

    # 对角线遍历矩阵,从右上角开始遍历, binary_search变体,
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]: return False

        m, n = len(matrix), len(matrix[0])
        x, y = 0, n - 1
        while x < m and y >= 0:
            if matrix[x][y] == target:
                return True
            elif matrix[x][y] < target:
                column = [matrix[i][y] for i in range(x, m)]
                if self.binary_search(column, target): return True
            else:
                row = [matrix[x][j] for j in range(y + 1)]
                if self.binary_search(row, target): return True
            x += 1
            y -= 1
        return False

    # 剪枝 binary_search变体
    def searchMatrix_1(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]: return False

        m, n = len(matrix), len(matrix[0])
        x, y = m - 1, 0
        while x >= 0 and y < n:
            if matrix[x][y] == target:
                return True
            elif matrix[x][y] < target:
                y += 1
            else:
                x -= 1
        return False


class MyTestCase(unittest.TestCase):
    def test_something(self):
        matrix = [[]]
        self.assertEqual(False, Solution().searchMatrix(matrix, 5))
        matrix = [
            [1, 4, 7, 11, 15],
            [2, 5, 8, 12, 19],
            [3, 6, 9, 16, 22],
            [10, 13, 14, 17, 24],
            [18, 21, 23, 26, 30]
        ]
        self.assertEqual(True, Solution().searchMatrix(matrix, 5))
        self.assertEqual(False, Solution().searchMatrix(matrix, 20))


if __name__ == '__main__':
    unittest.main()
