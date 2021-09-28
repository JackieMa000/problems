from typing import List, AnyStr

from dsa.lib.algo.sort.counting_sort import counting_sort
from dsa.lib.utils import lists


def sort(nums: List[int]) -> None:
    if len(nums) < 2: return

    max_ = max(nums)
    place = 1
    while place <= max_:
        counting_sort.sortIntPlace(nums, place)
        place *= 10


def sortStr(ss: List[AnyStr]) -> None:
    if len(ss) < 2: return

    max_ = lists.maxSize(ss)
    i = len(max_) - 1
    while i >= 0:
        counting_sort.sortStr(ss, i)
        i -= 1
