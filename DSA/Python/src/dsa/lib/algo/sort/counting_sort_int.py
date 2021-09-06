from typing import List

from dsa.lib.utils import arrays


class CountingSortInt:

    def __init__(self, nums: List[int]) -> None:
        self.nums = nums
        self.size = len(nums)

        self.min = None
        self.max = None
        self.counts: List[int] = []
        self.COUNTS_SIZE: int = 0

    def sort(self) -> None:
        if self.size < 2: return

        self.init_fields()
        self.store_counts()
        self.accumulate_counts()
        self.produceSorted()

    def init_minMax(self):
        if not self.size: return

        self.min = self.max = self.nums[0]
        for num in self.nums:
            if num > self.max:
                self.max = num
            elif num < self.min:
                self.min = num

    def init_fields(self):
        self.init_minMax()
        self.COUNTS_SIZE = self.max - self.min + 1
        self.init_counts()

    def init_counts(self):
        self.counts = [0] * self.COUNTS_SIZE

    def store_counts(self):
        for e in self.nums: self.counts[self.countsIndexOf(e)] += 1

    def countsIndexOf(self, num: int) -> int:
        return num - self.min

    def accumulate_counts(self):
        for i in range(1, self.COUNTS_SIZE): self.counts[i] += self.counts[i - 1]

    def produceSorted(self):
        r = [0] * self.size
        self.generate_result(r)
        arrays.copy(r, 0, self.nums, 0, self.size)

    def generate_result(self, res: List[int]) -> None:
        for i in range(self.size - 1, -1, -1):
            e = self.nums[i]
            ci = self.countsIndexOf(e)
            index = self.counts[ci] - 1

            res[index] = e
            self.counts[ci] -= 1


class CountingSortIntPlace:
    def __init__(self, nums: List[int], place: int):
        self.nums = nums
        self.place = place

    def sort(self):
        pass
