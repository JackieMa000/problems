package isValidBST;

/*
BST. Binary Search Tree Defination.
All the nodes on the left is smaller than the root node. All the nodes on the right
is bigger than the root node.
 */

public class SolutionDFS {
    private TreeNode prev = null;

    public boolean isValidBST(TreeNode root) {
        if (root == null) return true;
        if (!isValidBST(root.left)) return false;
        if (prev != null && prev.val >= root.val) return false;
        prev = root;
        return isValidBST(root.right);
    }
}
