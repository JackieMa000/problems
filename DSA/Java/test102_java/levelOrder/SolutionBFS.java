package levelOrder;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class SolutionBFS {

    /**
     * queue -> levelResult -> Result
     */
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
//        edge case
        if (root == null) return result;

        Queue<TreeNode> queue = new LinkedList<>();
//        initialize the queue
        queue.add(root);
        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            List<Integer> levelResult = new ArrayList<>();

//                add the current level nodes to the level result
            for (int i = 0; i < levelSize; i++) {
//                consume the queue for the current level
                TreeNode node = queue.poll();
                levelResult.add(node.val);

//                produce the children for next level
                if (node.left != null) queue.add(node.left);
                if (node.right != null) queue.add(node.right);
            }
            result.add(levelResult);
        }
        return result;
    }
}
