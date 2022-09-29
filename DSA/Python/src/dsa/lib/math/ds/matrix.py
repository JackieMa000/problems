from typing import List


class Matrix:
    # LeetCode74
    # Binary Search. Treat the matrix like a 1d-array.
    # O(logM*N)
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

    # Binary Search Variation, smallest_greater_than(), get would be row for the target,
    # than normal binary search on the would be row.
    # O(logM+logN)
    def searchMatrix1(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not matrix[0]: return False
        last_column = [matrix[i][-1] for i in range(len(matrix))]
        row = self.smallest_greater_than(last_column, target)
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

    def smallest_greater_than(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return left

    def biggest_less_than(self, nums: List[int], target: int):
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1
        return right
