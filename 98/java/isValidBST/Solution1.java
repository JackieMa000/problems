package isValidBST;

import nodes.BinaryTreeNode;

// BST Rule:
// left(all nodes) < root < right(all nodes)
// Biggest on the left < root < smallest on the right
// LowerBound and UpperBound.
class Solution1 {
    public boolean isValidBST(BinaryTreeNode root) {
        return isValid(root, null, null);
    }

    private boolean isValid(BinaryTreeNode root, BinaryTreeNode minNode, BinaryTreeNode maxNode) {
//        Terminator
        if (root == null) return true;

//        lowerBound
        if (minNode != null && root.val <= minNode.val) return false;

//        upperBound
        if (maxNode != null && root.val >= maxNode.val) return false;

//        Recursive case
        return isValid(root.left, minNode, root) && isValid(root.right, root, maxNode);
    }
}
