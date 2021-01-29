from typing import List


class BubbleSort:
    def __init__(self):
        self.swapped = False

    def sort(self, ary: List[int]) -> None:
        n: int = len(ary)
        for i in range(n):
            self.compare_swap(ary, 0, n - i)
            if not self.swapped: break

    def compare_swap(self, ary: List[int], st: int, end: int) -> None:
        """
        Compare each two adjacent elements, swap them if 1st one is bigger than the 2nd.

        :param ary: The array
        :param st: The start position, inclusive.
        :param end: The end position, exclusive.
        :return:
        """
        for i in range(st, end - 1):
            if ary[i] > ary[i + 1]:
                self.array_swap(ary, i, i + 1)
            self.swapped = True

    @staticmethod
    def array_swap(ary, i, j) -> None:
        ary[i], ary[j] = ary[j], ary[i]
