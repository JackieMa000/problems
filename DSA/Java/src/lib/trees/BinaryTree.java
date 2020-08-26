package lib.trees;

import lib.Utils;
import nodes.BinaryTreeNode;

import java.util.LinkedList;
import java.util.Queue;

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
        return depthDfs(this.root);
    }

    private static int depthDfs(BinaryTreeNode root) {
        return (root == null) ? 0 : 1 + max(depthDfs(root.left), depthDfs(root.right));
    }

    @Override
    public int size() {
        return sizeDfs(this.root);
    }

    private static int sizeDfs(BinaryTreeNode root) {
        int count = 0;
        if (root != null) {
            count += 1;
            count += sizeDfs(root.left);
            count += sizeDfs(root.right);
        }
        return count;
    }

    @Override
    public BinaryTreeNode getNodeByIndex(int idx) {
        return getNodeByIdxBfs(this.root, idx);
    }

    private static BinaryTreeNode getNodeByIdxBfs(BinaryTreeNode root, int idx) {
        Queue<BinaryTreeNode> queue = new LinkedList<>();

        queue.add(root);
        int count = 0;
        while (!queue.isEmpty()) {
            BinaryTreeNode node = queue.poll();
            count++;
            if ((count - 1) == idx) return node;

            if (node == null) continue;
            queue.add(node.left);
            queue.add(node.right);
        }

        return null;
    }

    @Override
    public BinaryTreeNode getNodeByValue(int val) {
        return getNodeByValBfs(this.root, val);
    }

    private static BinaryTreeNode getNodeByValBfs(BinaryTreeNode root, int val) {
        Queue<BinaryTreeNode> queue = new LinkedList<>();

        queue.add(root);
        while (!queue.isEmpty()) {
            BinaryTreeNode node = queue.poll();
            if (node == null) continue;
            if (node.val == val) return node;

            queue.add(node.left);
            queue.add(node.right);
        }

        return null;
    }
}
