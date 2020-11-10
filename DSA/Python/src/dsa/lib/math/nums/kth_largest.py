import heapq
from typing import List

from dsa.container.lists.queues import PriorityQueue


# LeetCode703
class KthLargest1:
    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.queue = heapq.nlargest(k, nums)
        heapq.heapify(self.queue)

    def add(self, val: int) -> int:
        heapq.heappush(self.queue, val)
        if len(self.queue) > self.k: heapq.heappop(self.queue)
        return self.queue[0]


class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.k = k
        self.queue: PriorityQueue = PriorityQueue()
        for num in nums:
            self.add(num)

    def add(self, val: int) -> int:
        self.queue.push(val)
        if self.queue.size() > self.k:
            self.queue.pop()
        return self.queue.peek()
