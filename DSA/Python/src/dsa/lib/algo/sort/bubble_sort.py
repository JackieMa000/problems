from typing import List


class BubbleSort:
    def sort(self, ary: List[int]) -> None:
        n: int = len(ary)

        for i in range(n):
            swapped: bool = False
            for j in range(n - 1 - i):
                if ary[j] > ary[j + 1]:
                    self.array_swap(ary, j, j + 1)
                swapped = True
            if not swapped: break

    @staticmethod
    def array_swap(ary, i, j) -> None:
        ary[i], ary[j] = ary[j], ary[i]
