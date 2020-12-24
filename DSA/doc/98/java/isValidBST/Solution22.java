package experiment.isValidBST;

import dsa.nodes.BinaryTreeNode;

import java.util.Stack;

public class Solution22 {
    public boolean isValidBST(BinaryTreeNode root) {
        Stack<BinaryTreeNode> stack = new Stack<>();
        BinaryTreeNode pre = null;

        while (root != null || !stack.isEmpty()) {
            while (root != null) {
                stack.push(root);
                root = root.left;
            }

            root = stack.pop();
            if (pre != null && pre.val >= root.val) return false;

            pre = root;
            root = root.right;
        }

        return true;
    }
}
