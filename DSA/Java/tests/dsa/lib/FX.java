package dsa.lib;

import dsa.lib.arrays.Array;
import dsa.nodes.BinaryTreeNode;

public class FX {
    public static BinaryTreeNode arrayToBinaryTree(int[] ary) {
        return new Array(ary).toBinaryTree();
    }
}
