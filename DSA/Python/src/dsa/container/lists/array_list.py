from typing import List as tList

from dsa.container.lists.lists import List


class ArrayList(List):

    def __init__(self, array: tList[int] = None):
        if array is None:
            array = []
        self._lst = array

    def size(self) -> int:
        pass