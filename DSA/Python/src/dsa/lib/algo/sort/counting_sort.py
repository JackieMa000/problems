from typing import List

from dsa.lib import utils


class CountingSort:

    def __init__(self, nums: List[int]) -> None:
        self.nums = nums
        self.size = len(nums)

        self.min = None
        self.max = None
        self.counts = None

    def sort(self) -> None:
        if self.size < 2: return

        self.init_fields()
        self.store_counts()
        self.accumulate_counts()

        result = [0] * self.size
        self.generate_result(result)
        utils.array_copy(result, 0, self.nums, 0, len(result))

    def init_fields(self):
        self.init_minMax()
        self.init_counts()

    def init_minMax(self):
        if not self.size: return

        self.min = self.max = self.nums[0]
        for num in self.nums:
            if num > self.max:
                self.max = num
            elif num < self.min:
                self.min = num

    def init_counts(self):
        self.counts = [0] * (self.max - self.min + 1)

    def store_counts(self):
        for num in self.nums: self.counts[self.countsIndexOf(num)] += 1

    def countsIndexOf(self, num: int) -> int:
        return num - self.min

    def accumulate_counts(self):
        for i in range(1, len(self.counts)): self.counts[i] += self.counts[i - 1]

    def generate_result(self, result: List[int]) -> None:
        for i in range(self.size - 1, -1, -1):
            num = self.nums[i]
            ci = self.countsIndexOf(num)
            result[(self.counts[ci] - 1)] = num
            self.counts[ci] -= 1
