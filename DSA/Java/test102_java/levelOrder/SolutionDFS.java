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
//        terminator
        if (root == null) return;

//        Go;
//        level is the same as index, starts with 0
        if (result.size() < level + 1) {
            result.add(new LinkedList<>());
        }


//        get the current level from the result, add the current node value to the current level
        result.get(level).add(root.val);

//        recursive case, drill down
        dfs(root.left, level + 1, result);
        dfs(root.right, level + 1, result);
    }
}
