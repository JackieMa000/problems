package dsa.lib.trees;

import dsa.nodes.BinaryTreeNode;

public class BinarySearchTree extends BinaryTree {
    public BinarySearchTree(BinaryTreeNode root) {
        super(root);
    }

    //    LeetCode98
    public boolean isValid() {
        return isValidBST(this.root, null, null);
    }

    /**
     * Rule: LowerBound, UpperBound.
     * BST Rule:
     * left(all nodes) < root < right(all nodes)
     * Biggest on the left < root < smallest on the right -> Left SubTree UpperBound = root, Right subTree LowerBound = root.
     */
    private static boolean isValidBST(BinaryTreeNode root, BinaryTreeNode minNode, BinaryTreeNode maxNode) {
//        Terminator
        if (root == null) return true;

//        Left SubTree. upperBound
        if (maxNode != null && root.val >= maxNode.val) return false;

//        Right SubTree. lowerBound
        if (minNode != null && root.val <= minNode.val) return false;

//        Left SubTree UpperBound = root, Right subTree LowerBound = root.
        return isValidBST(root.left, minNode, root) && isValidBST(root.right, root, maxNode);
    }

    /**
     * BST LCA Rule:
     * 1. if p < root < q or q < root < p -> root
     * 2. if p < root and q < root -> lca is on the left
     * 3. if root < p and root < q -> lca is on the right
     */
//    LeetCode235
    @Override
    public BinaryTreeNode lowestCommonAncestor(BinaryTreeNode p, BinaryTreeNode q) {
        return lowestCommonAncestorBfs(this.root, p, q);
    }

    private static BinaryTreeNode lowestCommonAncestorDfs(BinaryTreeNode root, BinaryTreeNode p, BinaryTreeNode q) {
        return (p.val < root.val && q.val < root.val) ? lowestCommonAncestorDfs(root.left, p, q) :
                (root.val < p.val && root.val < q.val) ? lowestCommonAncestorDfs(root.right, p, q) : root;
    }

    private static BinaryTreeNode lowestCommonAncestorBfs(BinaryTreeNode root, BinaryTreeNode p, BinaryTreeNode q) {
        while (root != null) {
            if (root.val > p.val && root.val > q.val) {
                root = root.left;
            } else if (root.val < p.val && root.val < q.val) {
                root = root.right;
            } else {
                break;
            }
        }
        return root;
    }
}
