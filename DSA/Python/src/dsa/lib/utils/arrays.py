from typing import List, Optional


def rStrip(nums: List[int]) -> List[int]:
    """
    Remove the trailing 0s from an array
    Rule:
    1. Array length is 0 -> return empty array
    2. Array length is 1, the element is 0 -> return empty array
    3. Array last element is not 0 -> return array
    4. Array length is bigger than 1, last element is 0 -> remove the trailing 0s by loop.
    """
    return rStrip_it(nums)


def rStrip_it(nums: List[int]) -> List[int]:
    n: int = len(nums)
    if not n or (n == 1 and nums[0] == 0): return []
    while not nums[-1]: nums.pop(-1)
    return nums


def rStrip_dfs(nums: List[int]) -> List[int]:
    if not len(nums) or (len(nums) == 1 and nums[0] == 0): return []
    if nums[-1] != 0: return nums
    return rStrip_dfs(nums[:-1])


def copy(src, src_pos, des, des_pos, n: int) -> None:
    for i in range(n): des[des_pos + i] = src[src_pos + i]


def swap(ary, i: int, j: int) -> None:
    ary[i], ary[j] = ary[j], ary[i]


def maxSizeElement(lists: List[List[any]]) -> Optional[list]:
    if not len(lists): return None
    r = lists[0]
    for l_ in lists:
        if len(l_) > len(r): r = l_
    return r


def minSizeElement(lists: List[List[any]]) -> Optional[list]:
    if not len(lists): return None
    r = lists[0]
    for l_ in lists:
        if len(l_) < len(r): r = l_
    return r
