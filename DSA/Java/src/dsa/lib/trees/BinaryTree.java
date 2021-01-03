package dsa.lib.trees;

import dsa.lib.Utils;
import dsa.nodes.BinaryTreeNode;

import java.util.*;

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

    //    LeetCode144
    public List<Integer> preorderTraversal() {
        List<Integer> lst = new LinkedList<>();
        BinaryTree.preorderDfs(this.root, lst);
        return lst;
    }

    //    parameter root will be a copy object, lst will be a lvalue, reference, shared object(declared in preorder
//    stack frame) for all recursive call stack.
//    Java decides the parameter object would be a copy or a reference
    private static void preorderDfs(BinaryTreeNode root, List<Integer> lst) {
        if (root != null) {
            lst.add(root.val);
            BinaryTree.preorderDfs(root.left, lst);
            BinaryTree.preorderDfs(root.right, lst);
        }
    }

    //    LeetCode94
    public List<Integer> inorderTraversal() {
        List<Integer> lst = new LinkedList<>();
        BinaryTree.inorderDfs(this.root, lst);
        return lst;
    }

    private static void inorderDfs(BinaryTreeNode root, List<Integer> lst) {
        if (root != null) {
            BinaryTree.inorderDfs(root.left, lst);
            lst.add(root.val);
            BinaryTree.inorderDfs(root.right, lst);
        }
    }

    //    LeetCode145
    public List<Integer> postorderTraversal() {
        List<Integer> lst = new LinkedList<>();
        BinaryTree.postorderDfs(this.root, lst);
        return lst;
    }

    private static void postorderDfs(BinaryTreeNode root, List<Integer> lst) {
        if (root != null) {
            BinaryTree.postorderDfs(root.left, lst);
            BinaryTree.postorderDfs(root.right, lst);
            lst.add(root.val);
        }
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


    //    LeetCode102
    public List<List<Integer>> levelOrder() {
//        return levelOrderBfs(this.root);
        List<List<Integer>> result = new LinkedList<>();
        levelOrderDfs(root, 0, result);
        return result;
    }

    /*
     * Rule: BFS
     * queue -> currentLevelResult -> Result
     * currentLevelResult: saving the node values for the current level, 1D-array
     * Result: saving the final result for all the levels, 2D-array
     * queue: for BFS traversing the tree by level,
     *  consuming the nodes for the current level, producing the children nodes for next level
     *  Loop for the current level, do the logic(saving the node values to the currentLevelResult), produce for the next level
     * Loop on the whole tree:
     *  Loop on the level:
     *      ....
     *
     */
    private static List<List<Integer>> levelOrderBfs(BinaryTreeNode root) {
        List<List<Integer>> result = new LinkedList<>();

        if (root != null) {
            Queue<BinaryTreeNode> queue = new LinkedList<>();
            queue.add(root);
            while (!queue.isEmpty()) {
                int levelSize = queue.size();
                List<Integer> levelResult = new LinkedList<>();

                for (int i = 0; i < levelSize; i++) {
                    root = queue.poll();
                    levelResult.add(root.val);

                    if (root.left != null) queue.add(root.left);
                    if (root.right != null) queue.add(root.right);
                }

                result.add(levelResult);
            }
        }

        return result;
    }

    /**
     * Rule: DFS
     * currentLevelResult -> Result
     * saving the current level node values to the currentLevelResult.
     * get the currentLevelResult by the level number parameter from Result
     * generate the currentLevelResult when it does not exist in the result.
     */
    private static void levelOrderDfs(BinaryTreeNode root, int level, List<List<Integer>> result) {
        if (root == null) return;

        if (result.size() < level + 1) result.add(new LinkedList<>());
        result.get(level).add(root.val);

        levelOrderDfs(root.left, level + 1, result);
        levelOrderDfs(root.right, level + 1, result);
    }
}
