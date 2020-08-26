package lib.trees;

import nodes.BinaryTreeNode;

import java.util.ArrayList;
import java.util.List;

public class BinarySearchTree extends BinaryTree {
    public BinarySearchTree(BinaryTreeNode root) {
        super(root);
    }

    public List<Integer> preorder() {
        return preorderDfs(this.root, new ArrayList<>());
    }

    private static List<Integer> preorderDfs(BinaryTreeNode root, List<Integer> lst) {
        if (root != null) {
            lst.add(root.val);
            preorderDfs(root.left, lst);
            preorderDfs(root.right, lst);
        }
        return lst;
    }

    public List<Integer> inorder() {
        return inorderDfs(this.root, new ArrayList<>());
    }

    private static List<Integer> inorderDfs(BinaryTreeNode root, List<Integer> lst) {
        if (root != null) {
            inorderDfs(root.left, lst);
            lst.add(root.val);
            inorderDfs(root.right, lst);
        }
        return lst;
    }

    public List<Integer> postorder() {
        return postorderDfs(this.root, new ArrayList<>());
    }

    private static List<Integer> postorderDfs(BinaryTreeNode root, List<Integer> lst) {
        if (root != null) {
            postorderDfs(root.left, lst);
            postorderDfs(root.right, lst);
            lst.add(root.val);
        }
        return lst;
    }

    public boolean isValid() {
        return isValidBST(this.root, null, null);
    }
/**
 LowerBound and UpperBound.
BST Rule:
 left(all nodes) < root < right(all nodes)
 Biggest on the left < root < smallest on the right
 */
private static boolean isValidBST(BinaryTreeNode root, BinaryTreeNode minNode, BinaryTreeNode maxNode) {
//        Terminator
    if (root == null) return true;

//        Left Children Tree. upperBound
    if (maxNode != null && root.val >= maxNode.val) return false;

//        Right Children Tree. lowerBound
    if (minNode != null && root.val <= minNode.val) return false;

//        Recursive case
    return isValidBST(root.left, minNode, root) && isValidBST(root.right, root, maxNode);
}

}
