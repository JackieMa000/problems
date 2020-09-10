package lib.trees;

import lib.lists.arrays.Array;
import nodes.BinaryTreeNode;
import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;

import static org.junit.Assert.*;

public class BinarySearchTreeTest extends BinarySearchTreeTestFX {

    public static class IsValidTest {

        @Test
        public void case1() {
            assertFalse(new BinarySearchTree(new Array(new int[]{1, 1}).toBinaryTree()).isValid());
            assertFalse(new BinarySearchTree(new Array(new int[]{2, 4, 5}).toBinaryTree()).isValid());
        }

        @Test
        public void case2() {
            assertTrue(new BinarySearchTree(new Array(new int[]{5, 1, 8, 0, 2, 6, 9}).toBinaryTree()).isValid());
        }

        @Test
        public void case3() {
            assertTrue(new BinarySearchTree(new Array(new int[]{5, 1, 6, -3, 2, 0, 7}).toBinaryTree()).isValid());
        }

        @Test
        public void case4() {
            assertFalse(new BinarySearchTree(new Array(new int[]{5, 1, 4, 0, 6, 3, 6}).toBinaryTree()).isValid());
        }

        @Test
        public void case5() {
            assertTrue(new BinarySearchTree(new Array(new int[]{3, 1, 5, 0, 2}).toBinaryTree()).isValid());
        }
    }

    public static class PreOrderTest {

        @Test
        public void case1() {
            BinaryTreeNode root = new Array(new int[]{2, 1}).toBinaryTree();
            assertEquals(new ArrayList<>(Arrays.asList(2, 1)), new BinarySearchTree(root).preorder());
        }

        @Test
        public void case2() {
            BinaryTreeNode root = new Array(new int[]{2, 1, 3}).toBinaryTree();
            assertEquals(new ArrayList<>(Arrays.asList(2, 1, 3)), new BinarySearchTree(root).preorder());
        }

        @Test
        public void case3() {
            BinaryTreeNode root = new Array(new int[]{3, 1, 5, 0, 2}).toBinaryTree();
            assertEquals(new ArrayList<>(Arrays.asList(3, 1, 2, 5)), new BinarySearchTree(root).preorder());
        }
    }

    public static class InOrderTest {

        @Test
        public void case1() {
            BinaryTreeNode root = new Array(new int[]{2, 1}).toBinaryTree();
            assertEquals(new ArrayList<>(Arrays.asList(1, 2)), new BinarySearchTree(root).inorder());
        }

        @Test
        public void case2() {
            BinaryTreeNode root = new Array(new int[]{2, 1, 3}).toBinaryTree();
            assertEquals(new ArrayList<>(Arrays.asList(1, 2, 3)), new BinarySearchTree(root).inorder());
        }

        @Test
        public void case3() {
            BinaryTreeNode root = new Array(new int[]{3, 1, 5, 0, 2}).toBinaryTree();
            assertEquals(new ArrayList<>(Arrays.asList(1, 2, 3, 5)), new BinarySearchTree(root).inorder());
        }
    }

    public static class PostOrderTest {

        @Test
        public void case1() {
            BinaryTreeNode root = new Array(new int[]{2, 1}).toBinaryTree();
            assertEquals(new ArrayList<>(Arrays.asList(1, 2)), new BinarySearchTree(root).postorder());
        }

        @Test
        public void case2() {
            BinaryTreeNode root = new Array(new int[]{2, 1, 3}).toBinaryTree();
            assertEquals(new ArrayList<>(Arrays.asList(1, 3, 2)), new BinarySearchTree(root).postorder());
        }

        @Test
        public void case3() {
            BinaryTreeNode root = new Array(new int[]{3, 1, 5, 0, 2}).toBinaryTree();
            assertEquals(new ArrayList<>(Arrays.asList(2, 1, 5, 3)), new BinarySearchTree(root).postorder());
        }
    }

    public static class LowestCommonAncestorTest {

        private BinaryTreeNode getLowestCommonAncestor(BinaryTreeNode root, BinaryTreeNode p, BinaryTreeNode q) {
            return new BinarySearchTree(root).lowestCommonAncestor(p, q);
        }

        @Test
        public void case1() {
            BinaryTreeNode root = arrayToTree(new int[]{6, 2, 8, 1, 4, 7, 9, 0, 0, 3, 5});
            BinaryTreeNode p = getTreeNodeByValue(root, 2);
            BinaryTreeNode q = getTreeNodeByValue(root, 8);
            assertEquals(6, getLowestCommonAncestor(root, p, q).val);
        }

        @Test
        public void case2() {
            BinaryTreeNode root = arrayToTree(new int[]{6, 2, 8, 1, 4, 7, 9, 0, 0, 3, 5});
            BinaryTreeNode p = getTreeNodeByValue(root, 2);
            BinaryTreeNode q = getTreeNodeByValue(root, 4);
            assertEquals(2, getLowestCommonAncestor(root, p, q).val);
        }
    }
}