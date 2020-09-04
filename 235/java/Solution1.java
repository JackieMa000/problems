import lib.trees.BinarySearchTree;
import nodes.BinaryTreeNode;

public class Solution1 {
    public BinaryTreeNode lowestCommonAncestor(BinaryTreeNode root, BinaryTreeNode p, BinaryTreeNode q) {
        return new BinarySearchTree(root).lowestCommonAncestor(p, q);
    }
}
