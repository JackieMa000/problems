# https://leetcode.com/problems/sliding-window-maximum/

import unittest
from typing import List


class SlidingWindow:

    def __init__(self, nums: list, k: int):
        self.nums = nums
        self.window_size = k

    def get_maxs_by_sliding(self) -> list:
        window, res = [], []
        for i, x in enumerate(self.nums):
            window = self.maintain_deque(i, window, x)
            self.append_max_num_from_window_to_results(i, res, window)
        return res

    def maintain_deque(self, i, window, element):
        window = self.make_window_leftout(i, window)
        window = self.make_window_rightout(window, element)
        window.append(i)
        return window

    def append_max_num_from_window_to_results(self, i, res, window):
        max_num = self.get_max_num(i, window)
        if max_num:
            res.append(max_num)

    def get_max_num(self, i, window):
        is_window = i >= self.window_size - 1
        return self.nums[window[0]] if is_window else None

    def make_window_leftout(self, i, window):
        is_leftout = i >= self.window_size and window[0] <= i - self.window_size
        if is_leftout:
            window.pop(0)
        return window

    def make_window_rightout(self, window, x):
        while window and self.nums[window[-1]] <= x:
            window.pop()
        return window


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums: return []
        window, res = [], []
        for i, x in enumerate(nums):
            if i >= k and window[0] <= i - k:
                window.pop(0)
            while window and nums[window[-1]] <= x:
                window.pop()
            window.append(i)
            if i >= k - 1:
                res.append(nums[window[0]])
        return res


class TestSliding(unittest.TestCase):

    def get_maxs_by_sliding(self, nums, window_size):
        return SlidingWindow(nums, window_size).get_maxs_by_sliding()

    def test_sliding_window(self):
        self.assertEqual([], self.get_maxs_by_sliding([], 3))
        self.assertEqual([], self.get_maxs_by_sliding([1], 3))
        self.assertEqual([], self.get_maxs_by_sliding([1, 4], 3))
        self.assertEqual([3], self.get_maxs_by_sliding([1, 3, -1], 3))
        self.assertEqual([3, 3, 5, 5, 6, 7], self.get_maxs_by_sliding([1, 3, -1, -3, 5, 3, 6, 7], 3))

