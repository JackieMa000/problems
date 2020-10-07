package dsa.nodes;

public class BinaryTreeNode extends TreeNode {
    public BinaryTreeNode left, right;

    public BinaryTreeNode() {
        super();
    }

    public BinaryTreeNode(int val) {
        super(val);
    }

    public BinaryTreeNode(int val, BinaryTreeNode left, BinaryTreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
