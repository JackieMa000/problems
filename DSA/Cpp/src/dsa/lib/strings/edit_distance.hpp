#pragma once

#include <string>

class EditDistance {
 public:
    /**
    * LeetCode72
    * Dynamic Programming
    * dp[i][j]: Represents the minimum number of operations required to convert first i chars of world1 to
    * first j chars of word2, including word1[i] and word2[j].  word1[:i+1] to word2[:j+1].
    */
    int minDistance(std::string word1, std::string word2) {
        int m = word1.length(), n = word2.length();
        int m1 = m + 1, n1 = n + 1;
//        create db table
        int dp[m1][n1];

//        initialize db table
        for (int i = 0; i < m1; ++i) dp[i][0] = i;
        for (int j = 0; j < n1; ++j) dp[0][j] = j;

//       Filling in db table
        for (int i = 1; i < m1; ++i) {
            for (int j = 1; j < n1; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int x = 1 + dp[i][j - 1];
                    int y = 1 + dp[i - 1][j];
                    int z = 1 + dp[i - 1][j - 1];
                    dp[i][j] = std::min({x, y, z});
                }
            }
        }

        return dp[m][n];
    }

    // Brutal Force. Redundant computation without caching.
    int minDistance1(std::string word1, std::string word2) {
        size_t m = word1.length(), n = word2.length();

        if (m == 0) return n;
        else if (n == 0) return m;

        if (word1[0] == word2[0]) {
            return minDistance(word1.substr(1, m - 1), word2.substr(1, n - 1));
        }

        auto x = 1 + minDistance(word1.substr(1, m - 1), word2);
        auto y = 1 + minDistance(word1, word2.substr(1, n - 1));
        auto z = 1 + minDistance(word1.substr(1, m - 1), word2.substr(1, n - 1));
        return std::min({x, y, z});
    }
};