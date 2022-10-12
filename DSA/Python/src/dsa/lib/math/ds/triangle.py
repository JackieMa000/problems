from typing import List, Optional


class Triangle:
    # 回溯 DFS
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        """
        LeetCode120
        """
        return self.dfs(triangle, 0, 0)

    def dfs(self, triangle: List[List[int]], i: int, j: int) -> int:
        # terminator
        if i >= len(triangle): return 0
        # Recursive
        down_left = self.dfs(triangle, i + 1, j)
        down_right = self.dfs(triangle, i + 1, j + 1)
        return triangle[i][j] + min(down_left, down_right)

    # DFS. Memorization
    def minimumTotal1(self, triangle: List[List[int]]) -> int:
        memo = [[None for _ in range(len(triangle[row]))] for row in range(len(triangle))]
        return self.dfs1(triangle, 0, 0, memo)

    def dfs1(self, triangle: List[List[int]], i: int, j: int, memo: List[List[Optional[int]]]) -> int:
        # terminator
        if i >= len(triangle): return 0
        if memo[i][j] is not None: return memo[i][j]
        # Recursive
        down_left = self.dfs1(triangle, i + 1, j, memo)
        down_right = self.dfs1(triangle, i + 1, j + 1, memo)
        memo[i][j] = triangle[i][j] + min(down_left, down_right)

        return memo[i][j]

    # DP dp[i][j] means the minimum path sum from bottom to the position [i, j]
    def minimumTotal2(self, triangle: List[List[int]]) -> int:
        # dp Initialize
        m = len(triangle)
        dp = [[0 for _ in range(len(triangle[row]))] for row in range(m)]
        dp[m - 1] = [x for x in triangle[m - 1]]

        # dp formula
        for i in range(m - 2, -1, -1):
            n = len(triangle[i])
            for j in range(n):
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1])

        # dp result
        return dp[0][0]

    # DP 一维数组. 状态压缩. Only saving the result of last row into dp table.
    # min_sum[j] means the minimum path sum from bottom to position j of the current row.
    def minimumTotal3(self, triangle: List[List[int]]) -> int:
        # dp Initialize
        m = len(triangle)
        dp = [x for x in triangle[m - 1]]

        # dp formula
        m = len(triangle)
        for i in range(m - 2, -1, -1):
            n = len(triangle[i])
            for j in range(n):
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1])

        # dp result
        return dp[0]
