import unittest

from .sliding import SlidingWindow


class TestSliding(unittest.TestCase):

    def get_maxs_by_sliding(self, nums, window_size):
        return SlidingWindow(nums, window_size).get_maxs_by_sliding()

    def test_sliding_window(self):
        self.assertEqual([], self.get_maxs_by_sliding([], 3))
        self.assertEqual([], self.get_maxs_by_sliding([1], 3))
        self.assertEqual([], self.get_maxs_by_sliding([1, 4], 3))
        self.assertEqual([3], self.get_maxs_by_sliding([1, 3, -1], 3))
        self.assertEqual([3, 3, 5, 5, 6, 7], self.get_maxs_by_sliding([1, 3, -1, -3, 5, 3, 6, 7], 3))

