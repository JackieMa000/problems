package dsa.lib.strings;

public class EditDistance {
    /**
     * LeetCode72
     * Dynamic Programming
     * dp[i][j]: Represents the minimum number of operations required to convert first i chars of world1 to
     * first j chars of word2, including word1[i] and word2[j].  word1[:i+1] to word2[:j+1].
     */
    public int minDistance(String word1, String word2) {
        final int m = word1.length(), n = word2.length();

//        create db table
        final int m1 = m + 1, n1 = n + 1;
        int[][] dp = new int[m1][n1];

//        initialize db table
//        dp[i][0] means word2 is emtpy string.
        for (int i = 0; i < m1; i++) dp[i][0] = i;
        for (int j = 0; j < n1; j++) dp[0][j] = j;

//        Filling in the db table
        for (int i = 1; i < m1; i++) {
            for (int j = 1; j < n1; j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.min(dp[i][j - 1], Math.min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
                }
            }
        }

        return dp[m][n];
    }

    // Brutal Force. dfs
    public int minDistance1(String word1, String word2) {
        final int m = word1.length(), n = word2.length();

        if (m == 0) return n;
        else if (n == 0) return m;

        if (word1.charAt(0) == word2.charAt(0)) {
            return minDistance(word1.substring(1), word2.substring(1));
        }

//        insert word2[0] before word1[0]
        int insert = 1 + minDistance(word1, word2.substring(1));
//        delete word1[0]
        int delete = 1 + minDistance(word1.substring(1), word2);
//        replace word1[0] with word2[0]
        int replace = 1 + minDistance(word1.substring(1), word2.substring(1));

        return Math.min(insert, Math.min(delete, replace));
    }
}
