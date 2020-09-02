import lib.trees.BinaryTree;
import nodes.BinaryTreeNode;

public class Solution1 {
    public BinaryTreeNode lowestCommonAncestor(BinaryTreeNode root, BinaryTreeNode p, BinaryTreeNode q) {
        return new BinaryTree(root).lowestCommonAncestor(p, q);
    }
}
