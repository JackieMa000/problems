package isValidBST;

import lib.trees.BinarySearchTree;
import nodes.BinaryTreeNode;

// BST Rule:
// left(all nodes) < root < right(all nodes)
// Biggest on the left < root < smallest on the right
// LowerBound and UpperBound.
class Solution1 {
    public boolean isValid(BinaryTreeNode root) {
        return new BinarySearchTree(root).isValid();
    }
}
