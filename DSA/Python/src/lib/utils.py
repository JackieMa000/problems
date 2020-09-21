from typing import List


def array_rstrip(array: List[int]) -> List[int]:
    """
    Remove the trailing 0s from an array
    Rule:
    1. Array length is 0 -> return empty array
    2. Array length is 1, the element is 0 -> return empty array
    3. Array last element is not 0 -> return array
    4. Array length is bigger than 1, last element is 0 -> remove the trailing 0s by loop.
    """
    return _array_rstrip_it(array)


def _array_rstrip_it(array: List[int]) -> List[int]:
    if len(array) == 0 or (len(array) == 1 and array[0] == 0): return []
    while not array[(-1)]: array.pop(-1)
    return array


def _array_rstrip_dfs(array: List[int]) -> List[int]:
    if len(array) == 0 or (len(array) == 1 and array[0] == 0): return []
    if array[-1] != 0: return array
    return _array_rstrip_dfs(array[:-1])
