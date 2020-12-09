from typing import List


# LeetCode15
class ThreeSum:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        return self.threeSum1(nums)

    def threeSum1(self, nums: List[int]) -> List[List[int]]:
        """
        Rule: SortFind, Double Pointers
        Sort, remove duplicates

        loop a:
            remove duplicates for a
            double pointers for b, c
                a + b + c > 0 -> c shift left
                a + b + c < 0 -> b shift right
                a + b + c = 0 -> 1) save result.
                                2) remove duplicates for b, c
                                3) b shift right, c shift left.
        """
        n: int = len(nums)
        result = []

        nums.sort()
        for i in range(n - 2):
            if i >= 1 and nums[i] == nums[i - 1]: continue
            left, right = i + 1, n - 1
            while left < right:
                sum = nums[i] + nums[left] + nums[right]
                if sum == 0:
                    while left < right and nums[left] == nums[left + 1]: left += 1
                    while left < right and nums[right] == nums[right - 1]: right -= 1
                    result.append([nums[i], nums[left], nums[right]])
                    left += 1
                    right -= 1
                elif sum < 0:
                    left += 1
                else:
                    right -= 1

        return result

    def threeSum2(self, nums: List[int]) -> List[List[int]]:
        """
        Rule: Hash Table
        Hash Table bset for b.
        sort, hash set, remove duplicates for the result.
        find b in hash table, look back.

        a + b + c = 0 -> b = -(a + c)
        loop a:
            loop c:
                b = -(a + c)
                if find b in hash table, save result
                else, save cur(c) in hash table
        """
        n: int = len(nums)
        result = set()

        nums.sort()
        for i in range(n - 2):
            b_set = set()
            for j in range(i + 1, n):
                b = -(nums[i] + nums[j])
                if b in b_set:
                    result.add(((nums[i]), b, (nums[j])))
                else:
                    b_set.add(nums[j])

        return [list(x) for x in result]
