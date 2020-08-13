package isValidBST;

import nodes.BinaryTreeNode;

//inorder traversal.
//inorder Rule: left(all nodes) < root < right(all nodes), or prev < cur.
public class Scratch1 {
    private BinaryTreeNode prev = null;

    public boolean isValidBST(BinaryTreeNode root) {
        // Terminator
        if (root == null) return true;

//        Left
        if (!isValidBST(root.left)) return false;

//        Process or Condition
        if (prev != null && prev.val >= root.val) return false;

//        Right, recursive
        prev = root;
        return isValidBST(root.right);
    }
}
