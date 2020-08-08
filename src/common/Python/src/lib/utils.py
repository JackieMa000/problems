from typing import List


def array_rstrip(array: List[int]) -> List[int]:
    # // FixMe: Edge cases
    while not array[(-1)]:
        array.pop(-1)
    return array


def array_rstrip_dfs(array: List[int]) -> List[int]:
    # ToDo
    pass
