package dsa.nodes.generics;

public class BinaryTreeNode<T> extends TreeNode<T> {
    public BinaryTreeNode<T> left, right;

    public BinaryTreeNode() {
        super();
        left = null;
        right = null;
    }

    public BinaryTreeNode(T val) {
        super(val);
        left = null;
        right = null;
    }

    public BinaryTreeNode(T val, BinaryTreeNode<T> left, BinaryTreeNode<T> right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
