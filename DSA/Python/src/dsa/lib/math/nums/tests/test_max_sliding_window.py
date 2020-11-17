from unittest import TestCase

from dsa.lib.math.nums.max_sliding_window import MaxSlidingWindow


class TestMaxSlidingWindow(TestCase):
    @staticmethod
    def max_sliding_window(nums, k):
        return MaxSlidingWindow.maxSlidingWindow(nums, k)

    def test_max_sliding_window(self):
        self.assertEqual([], self.max_sliding_window([], 3))
        self.assertEqual([], self.max_sliding_window([1], 3))
        self.assertEqual([], self.max_sliding_window([1, 4], 3))
        self.assertEqual([3], self.max_sliding_window([1, 3, -1], 3))
        self.assertEqual([3, 3, 5, 5, 6, 7], self.max_sliding_window([1, 3, -1, -3, 5, 3, 6, 7], 3))
