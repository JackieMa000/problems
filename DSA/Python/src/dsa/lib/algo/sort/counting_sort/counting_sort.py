from typing import List, AnyStr

from dsa.lib.algo.sort.counting_sort.counting_sort_int import CountingSortInt, CountingSortIntPlace
from dsa.lib.algo.sort.counting_sort.counting_sort_str import CountingSortStr


def sortInt(nums: List[int]) -> None:
    CountingSortInt(nums).sort()


def sortIntPlace(nums: List[int], place: int) -> None:
    CountingSortIntPlace(nums, place).sort()


def sortStr(ss: List[AnyStr], index: int) -> None:
    CountingSortStr(ss, index).sort()
