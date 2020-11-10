import heapq
from typing import List
from unittest import TestCase


class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.heap = heapq.nlargest(k, nums)
        heapq.heapify(self.heap)
        self.k = k

    def add(self, val: int) -> int:
        if len(self.heap) < self.k:
            heapq.heappush(self.heap, val)
        else:
            heapq.heappushpop(self.heap, val)
        return self.heap[0]


class TestKthLargest(TestCase):

    def test_add(self):
        largest = KthLargest(3, [4, 5, 8, 2])
        self.assertEqual(4, largest.add(3))
        self.assertEqual(5, largest.add(5))
        self.assertEqual(5, largest.add(10))
        self.assertEqual(8, largest.add(9))
        self.assertEqual(8, largest.add(4))