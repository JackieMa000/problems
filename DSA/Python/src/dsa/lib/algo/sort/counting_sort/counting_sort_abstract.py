from abc import ABCMeta, abstractmethod
from typing import List, Any

from dsa.lib.utils import lists


class CountingSortAbstract(metaclass=ABCMeta):
    def __init__(self, ary: List[Any]) -> None:
        self.ary = ary
        self.size = len(ary)

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

    def init_fields(self):
        self.init_minMax()
        self.COUNTS_SIZE = self.max - self.min + 1
        self.init_counts()

    @abstractmethod
    def init_minMax(self) -> None:
        pass

    @abstractmethod
    def countsIndexOf(self, e) -> int:
        pass

    def init_counts(self):
        self.counts = [0] * self.COUNTS_SIZE

    def store_counts(self):
        for e in self.ary: self.counts[self.countsIndexOf(e)] += 1

    def accumulate_counts(self):
        for i in range(1, self.COUNTS_SIZE): self.counts[i] += self.counts[i - 1]

    def produceSorted(self):
        r = [0] * self.size
        self.generate_result(r)
        lists.copy(r, 0, self.ary, 0, self.size)

    def generate_result(self, res: List[Any]) -> None:
        for i in range(self.size - 1, -1, -1):
            e = self.ary[i]
            ci = self.countsIndexOf(e)
            index = self.counts[ci] - 1

            res[index] = e
            self.counts[ci] -= 1


class CountingSortIntAbstract(CountingSortAbstract, metaclass=ABCMeta):
    pass
