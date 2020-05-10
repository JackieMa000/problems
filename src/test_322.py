import sys
import unittest
from typing import List


class Solution:
    # Brute Force. Backtracking
    def coinChange(self, coins: List[int], amount: int) -> int:
        return self._dfs(0, coins, amount)

    def _dfs(self, i: int, coins: List[int], amount: int) -> int:
        if amount <= 0: return amount

        if i < len(coins):
            max_val = amount // coins[i]
            min_cost = sys.maxsize
            for x in range(max_val + 1):
                res = self._dfs(i + 1, coins, amount - x * coins[i])
                if res >= 0:
                    min_cost = min(min_cost, res + x)
            return -1 if min_cost == sys.maxsize else min_cost

        return -1

    # Recursion. Divide & Conquer. Memorization. Top down
    def coinChange_3(self, coins: List[int], amount: int) -> int:
        count = [amount + 1] * (amount + 1)
        return self.dfs(coins, amount, count)

    def dfs(self, coins: List[int], amount: int, count: List[int]) -> int:
        # terminator
        if amount <= 0: return amount

        if count[amount] < amount + 1:
            return count[amount]

        # Recursive case
        minimum = amount + 1
        for j in range(len(coins)):
            sub = self.dfs(coins, amount - coins[j], count)
            if sub >= 0:
                minimum = min(minimum, sub + 1)
        count[amount] = minimum if minimum < amount + 1 else -1

        return count[amount]

    # Dynamic Programming. Bottom up
    def coinChange_2(self, coins: List[int], amount: int) -> int:
        dp = [amount + 1] * (amount + 1)
        dp[0] = 0
        for i in range(1, amount + 1):
            prev = amount
            for j in range(len(coins)):
                if i >= coins[j]:
                    prev = min(prev, dp[i - coins[j]])
            dp[i] = prev + 1
        return -1 if dp[amount] > amount else dp[amount]

    # Dynamic Programming. Bottom up. dp[i] = min{dp[i-coins[j]} + 1. j: (0, n-1)
    def coinChange_1(self, coins: List[int], amount: int) -> int:
        dp = [amount + 1] * (amount + 1)
        dp[0] = 0
        for i in range(1, amount + 1):
            for j in range(len(coins)):
                if i >= coins[j]:
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1)
        return dp[amount] if dp[amount] != amount + 1 else -1


class MyTestCase(unittest.TestCase):
    def test_something(self):
        self.assertEqual(-1, Solution().coinChange([2], 1))
        self.assertEqual(-1, Solution().coinChange([2], 3))
        self.assertEqual(2, Solution().coinChange([1, 2, 5], 3))
        self.assertEqual(3, Solution().coinChange([1, 2, 5], 11))


if __name__ == '__main__':
    unittest.main()
