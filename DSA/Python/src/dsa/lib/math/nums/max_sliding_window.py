from typing import List

from dsa.container.lists.queues import Deque


# LeetCode239
class MaxSlidingWindow:
    @staticmethod
    def maxSlidingWindow(nums: List[int], k: int) -> List[int]:
        """
        Rule: Deque, Monotonic Queue
        Monotonic Queue: sorted Queue(Ascending or Descending)
        """
        deque = Deque()
        result: List[int] = []
        for i in range(len(nums)):
            window_left_bound: int = i - k + 1
            if not deque.empty() and deque.peek() < window_left_bound: deque.pop()
            # maintain the ascending order
            while not deque.empty() and nums[deque.peekback()] < nums[i]: deque.popback()
            deque.push(i)
            if window_left_bound >= 0: result.append(nums[deque.peek()])
        return result
