package dsa.lib.trees;

import dsa.nodes.BinaryTreeNode;
import org.junit.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.Assert.*;

public class BinarySearchTreeTest extends BinarySearchTreeTestFX {
    public static class IsValidTest {
        @Test
        public void emptyTree() {
            assertTrue(isValid(new int[]{}));
        }

        @Test
        public void oneNode() {
            assertTrue(isValid(new int[]{1}));
        }

        @Test
        public void notBST() {
            assertFalse(isValid(new int[]{1, 1}));
            assertFalse(isValid(new int[]{2, 4, 5}));
            assertFalse(isValid(new int[]{5, 1, 4, 0, 6, 3, 6}));
        }

        @Test
        public void isBST() {
            assertTrue(isValid(new int[]{3, 1, 5, 0, 2}));
            assertTrue(isValid(new int[]{5, 1, 8, 0, 2, 6, 9}));
            assertTrue(isValid(new int[]{5, 1, 6, -3, 2, 0, 7}));
        }

        private boolean isValid(int[] ary) {
            return new BinarySearchTree(arrayToBinaryTree(ary)).isValid();
        }
    }

    public static class PreOrderTest {

        private List<Integer> preorder(BinaryTreeNode root) {
            return new BinarySearchTree(root).preorderTraversal();
        }

        @Test
        public void case1() {
            assertEquals(Arrays.asList(2, 1), preorder(arrayToBinaryTree(2, 1)));
        }

        @Test
        public void case2() {
            assertEquals(Arrays.asList(2, 1, 3), preorder(arrayToBinaryTree(2, 1, 3)));
        }

        @Test
        public void case3() {
            assertEquals(Arrays.asList(3, 1, 2, 5), preorder(arrayToBinaryTree(3, 1, 5, 0, 2)));
        }
    }

    public static class InOrderTest {

        private List<Integer> inorder(BinaryTreeNode root) {
            return new BinarySearchTree(root).inorderTraversal();
        }

        @Test
        public void case1() {
            assertEquals(Arrays.asList(1, 2), inorder(arrayToBinaryTree(2, 1)));
        }

        @Test
        public void case2() {
            assertEquals(Arrays.asList(1, 2, 3), inorder(arrayToBinaryTree(2, 1, 3)));
        }

        @Test
        public void case3() {
            assertEquals(Arrays.asList(1, 2, 3, 5), inorder(arrayToBinaryTree(3, 1, 5, 0, 2)));
        }
    }

    public static class PostOrderTest {

        @Test
        public void case1() {
            assertEquals(Arrays.asList(1, 2), postorder(arrayToBinaryTree(2, 1)));
        }

        @Test
        public void case2() {
            assertEquals(Arrays.asList(1, 3, 2), postorder(arrayToBinaryTree(2, 1, 3)));
        }

        @Test
        public void case3() {
            assertEquals(Arrays.asList(2, 1, 5, 3), postorder(arrayToBinaryTree(3, 1, 5, 0, 2)));
        }

        private List<Integer> postorder(BinaryTreeNode root) {
            return new BinarySearchTree(root).postorderTraversal();
        }
    }

    public static class LowestCommonAncestorTest {

        private BinaryTreeNode lca(BinaryTreeNode root, BinaryTreeNode p, BinaryTreeNode q) {
            return new BinarySearchTree(root).lowestCommonAncestor(p, q);
        }

        @Test
        public void case1() {
            BinaryTreeNode root = arrayToBinaryTree(new int[]{6, 2, 8, 1, 4, 7, 9, 0, 0, 3, 5});
            BinaryTreeNode p = getTreeNodeByValue(root, 2);
            BinaryTreeNode q = getTreeNodeByValue(root, 8);
            assertEquals(6, lca(root, p, q).val);
        }

        @Test
        public void case2() {
            BinaryTreeNode root = arrayToBinaryTree(new int[]{6, 2, 8, 1, 4, 7, 9, 0, 0, 3, 5});
            BinaryTreeNode p = getTreeNodeByValue(root, 2);
            BinaryTreeNode q = getTreeNodeByValue(root, 4);
            assertEquals(2, lca(root, p, q).val);
        }

        @Test
        public void case3() {
            BinaryTreeNode root = arrayToBinaryTree(new int[]{1, 2});
            BinaryTreeNode p = getTreeNodeByValue(root, 1);
            BinaryTreeNode q = getTreeNodeByValue(root, 2);
            assertEquals(1, lca(root, p, q).val);
        }
    }
}