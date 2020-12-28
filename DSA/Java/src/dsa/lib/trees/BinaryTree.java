package dsa.lib.trees;

import dsa.lib.Utils;
import dsa.nodes.BinaryTreeNode;

import java.util.LinkedList;
import java.util.Queue;

import static java.lang.Math.max;
import static java.lang.Math.pow;

public class BinaryTree implements Tree {

    protected final BinaryTreeNode root;

    public BinaryTree(BinaryTreeNode root) {
        this.root = root;
    }

    public int[] toArrayInt() {
        if (this.root == null) return null;
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
        return getTreeNodeByIdxBfs(this.root, idx);
    }

    private static BinaryTreeNode getTreeNodeByIdxBfs(BinaryTreeNode root, int idx) {
        Queue<BinaryTreeNode> queue = new LinkedList<>();
        if (root != null) queue.add(root);

        int count = 0;
        while (!queue.isEmpty()) {
            root = queue.poll();
            if ((++count - 1) == idx) return root;

            if (root == null) continue;
            queue.add(root.left);
            queue.add(root.right);
        }

        return null;
    }

    @Override
    public BinaryTreeNode getNodeByValue(int val) {
        return getNodeByValDfs(this.root, val);
    }

    private static BinaryTreeNode getNodeByValDfs(BinaryTreeNode root, int val) {
        if (root == null) return null;
        if (root.val == val) return root;

        BinaryTreeNode left = getNodeByValDfs(root.left, val);
        BinaryTreeNode right = getNodeByValDfs(root.right, val);
        return left != null ? left : right;
    }

    private static BinaryTreeNode getNodeByValBfs(BinaryTreeNode root, int val) {
        Queue<BinaryTreeNode> queue = new LinkedList<>();
        if (root != null) queue.add(root);
        while (!queue.isEmpty()) {
            root = queue.poll();
            if (root.val == val) return root;

            if (root.left != null) queue.add(root.left);
            if (root.right != null) queue.add(root.right);
        }

        return null;
    }

    private static BinaryTreeNode getNodeByValBfs1(BinaryTreeNode root, int val) {
        Queue<BinaryTreeNode> queue = new LinkedList<>();
        if (root != null) queue.add(root);
        while (!queue.isEmpty()) {
            root = queue.poll();
            if (root == null) continue;
            if (root.val == val) return root;

            queue.add(root.left);
            queue.add(root.right);
        }

        return null;
    }

    //    LeetCode236
    public BinaryTreeNode lowestCommonAncestor(BinaryTreeNode p, BinaryTreeNode q) {
        return lowestCommonAncestorDfs(this.root, p, q);
    }

    /**
     * Binary Tree LCA Rule:
     * find(root, p, q): find p or q in the tree.
     * lca(root, p, q): find the lca in the tree.
     * 1. root is null -> null
     * 2. p or q is root -> lca is root
     * 3. p is on the left/right subtree, and q is on the right/left subtree, respectively -> lca is root
     * 4. p and q both are on the left/right subtree, means lca is on the left/right, return left/right respectively.
     */
    private static BinaryTreeNode lowestCommonAncestorDfs(BinaryTreeNode root, BinaryTreeNode p, BinaryTreeNode q) {
        if (root == null || root == p || root == q) return root;

//        saving the lca on variable left, right
        BinaryTreeNode left = lowestCommonAncestorDfs(root.left, p, q);
        BinaryTreeNode right = lowestCommonAncestorDfs(root.right, p, q);
        return (left != null && right != null) ? root : left == null ? right : left;
//        return left == null ? right : right == null ? left : root;
    }
}
