from typing import List


class Sort:
    def sortColors(self, nums: List[int]) -> None:
        """
        LeetCode75
        QuickSort Solution
        p0 [0, p0) == 0
        p1 [p0, i) == 1 i: current traversing position
        p2 (p2, n-1] == 2
        """
        n = len(nums)
        if n < 2: return

        p0 = 0
        i = 0
        p2 = n - 1

        while i <= p2:
            if nums[i] == 0:
                nums[i], nums[p0] = nums[p0], nums[i]
                p0 += 1
                # p0 is checked, increase i
                i += 1
            elif nums[i] == 1:
                i += 1
            else:
                # nums[i] == 2
                nums[i], nums[p2] = nums[p2], nums[i]
                # p2 is unchecked.
                p2 -= 1

    def sortColors1(self, nums: List[int]) -> None:
        """
        LeetCode75
        CountingSort Solution
        sums[]: saving the count of occurrence of the num. index is the num, value is the count of occurrence of the num.
        """
        # initialize sums from 0 to len(nums) - 1
        sums = [0 for _ in range(max(nums) + 1)]
        for i in range(len(nums)):
            sums[nums[i]] += 1

        count = 0
        for i in range(len(sums)):
            for _ in range(sums[i]):
                nums[count] = i
                count += 1
