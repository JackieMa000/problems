package dsa.lib;

import dsa.lib.arrays.ArrayInt;
import dsa.nodes.BinaryTreeNode;

public class LibFX {
    public static BinaryTreeNode arrayToBinaryTree(int[] ary) {
        return new ArrayInt(ary).toBinaryTree();
    }
}
