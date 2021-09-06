from typing import List

from dsa.lib.utils import arrays


class SelectionSort:
    def sort(self, ary: List[int]) -> None:
        n = len(ary)
        for i in range(n - 1):
            min_idx = self.array_min_pos(ary, i, n)
            arrays.swap(ary, i, min_idx)

    @staticmethod
    def array_min_pos(ary: List[int], st: int, end: int) -> int:
        """
        Find the position of minimum element in the range of array

        :param ary: The whole array.
        :param st: The start position of the range array, inclusive.
        :param end: The end position of the range array, exclusive.
        :return: The position of the minimum element.
        """
        m: int = st
        for i in range(st + 1, end):
            if ary[i] < ary[m]: m = i
        return m
