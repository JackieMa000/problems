package dsa.lib.trees;

import dsa.nodes.BinaryTreeNode;

public class BinaryTreeTestFX extends TreeTestFX {

    public static BinaryTreeNode getTreeNodeByValue(BinaryTreeNode root, int v) {
        return new BinaryTree(root).getNodeByValue(v);
    }
}
