from typing import List


class InsertionSort:
    def sort(self, ary: List[int]) -> None:
        n: int = len(ary)
        for i in range(1, n):
            b: int = ary[i]
            pos: int = self.insert_pos_of(ary, i)
            ary[pos] = b

    @staticmethod
    def insert_pos_of(ary, i) -> int:
        """
        Find the insert position of element in the sorted range of array.

        :param ary: The whole array
        :param i: The index of element to be inserted
        :return: The index of insert position
        """
        b: int = ary[i]
        i -= 1
        while i >= 0:
            a = ary[i]
            if a > b:
                ary[i + 1] = a
            else:
                break
            i -= 1
        return i + 1
