package dsa.lib.trees;

import dsa.lib.arrays.ArrayInt;
import dsa.nodes.BinaryTreeNode;
import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;

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

        @Test
        public void case1() {
            BinaryTreeNode root = new ArrayInt(new int[]{2, 1}).toBinaryTree();
            assertEquals(new ArrayList<>(Arrays.asList(2, 1)), new BinarySearchTree(root).preorder());
        }

        @Test
        public void case2() {
            BinaryTreeNode root = new ArrayInt(new int[]{2, 1, 3}).toBinaryTree();
            assertEquals(new ArrayList<>(Arrays.asList(2, 1, 3)), new BinarySearchTree(root).preorder());
        }

        @Test
        public void case3() {
            BinaryTreeNode root = new ArrayInt(new int[]{3, 1, 5, 0, 2}).toBinaryTree();
            assertEquals(new ArrayList<>(Arrays.asList(3, 1, 2, 5)), new BinarySearchTree(root).preorder());
        }
    }

    public static class InOrderTest {

        @Test
        public void case1() {
            BinaryTreeNode root = new ArrayInt(new int[]{2, 1}).toBinaryTree();
            assertEquals(new ArrayList<>(Arrays.asList(1, 2)), new BinarySearchTree(root).inorder());
        }

        @Test
        public void case2() {
            BinaryTreeNode root = new ArrayInt(new int[]{2, 1, 3}).toBinaryTree();
            assertEquals(new ArrayList<>(Arrays.asList(1, 2, 3)), new BinarySearchTree(root).inorder());
        }

        @Test
        public void case3() {
            BinaryTreeNode root = new ArrayInt(new int[]{3, 1, 5, 0, 2}).toBinaryTree();
            assertEquals(new ArrayList<>(Arrays.asList(1, 2, 3, 5)), new BinarySearchTree(root).inorder());
        }
    }

    public static class PostOrderTest {

        @Test
        public void case1() {
            BinaryTreeNode root = new ArrayInt(new int[]{2, 1}).toBinaryTree();
            assertEquals(new ArrayList<>(Arrays.asList(1, 2)), new BinarySearchTree(root).postorder());
        }

        @Test
        public void case2() {
            BinaryTreeNode root = new ArrayInt(new int[]{2, 1, 3}).toBinaryTree();
            assertEquals(new ArrayList<>(Arrays.asList(1, 3, 2)), new BinarySearchTree(root).postorder());
        }

        @Test
        public void case3() {
            BinaryTreeNode root = new ArrayInt(new int[]{3, 1, 5, 0, 2}).toBinaryTree();
            assertEquals(new ArrayList<>(Arrays.asList(2, 1, 5, 3)), new BinarySearchTree(root).postorder());
        }
    }

    public static class LowestCommonAncestorTest {

        private BinaryTreeNode getLowestCommonAncestor(BinaryTreeNode root, BinaryTreeNode p, BinaryTreeNode q) {
            return new BinarySearchTree(root).lowestCommonAncestor(p, q);
        }

        @Test
        public void case1() {
            BinaryTreeNode root = arrayToBinaryTree(new int[]{6, 2, 8, 1, 4, 7, 9, 0, 0, 3, 5});
            BinaryTreeNode p = getTreeNodeByValue(root, 2);
            BinaryTreeNode q = getTreeNodeByValue(root, 8);
            assertEquals(6, getLowestCommonAncestor(root, p, q).val);
        }

        @Test
        public void case2() {
            BinaryTreeNode root = arrayToBinaryTree(new int[]{6, 2, 8, 1, 4, 7, 9, 0, 0, 3, 5});
            BinaryTreeNode p = getTreeNodeByValue(root, 2);
            BinaryTreeNode q = getTreeNodeByValue(root, 4);
            assertEquals(2, getLowestCommonAncestor(root, p, q).val);
        }
    }
}