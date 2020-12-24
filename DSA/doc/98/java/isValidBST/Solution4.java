package experiment.isValidBST;

import dsa.nodes.BinaryTreeNode;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Solution4 {
    //  iterative inorder traversal using stack.
    public List<Integer> inorderTraversal(BinaryTreeNode root) {
        List<Integer> list = new ArrayList<>();
        if (root == null) return list;

        // Add all the nodes to the stack by inorder traversal
        Stack<BinaryTreeNode> stack = new Stack<>();
//        Produce the stack
        while (root != null || !stack.empty()) {
            // Push root and left subtree to the stack
            while (root != null) {
                stack.push(root);
                root = root.left;
            }

//            consume the stack
            root = stack.pop();
            // Add the root to the list
            list.add(root.val);

            // Add all the right nodes
            root = root.right;
        }

        return list;
    }

    /*
    Now, we can use this structure to find the Kth smallest element in BST.

Question : Kth Smallest Element in a BST
     */
    public int kthSmallest(BinaryTreeNode root, int k) {
        Stack<BinaryTreeNode> stack = new Stack<>();

        while (root != null || !stack.isEmpty()) {

            // Produce on the left side
            // It's the smallest on the top of the stack.
            // The stack is in desc order from bottom to the top
            while (root != null) {
                stack.push(root);
                root = root.left;
            }

            // Consume the stack from the top.
            root = stack.pop();
            if (--k == 0) break;

            // Produce on the right side
            root = root.right;
        }

        return root.val;
    }

    /*
    We can also use this structure to solve BST validation question.

Question : Validate Binary Search Tree
     */

    //Rule: inorder traversal
//    iterative
    //inorder Rule: left(all nodes) < root < right(all nodes), or prev < cur.
    public boolean isValidBST(BinaryTreeNode root) {
        if (root == null) return true;
        Stack<BinaryTreeNode> stack = new Stack<>();
        BinaryTreeNode pre = null;


//        1) cur is root, Put all the left nodes to the stack until the end.
//        2) cur is right child node of the leaf node, do the same process for the cur.
        while (root != null || !stack.isEmpty()) {

            // Produce on the left side
            while (root != null) {
                stack.push(root);
                root = root.left;
            }

            // Consume the stack from the top.
            // It's the smallest on the top of the stack.
            // The stack is in desc order from bottom to the top
            root = stack.pop();
//            Process, Logic
            if (pre != null && root.val <= pre.val) return false;

            // Produce on the right side
            // go to the right side
            pre = root;
            root = root.right;
        }

        return true;
    }
}
