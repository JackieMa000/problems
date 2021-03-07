from typing import List


class InsertionSort:
    def sort(self, ary: List[int]) -> None:
        n: int = len(ary)
        for i in range(1, n):
            b: int = ary[i]
            pos: int = self.insert_pos_of(ary, 0, i)
            ary[pos] = b

    @staticmethod
    def insert_pos_of(ary: List[int], st: int, idx: int) -> int:
        """
        Find the insert position of an element in the sorted array.

        :param ary:
        :param st: The start position of the sorted array.
        :param idx: The index of the element to be inserted. The element should be next to the end element of
        the sorted array
        :return: The index of insert position
        """
        b: int = ary[idx]
        idx -= 1
        while idx >= st:
            a = ary[idx]
            if a > b:
                ary[idx + 1] = a
            else:
                break
            idx -= 1
        return idx + 1
