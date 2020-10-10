package dsa.lib.trees;

import dsa.lib.FX;
import dsa.nodes.BinaryTreeNode;

public class BinaryTreeTestFX extends FX {

    public static BinaryTreeNode getTreeNodeByValue(BinaryTreeNode root, int v) {
        return new BinaryTree(root).getNodeByValue(v);
    }
}
