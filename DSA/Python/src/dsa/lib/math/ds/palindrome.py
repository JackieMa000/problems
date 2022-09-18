class Palindrome:
    def longestPalindrome(self, s: str) -> str:
        """
        # LeetCode5
        # Dynamic Programming
        # dp[i][j] represents whether it's palindrome from i to j(including a[j])
        # s[i] ==s[j] and (dp[i+1][j-1] or j -i < 3) => dp[i][j]
        """
        if not s or len(s) <= 1: return s

        n = len(s)
        # Initialize for DP table and get the range of the longest palindrome substring
        start, end = 0, 0
        dp = [[False for _ in range(n)] for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i, n):
                dp[i][j] = (s[i] == s[j] and (j - i < 3 or dp[i + 1][j - 1]))

                if dp[i][j] and j - i > end - start:
                    start, end = i, j
        return s[start:end + 1]

    def longestPalindrome1(self, s: str) -> str:
        """
            # Expand around center
            # O(n^2), Constant Space
        """
        if not s or len(s) <= 1: return s

        n = len(s)
        start, end = 0, 0
        for i in range(n):
            lenOdd = self.expand_around_center(s, i, i)  # Palindrome Odd case
            lenEven = self.expand_around_center(s, i, i + 1)  # Palindrome Even case
            lenMax = max(lenOdd, lenEven)
            if lenMax > end - start + 1:
                start = i - (lenMax - 1) // 2
                end = i + lenMax // 2
        return s[start:end + 1]

    def expand_around_center(self, s: str, left: int, right: int) -> int:
        while 0 <= left and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return right - left - 1
