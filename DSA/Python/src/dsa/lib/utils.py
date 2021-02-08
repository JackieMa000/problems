from typing import List


def array_rstrip(ary: List[int]) -> List[int]:
    """
    Remove the trailing 0s from an array
    Rule:
    1. Array length is 0 -> return empty array
    2. Array length is 1, the element is 0 -> return empty array
    3. Array last element is not 0 -> return array
    4. Array length is bigger than 1, last element is 0 -> remove the trailing 0s by loop.
    """
    return _array_rstrip_it(ary)


def _array_rstrip_it(ary: List[int]) -> List[int]:
    if not len(ary) or (len(ary) == 1 and ary[0] == 0): return []
    while not ary[(-1)]: ary.pop(-1)
    return ary


def _array_rstrip_dfs(ary: List[int]) -> List[int]:
    if not len(ary) or (len(ary) == 1 and ary[0] == 0): return []
    if ary[-1] != 0: return ary
    return _array_rstrip_dfs(ary[:-1])


def array_copy(src: List[int], src_pos, des: List[int], des_pos, length) -> None:
    for i in range(length): des[des_pos + i] = src[src_pos + i]


def array_swap(ary, i, j) -> None:
    ary[i], ary[j] = ary[j], ary[i]
