package lib.trees;

import lib.lists.arrays.Array;
import nodes.BinaryTreeNode;
import org.junit.Assert;
import org.junit.Test;

import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;

public class BinaryTreeTest {
    public static class DepthTest {
        @Test
        public void case1() {
            BinaryTreeNode root = new Array(new int[]{5, 1, 4, 0, 0, 3, 6}).toBinaryTree();
            assertEquals(3, new BinaryTree(root).depth());
        }
    }

    public static class ToArrayTest {
        @Test
        public void case1() {
            BinaryTreeNode root = new Array(new int[]{3, 1, 5, 0, 2}).toBinaryTree();
            Assert.assertArrayEquals(new int[]{3, 1, 5, 0, 2}, new BinaryTree(root).toArray());
        }

        @Test
        public void case2() {
            BinaryTreeNode root = new Array(new int[]{5, 1, 4, 0, 6, 3, 6}).toBinaryTree();
            assertArrayEquals(new int[]{5, 1, 4, 0, 6, 3, 6}, new BinaryTree(root).toArray());
        }
        @Test
        public void case3() {
            BinaryTreeNode root = new Array(new int[]{5, 1, 4, 0, 0, 3, 6}).toBinaryTree();
            assertArrayEquals(new int[]{5, 1, 4, 0, 0, 3, 6}, new BinaryTree(root).toArray());
        }
    }

    public static class GetArraySizeForBinaryTreeTest {
        @Test
        public void case1() {
            BinaryTreeNode root = new Array(new int[]{3, 1, 5, 0, 2}).toBinaryTree();
            assertEquals(7, BinaryTree.getArraySizeForBinaryTree(root));
        }
    }
}
