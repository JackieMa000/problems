import unittest
from typing import List


# Map or Set
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3: return []
        # 判重
        nums.sort()

        # 判重
        res = set()

        n = len(nums)
        for i in range(n - 2):
            a = nums[i]
            expected_c = set()
            # 判重
            if i >= 1 and nums[i] == nums[i - 1]: continue

            for j in range(i + 1, n):
                cur_b = nums[j]
                if cur_b in expected_c:
                    res.add((a, -(a + cur_b), cur_b))
                else:
                    expected_c.add(-(a + cur_b))

        return [list(x) for x in res]

    def threeSum_3(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3: return []
        # 判重
        nums.sort()

        # 判重
        res = set()

        alst = nums[:-2]
        for i, a in enumerate(alst):
            expected_c = set()
            # 判重
            if i >= 1 and a == nums[i - 1]: continue

            blst = nums[i + 1:]
            for cur_b in blst:
                if cur_b in expected_c:
                    res.add((a, -(a + cur_b), cur_b))
                else:
                    expected_c.add(-(a + cur_b))

        return [list(item) for item in res]

    def threeSum_2(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3: return []
        # 判重
        nums.sort()

        # 判重，去除c重复
        res = set()
        for i, a in enumerate(nums[:-2]):
            # 判重, 去除a重复
            if i >= 1 and a == nums[i - 1]: continue

            # There's two scenarios here. Current moment and in the past. We need to compare a, b, c value.

            # Saving what c should be when we have a, b.
            # {c: 1}
            # 这里也可以用set
            expected_c = {}
            for cur_b in nums[i + 1:]:
                # 这里交给res set来去重
                # Find whether or not current element(b) equals to what c should be when we have a, b in the past

                # Past Scenario
                # Current element(b) equals to what c should be when we have a, b in the past.
                # a(fixed) + b(past) + current element(b) = 0, so b(past) = -(a(fixed) + current element(b))
                if cur_b in expected_c:
                    res.add((a, -(a + cur_b), cur_b))

                # Current Scenario
                # Here, b means b, c means c.
                # Current element(b) not equals to what c should be when we have a, b in the past.
                # a(fixed) + b(past) + current_element(b) != 0.
                # So we computer and save what c should be when have a and current element as b in the current moment.
                # So a(fixed) + b(now) + c = 0, c = -(a(fixed) + b(now))
                else:
                    expected_c[-(a + cur_b)] = 1

        return [list(item) for item in res]


class MyTestCase(unittest.TestCase):
    def test_something(self):
        self.assertEqual([[0, 0, 0]], Solution().threeSum([0, 0, 0, 0]))
        self.assertEqual([[-2, 0, 2]], Solution().threeSum([-2, 0, 0, 2, 2]))
        self.assertEqual([[-1, 0, 1]], Solution().threeSum([-1, 0, 1, 0]))
        self.assertEqual([[-1, -1, 2], [-1, 0, 1]], Solution().threeSum([-1, 0, 1, 2, -1, -4]))
