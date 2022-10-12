package dsa.lib.math.ds;


import java.util.List;

public class Triangle {
    // LeetCode120
    //DFS
    public int minimumTotal(List<List<Integer>> triangle) {
        return dfs(triangle, 0, 0);
    }

    int dfs(List<List<Integer>> triangle, int i, int j) {
        if (i >= triangle.size()) return 0;

        int downLeft = dfs(triangle, i + 1, j);
        int downRight = dfs(triangle, i + 1, j + 1);

        return triangle.get(i).get(j) + Math.min(downLeft, downRight);
    }

    //DFS with memorization
    public int minimumTotal1(List<List<Integer>> triangle) {
        final int m = triangle.size();
        Integer[][] memo = new Integer[m][m];
        return dfs1(triangle, 0, 0, memo);
    }

    int dfs1(List<List<Integer>> triangle, int i, int j, Integer[][] memo) {
        if (i >= triangle.size()) return 0;
        if (memo[i][j] != null) return memo[i][j];

        int downLeft = dfs1(triangle, i + 1, j, memo);
        int downRight = dfs1(triangle, i + 1, j + 1, memo);
        memo[i][j] = triangle.get(i).get(j) + Math.min(downLeft, downRight);

        return memo[i][j];
    }

    //    Dynamic Programming
    public int minimumTotal2(List<List<Integer>> triangle) {
        // dp initialize
        int m = triangle.size();
        int[][] dp = new int[m][m];
        copy(triangle.get(m - 1), 0, dp[m - 1], 0, triangle.get(m - 1).size());

        // dp formula
        for (int i = m - 2; i >= 0; i--) {
            int n = triangle.get(i).size();
            for (int j = 0; j < n; j++) {
                dp[i][j] = triangle.get(i).get(j) + Math.min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }

        // dp result
        return dp[0][0];
    }

    //    dp with Space Optimized
    public int minimumTotal3(List<List<Integer>> triangle) {
        // dp initialize
        int m = triangle.size();
        int[] dp = new int[m];
        copy(triangle.get(m - 1), 0, dp, 0, triangle.get(m - 1).size());

        // dp formula
        for (int i = m - 2; i >= 0; i--) {
            int n = triangle.get(i).size();
            for (int j = 0; j < n; j++) {
                dp[j] = triangle.get(i).get(j) + Math.min(dp[j], dp[j + 1]);
            }
        }

        // dp result
        return dp[0];
    }

    public static void copy(List<Integer> src, int srcPos, int[] des, int desPos, int n) {
        for (int i = 0; i < n; ++i) des[desPos + i] = src.get(srcPos + i);
    }

}

