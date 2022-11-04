from typing import List


class Solution:
    # 空间压缩，滚动数组
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if not prices: return 0

        n = len(prices)
        # When K is larger than the prices.size, it goes to the same solution as what stocks.a122 does.
        if k > n:
            maxProfit = 0
            for i in range(len(prices) - 1):
                if prices[i + 1] > prices[i]:
                    maxProfit += (prices[i + 1] - prices[i])
            return maxProfit

        MP = [[[0, 0] for _ in range(k + 1)] for _ in range(2)]
        # Initialize the data for the first day
        MP[0] = [[0, 0]] + [[0, -prices[0]] for _ in range(k)]

        for i in range(1, n):
            x, y = i & 1, (i - 1) & 1
            for kk in range(1, k + 1):
                MP[x][kk][1] = max(MP[y][kk][1], MP[y][kk - 1][0] - prices[i])
                MP[x][kk][0] = max(MP[y][kk][0], MP[y][kk][1] + prices[i])

        return max(map(lambda x: x[0], MP[(n - 1) & 1]))

    def maxProfit_1(self, k: int, prices: List[int]) -> int:
        if not prices: return 0

        n = len(prices)
        # When K is larger thani the prices.size, it goes to the same solution as what stocks.a122 does.
        if k > n:
            maxProfit = 0
            for i in range(len(prices) - 1):
                if prices[i + 1] > prices[i]:
                    maxProfit += (prices[i + 1] - prices[i])
            return maxProfit

        MP = [[[0, 0] for _ in range(k + 1)] for _ in range(n)]
        # Initialize the data for the first day
        MP[0] = [[0, 0]] + [[0, -prices[0]] for _ in range(k)]

        for i in range(1, n):
            for kk in range(1, k + 1):
                MP[i][kk][1] = max(MP[i - 1][kk][1], MP[i - 1][kk - 1][0] - prices[i])
                MP[i][kk][0] = max(MP[i - 1][kk][0], MP[i - 1][kk][1] + prices[i])

        return max(map(lambda x: x[0], MP[n - 1]))
