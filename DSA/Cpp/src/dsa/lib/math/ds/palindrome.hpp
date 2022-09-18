#pragma once

#include <string>

namespace dsa::lib::math::ds {

class Palindrome {
 public:
    /**
     * LeetCode5
     * Dynamic Programming
     * dp[i][j] represents whether it's palindrome from i to j(including a[j])
     * s[i] ==s[j] and (dp[i+1][j-1] or j -i < 3) => dp[i][j]
    */
    std::string longestPalindrome(std::string &s) {
        int n = (int) s.size();
        if (n <= 1) return s;

        // Filling in dp table and get the range of the longest palindrome substring.
        int start = 0, end = 0;
        bool dp[n][n];
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                dp[i][j] = s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1]);

                if (dp[i][j] && j - i > end - start) {
                    start = i;
                    end = j;
                }
            }
        }
        return s.substr(start, end - start + 1);
    }

    /**
     * Expand around center
     * O(n^2), Constant Space
     */
    std::string longestPalindrome1(std::string &s) {
        if (s.size() <= 1) return s;

        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            int lenOdd = expandAroundCenter(s, i, i);
            int lenEven = expandAroundCenter(s, i, i + 1);
            int lenMax = std::max(lenOdd, lenEven);

            if (lenMax > end - start + 1) {
                start = i - (lenMax - 1) / 2;
                end = i + lenMax / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
    static int expandAroundCenter(std::string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return right - left - 1;
    }
};

}