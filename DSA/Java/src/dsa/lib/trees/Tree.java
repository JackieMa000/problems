package dsa.lib.trees;

import dsa.nodes.TreeNode;

public interface Tree {
    int[] toArray();
    int depth();
    int size();
    TreeNode getNodeByIndex(int idx);
    TreeNode getNodeByValue(int val);
}
