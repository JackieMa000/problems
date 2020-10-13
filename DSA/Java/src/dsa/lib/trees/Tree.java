package dsa.lib.trees;

import dsa.nodes.TreeNode;

public interface Tree {
    int[] toArrayInt();
    int depth();
    int size();
    TreeNode getNodeByIndex(int idx);
    TreeNode getNodeByValue(int val);
}
