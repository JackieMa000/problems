from typing import List


def lstripIt(nums: List[int]) -> List[int]:
    i = 0
    while i < len(nums) and nums[i] == 0: i += 1
    return nums if i == 0 else nums[i:]


def lstripDfs(nums: List[int]) -> List[int]:
    if not len(nums): return nums
    return nums if nums[0] != 0 else lstripDfs(nums[1:])


def rstripIt(nums: List[int]) -> List[int]:
    n = i = len(nums)
    while i > 0 and nums[i - 1] == 0: i -= 1
    return nums if i == n else nums[:i]


def rstripDfs(nums: List[int]) -> List[int]:
    if not len(nums): return nums
    return nums if nums[-1] != 0 else rstripDfs(nums[:-1])


def stripIt(nums: List[int]) -> List[int]:
    n = len(nums)
    i = 0
    j = n
    while i < j and nums[i] == 0: i += 1
    while i < j and nums[j - 1] == 0: j -= 1
    return nums if (i == 0 and j == n) else nums[i:j]


def stripDfs(nums: List[int]) -> List[int]:
    n = len(nums)
    if not n: return nums

    is_first0 = nums[0] == 0
    is_last0 = nums[-1] == 0
    i = 1 if is_first0 else 0
    j = n - 1 if is_last0 and n > 1 else n
    return nums if (nums[0] != 0 and nums[-1] != 0) else stripDfs(nums[i:j])
