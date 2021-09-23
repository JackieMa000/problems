from typing import List, Optional, Any, Callable


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
