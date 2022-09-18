package dsa.lib.math.ds;

public class Palindrome {
    /**
     * LeetCode5
     * Dynamic Programming
     * dp[i][j] represents whether it's palindrome from i to j(including a[j])
     * s[i] ==s[j] and (dp[i+1][j-1] or j -i < 3) => dp[i][j]
     */
    public String longestPalindrome(String s) {
        if (s == null || s.length() <= 1) return s;
        int n = s.length();

//        Filling in dp table and get the range of the longest palindrome substring.
        int start = 0, end = 0;
        boolean[][] dp = new boolean[n][n];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                dp[i][j] = s.charAt(i) == s.charAt(j) && (j - i < 3 || dp[i + 1][j - 1]);

                if (dp[i][j] && j - i > end - start) {
                    start = i;
                    end = j;
                }
            }
        }
        return s.substring(start, end + 1);
    }

    /**
     * Expand around center
     * O(n^2), Constant Space
     */
    public String longestPalindrome1(String s) {
        if (s == null || s.length() <= 1) return s;

        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            int lenOdd = expandAroundCenter(s, i, i);
            int lenEven = expandAroundCenter(s, i, i + 1);
            int lenMax = Math.max(lenOdd, lenEven);

            if (lenMax > end - start + 1) {
                start = i - (lenMax - 1) / 2;
                end = i + lenMax / 2;
            }
        }
        return s.substring(start, end + 1);
    }

    private int expandAroundCenter(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            --left;
            ++right;
        }
        return right - left - 1;
    }
}
