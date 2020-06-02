package minimumTotal;

import java.util.List;

//DFS with memorization
class SolutionDFS {
    public int minimumTotal(List<List<Integer>> triangle) {
        Integer[][] found = new Integer[triangle.size()][triangle.size()];
        return minsumDFS(triangle, 0, 0, found);
    }

    int minsumDFS(List<List<Integer>> triangle, int i, int j, Integer[][] found) {
        if (i >= triangle.size()) return 0;
        if (found[i][j] != null) return found[i][j];

        int down_left = minsumDFS(triangle, i + 1, j, found);
        int down_right = minsumDFS(triangle, i + 1, j + 1, found);
        found[i][j] = triangle.get(i).get(j) + Math.min(down_left, down_right);

        return found[i][j];

    }
}
