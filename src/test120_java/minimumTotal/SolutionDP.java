package minimumTotal;

import java.util.List;

public class SolutionDP {
    public int minimumTotal(List<List<Integer>> triangle) {
        // dp initialize
        int m = triangle.size();
        int[][] dp = new int[m][m];
        for (int j = 0; j < triangle.get(m - 1).size(); j++) {
            dp[m - 1][j] = triangle.get(m - 1).get(j);
        }
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
}
