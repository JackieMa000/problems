package experiment.isValidBST;

import java.util.Stack;

import dsa.nodes.BinaryTreeNode;

//Rule: inorder traversal
// iterative
//inorder Rule: left(all nodes) < root < right(all nodes), or prev < cur.
//equivalent to self-implemented recursive stack
public class Solution2 {
    public boolean isValidBST(BinaryTreeNode root) {
        Stack<BinaryTreeNode> stack = new Stack<>();
        BinaryTreeNode pre = null;

//        1) Put all the left nodes to the stack until reaching to the leaf.
//      recursion equivalent: Terminator

        while (root != null || !stack.isEmpty()) {
//      recursion equivalent: Go
//            push to the stack
            // Produce on the left subTree
            while (root != null) {
                stack.push(root);
                root = root.left;
            }

//            pop the stack
            // Consume the stack from the top.
            // It's the smallest on the top of the stack.
            // The stack is in desc order from bottom to the top

//      recursion equivalent: Back
//      Process or Condition
            root = stack.pop();
            if (pre != null && pre.val >= root.val) return false;

//      recursion equivalent: recursive case. drill down
            // Produce on the right side
            // go to the right side
            pre = root;
            root = root.right;
        }

        return true;
    }
}
