from typing import List

from dsa.lib import utils


class QuickSort:
    def sort(self, ary: List[int]) -> None:
        n: int = len(ary)
        self.quick_sort(ary, 0, n - 1)

    def quick_sort(self, ary, low: int, high: int) -> None:
        """
        QuickSort the ary recursively, until the array has only one element.

        :param ary: The array.
        :param low: The low endpoint of the array, inclusive.
        :param high: The high endpoint of the array, inclusive.
        """
        if low >= high: return

        m: int = self.partition(ary, low, high)
        self.quick_sort(ary, low, m - 1)
        self.quick_sort(ary, m + 1, high)

    @staticmethod
    def partition(ary: List[int], low: int, high: int) -> int:
        """
        Partition the array into 2 sub-parts, return the pivot position.
        All the elements on the left part are smaller than the pivot,
        all the elements on the right part are bigger than the pivot.

        :param ary: The array.
        :param low: The low endpoint of the array to be partitioned, inclusive.
        :param high: The high endpoint of the array to be partitioned, inclusive.
        :return: The pivot position.
        """
        i: int = low
        for j in range(low, high):
            if ary[j] < ary[high]:
                utils.array_swap(ary, i, j)
                i += 1
        utils.array_swap(ary, i, high)

        return i
