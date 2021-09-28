from typing import List, AnyStr

from dsa.lib.algo.sort.counting_sort.counting_sort_abstract import CountingSortAbstract


class CountingSortStr(CountingSortAbstract):
    def __init__(self, ss: List[AnyStr], index: int):
        """
        Only handles small case letters
        """
        super().__init__(ss)
        self.index = index

    def init_minMax(self) -> None:
        self.min = ord('a')
        self.max = ord('z')

    def countsIndexOf(self, e: str) -> int:
        return self.getCharFrom(e) - self.min

    def getCharFrom(self, s: str) -> int:
        lastIndex = len(s) - 1
        if self.index > lastIndex:
            return ord(s[lastIndex])
        return ord(s[self.index])
