import collections
from typing import List


# LeetCode239
class MaxSlidingWindow:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        """
        1. maintain the window in the queue(deque).
        2. the queue is stronger order.
        3. get the max for each window.
        """
        n: int = len(nums)
        # get a deque
        deque = collections.deque()

        # loop through the nums.
        # Maintain the window in the queue.
        # Store index in the queue
        result: List[int] = []
        for i in nums:
            window_left_bound: int = i - (k - 1)
            # remove
            while (len(deque) != 0 and deque[0] < window_left_bound):
                deque.pop()

            # ascending ordered queue
            # remove all the elements which are smaller than the cur
            while (len(deque) != 0 and nums[deque[-1]] < nums[i]):
                deque.popleft()

            # add
            deque.append(i)

            # save the result. when the window is formed to k num
            if window_left_bound >= 0:
                result.append(deque[0])

        return result

    def maxSlidingWindow1(self, nums: List[int], k: int) -> List[int]:
        # Edge case
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
