from typing import List

from dsa.lib.utils import array_copy


class MergeSort:
    def sort(self, ary: List[int], n: int) -> None:
        self.split(ary, 0, n - 1)

    def split(self, ary: List[int], st: int, end: int) -> None:
        """
        Split the array into 2 sub-arrays recursively, then merge them into a sorted array.

        :param ary:
        :param st: The start position of the array to be split, inclusive.
        :param end: The end position of the array to be split, inclusive.
        """
        if st >= end: return

        mid: int = st + (end - st) // 2
        self.split(ary, st, mid)
        self.split(ary, mid + 1, end)
        self.merge(ary, st, mid, end)

    @staticmethod
    def merge(ary: List[int], st: int, m: int, end: int) -> None:
        """
        Merge 2 sub-arrays into a sorted array.

        :param ary:
        :param st: The start position of 1st sub-array, inclusive.
        :param m: The end position of the 1st sub-array, inclusive.
        Also it is the divided position of the 2 sub-arrays, the next position is the start of the 2nd sub-array.
        :param end: The end position of the 2nd array,inclusive.
        :return:
        """
        n: int = end - st + 1
        result: List[int] = [0 for _ in range(n)]

        i, j = st, m + 1
        for k in range(n):
            if i <= m and j <= end:
                if ary[i] <= ary[j]:
                    result[k] = ary[i]
                    i += 1
                else:
                    result[k] = ary[j]
                    j += 1
            elif i <= m:
                result[k] = ary[i]
                i += 1
            else:
                result[k] = ary[j]
                j += 1

        array_copy(result, 0, ary, st, n)
