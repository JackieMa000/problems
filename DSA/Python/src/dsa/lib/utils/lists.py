from typing import List, Any
from copy import deepcopy

from dsa.lib.utils.algorithm import stripper


def lstrip(nums: List[int]) -> List[int]:
    """
    Remove all leading 0s from the given list.
    :param nums:
    :return:
    """
    return stripper.lstripIt(nums)


def rstrip(nums: List[int]) -> List[int]:
    """
    Remove all trailing 0s from the given list.
    :param nums:
    :return:
    """
    return stripper.rstripIt(nums)


def strip(nums: List[int]) -> List[int]:
    """
    Remove all leading and trailing 0s from the given list.
    :param nums:
    :return:
    """
    return stripper.stripIt(nums)


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
