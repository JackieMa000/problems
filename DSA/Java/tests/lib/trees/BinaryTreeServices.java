package lib.trees;

import lib.lists.arrays.Array;
import nodes.BinaryTreeNode;

public class BinaryTreeServices {

    public static BinaryTreeNode arrayToTree(int[] ary) {
        return new Array(ary).toBinaryTree();
    }

    public static BinaryTreeNode getTreeNodeByValue(BinaryTreeNode root, int v) {
        return new BinaryTree(root).getNodeByValue(v);
    }
}
