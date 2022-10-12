#pragma once

#include <vector>
#include <climits>

#include "dsa/lib/utils/algorithm.hpp"
#include "dsa/lib/utils/math.hpp"

namespace dsa::lib::math::ds {

class Triangle {
 public:
    // LeetCode120
    // dfs
    int minimumTotal(std::vector<std::vector<int>> &triangle) {
        return dfs(triangle, 0, 0);
    }
    static int dfs(std::vector<std::vector<int>> &triangle, int i, int j) {
        if (i >= triangle.size()) return 0;

        int downLeft = dfs(triangle, i + 1, j);
        int downRight = dfs(triangle, i + 1, j + 1);
        return triangle[i][j] + std::min(downLeft, downRight);
    }

    // dfs with memorization
    int minimumTotal1(std::vector<std::vector<int>> &triangle) {
        auto m = triangle.size();
        std::vector<std::vector<int>> memo(m, std::vector<int>(m, INT_MIN));
        return dfs1(triangle, 0, 0, memo);
    }
    static int dfs1(std::vector<std::vector<int>> &triangle, int i, int j, std::vector<std::vector<int>> &memo) {
        if (i >= triangle.size()) return 0;
        if (memo[i][j] != INT_MIN) return memo[i][j];

        int downLeft = dfs1(triangle, i + 1, j, memo);
        int downRight = dfs1(triangle, i + 1, j + 1, memo);
        memo[i][j] = triangle[i][j] + std::min(downLeft, downRight);

        return memo[i][j];
    }

    // dfs with memorization. using dsa Matrix.
    int minimumTotal2(std::vector<std::vector<int>> &triangle) {
        auto m = triangle.size();
        MatrixHeap<int> memo(m, m, INT_MIN);
        return dfs2(triangle, 0, 0, memo);
    }
    static int dfs2(std::vector<std::vector<int>> &triangle, int i, int j, MatrixHeap<int> &memo) {
        if (i >= triangle.size()) return 0;
        if (memo[i][j] != INT_MIN) return memo[i][j];

        int downLeft = dfs2(triangle, i + 1, j, memo);
        int downRight = dfs2(triangle, i + 1, j + 1, memo);
        memo[i][j] = triangle[i][j] + std::min(downLeft, downRight);

        return memo[i][j];
    }

//    Dynamic Programming. Bottom Up
    int minimumTotal3(std::vector<std::vector<int>> &triangle) {
        int m = triangle.size();
        std::vector<std::vector<int>> dp(triangle);

        for (int i = m - 2; i >= 0; --i) {
            auto n = triangle[i].size();
            for (int j = 0; j < n; ++j) {
                dp[i][j] = triangle[i][j] + std::min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }

        return dp[0][0];
    }

//    Dynamic Programming. Bottom Up. Space Optimized
    int minimumTotal4(std::vector<std::vector<int>> &triangle) {
        int m = triangle.size();
        int dp[m];
        dsa::copy(triangle[m - 1].begin(), triangle[m - 1].end(), dp);

        for (int i = m - 2; i >= 0; --i) {
            auto n = triangle[i].size();
            for (int j = 0; j < n; ++j) {
                dp[j] = triangle[i][j] + std::min(dp[j], dp[j + 1]);
            }
        }

        return dp[0];
    }

};

}
