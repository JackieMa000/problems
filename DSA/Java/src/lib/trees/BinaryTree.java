package lib.trees;

import lib.Utils;
import nodes.BinaryTreeNode;

import static java.lang.Math.max;
import static java.lang.Math.pow;

public class BinaryTree implements Tree {

    protected final BinaryTreeNode root;

    public BinaryTree(BinaryTreeNode root) {
        this.root = root;
    }

    @Override
    public int[] toArray() {
        int arraySize = getArraySizeForBinaryTree(this.root);
        int[] array = new int[arraySize];
        generateArrayFromTree(this.root, 0, array);
        return Utils.arrayStripTrailing(array);
    }

    private static void generateArrayFromTree(BinaryTreeNode root, int i, int[] array) {
        if (root == null || i >= array.length) return;
        array[i] = root.val;
        generateArrayFromTree(root.left, 2 * i + 1, array);
        generateArrayFromTree(root.right, 2 * i + 2, array);
    }

    protected static int getArraySizeForBinaryTree(BinaryTreeNode root) {
        // Todo: Could use my own pow algorithm.
        return (int) (pow(2, new BinaryTree(root).depth()) - 1);
    }

    @Override
    public int depth() {
        return (this.root == null) ? 0 : 1 + max(new BinaryTree(this.root.left).depth(),
                new BinaryTree(this.root.right).depth());
    }

    @Override
    public int size() {
        // ToDo
        return 0;
    }
}
