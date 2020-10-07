package dsa.lib.trees;

import dsa.lib.arrays.Array;
import dsa.nodes.BinaryTreeNode;

public class BinaryTreeTestFX {

    public static BinaryTreeNode arrayToTree(int[] ary) {
        return new Array(ary).toBinaryTree();
    }

    public static BinaryTreeNode getTreeNodeByValue(BinaryTreeNode root, int v) {
        return new BinaryTree(root).getNodeByValue(v);
    }
}
