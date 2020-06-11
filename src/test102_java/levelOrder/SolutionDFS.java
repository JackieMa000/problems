package levelOrder;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class SolutionDFS {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        dfs(root, 0, result);
        return result;
    }

    private void dfs(TreeNode root, int level, List<List<Integer>> result) {
        if (root == null) return;
        if (result.size() < level + 1) result.add(new LinkedList<>());
        result.get(level).add(root.val);
        dfs(root.left, level + 1, result);
        dfs(root.right, level + 1, result);
    }
}
