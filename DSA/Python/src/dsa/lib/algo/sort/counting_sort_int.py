from typing import List

from dsa.lib.algo.sort.counting_sort_abstract import CountingSortIntAbstract
from dsa.lib.utils import nums


class CountingSortInt(CountingSortIntAbstract):
    def init_minMax(self):
        if not self.size: return

        self.min = self.max = self.ary[0]
        for num in self.ary:
            if num > self.max:
                self.max = num
            elif num < self.min:
                self.min = num

    def countsIndexOf(self, e: int) -> int:
        return e - self.min


class CountingSortIntPlace(CountingSortIntAbstract):
    def __init__(self, nums_: List[int], place: int):
        super().__init__(nums_)
        self.place = place

    def init_minMax(self):
        self.min = 0
        self.max = 9

    def countsIndexOf(self, e: int) -> int:
        return nums.placeValueOf(e, self.place) - self.min
