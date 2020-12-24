package experiment.isValidBST;

import dsa.nodes.BinaryTreeNode;

//inorder traversal.
//recursion
//inorder Rule: left(all nodes) < root < right(all nodes), or prev < cur.
//left subTree initial value: prev = null, right subTree: prev = root;
public class Solution1 {
    //BinaryTreeNode prev should be global scope, need to change the prev value in the subroutine(callee) for the parent routine(caller)
    private BinaryTreeNode prev = null; // initial value for the left subTree

    public boolean isValidBST(BinaryTreeNode root) {
        // Terminator
        if (root == null) return true;

//        Left subTree. Recursive Case
        if (!isValidBST(root.left)) return false;

//       Back. Process or Condition
        if (prev != null && prev.val >= root.val) return false;

//        Right subTree, recursive case. drill down
        prev = root; // initial value for the right subTree
        return isValidBST(root.right);
    }
}

