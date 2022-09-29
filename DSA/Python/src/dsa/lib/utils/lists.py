from typing import List, Any, Callable, Optional
from copy import deepcopy


def _lstripIt(nums: List[int]) -> List[int]:
    i = 0
    while i < len(nums) and nums[i] == 0: i += 1
    return nums if i == 0 else nums[i:]


def _lstripDfs(nums: List[int]) -> List[int]:
    if not len(nums): return nums
    return nums if nums[0] != 0 else _lstripDfs(nums[1:])


def _rstripIt(nums: List[int]) -> List[int]:
    n = i = len(nums)
    while i > 0 and nums[i - 1] == 0: i -= 1
    return nums if i == n else nums[:i]


def _rstripDfs(nums: List[int]) -> List[int]:
    if not len(nums): return nums
    return nums if nums[-1] != 0 else _rstripDfs(nums[:-1])


def _stripIt(nums: List[int]) -> List[int]:
    n = len(nums)
    i = 0
    j = n
    while i < j and nums[i] == 0: i += 1
    while i < j and nums[j - 1] == 0: j -= 1
    return nums if (i == 0 and j == n) else nums[i:j]


def _stripDfs(nums: List[int]) -> List[int]:
    n = len(nums)
    if not n: return nums

    is_first0 = nums[0] == 0
    is_last0 = nums[-1] == 0
    i = 1 if is_first0 else 0
    j = n - 1 if is_last0 and n > 1 else n
    return nums if (nums[0] != 0 and nums[-1] != 0) else _stripDfs(nums[i:j])


def lstrip(nums: List[int]) -> List[int]:
    """
    Remove all leading 0s from the given list.
    :param nums:
    :return:
    """
    return _lstripIt(nums)


def rstrip(nums: List[int]) -> List[int]:
    """
    Remove all trailing 0s from the given list.
    :param nums:
    :return:
    """
    return _rstripIt(nums)


def strip(nums: List[int]) -> List[int]:
    """
    Remove all leading and trailing 0s from the given list.
    :param nums:
    :return:
    """
    return _stripIt(nums)


def trim(nums: List[int]) -> List[int]:
    """
    Remove all leading and trailing 0s from the given list.
    :param nums:
    :return:
    """
    return strip(nums)


def copy(src: List[Any], src_pos: int, des: List[Any], des_pos: int, n: int) -> None:
    for i in range(n):
        if isinstance(src[src_pos + i], list) and isinstance(des[des_pos + i], list):
            copy(src[src_pos + i], 0, des[des_pos + i], 0, len(src[src_pos + i]))
        else:
            des[des_pos + i] = deepcopy(src[src_pos + i])


def _copyOfRangeDfs(result: List[Any], origin: List[Any], from_: int, to: int) -> None:
    for i in range(from_, to):
        if isinstance(origin[i], list):
            r = []
            _copyOfRangeDfs(r, origin[i], 0, len(origin[i]))
            result.append(r)
        else:
            result.append(deepcopy(origin[i]))


def copyOf(origin: List[Any], n: int) -> List[Any]:
    r = []
    _copyOfRangeDfs(r, origin, 0, n)
    return r


def copyOfRange(origin: List[Any], from_: int, to: int) -> List[Any]:
    if to - from_ < 0: raise IndexError()
    r = []
    _copyOfRangeDfs(r, origin, from_, to)
    return r


def swap(ls: List[Any], i: int, j: int) -> None:
    ls[i], ls[j] = ls[j], ls[i]


def comp(lists: List[List[Any]], compare: Callable[[Any, Any], bool]) -> Optional[list]:
    if not len(lists): return None
    r = lists[0]
    for e in lists:
        if compare(e, r): r = e
    return r


def maxSize(lists: List[List[Any]]) -> Optional[list]:
    return comp(lists, lambda x, y: len(x) > len(y))


def minSize(lists: List[List[Any]]) -> Optional[list]:
    return comp(lists, lambda x, y: len(x) < len(y))


def binary_search(nums: List[int], target: int) -> int:
    """
    :param nums:
    :param target:
    :return: the index of target in nums. -1 means did not find the target.
    """
    left, right = 0, len(nums) - 1
    while left <= right:
        mid = left + (right - left) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1
