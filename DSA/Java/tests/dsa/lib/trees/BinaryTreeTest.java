package dsa.lib.trees;

import dsa.lib.arrays.Array;
import dsa.nodes.BinaryTreeNode;
import org.junit.Assert;
import org.junit.Test;

import static org.junit.Assert.*;

public class BinaryTreeTest extends BinaryTreeTestFX {

    public static class GetNodeByIndexTest {
        @Test
        public void case1() {
            assertNull(getTreeNodeByIdx(null, 1));
            assertNull(getTreeNodeByIdx(arrayToBinaryTree(new int[]{1}), 1));
            assertNull(getTreeNodeByIdx(arrayToBinaryTree(new int[]{1, 0, 3}), 1));
        }

        @Test
        public void case2() {
            assertEquals(1, getTreeNodeByIdx(arrayToBinaryTree(new int[]{1}), 0).val);
            assertEquals(3, getTreeNodeByIdx(arrayToBinaryTree(new int[]{1, 2, 3}), 2).val);
        }

        @Test
        public void case3() {
            assertEquals(2, getTreeNodeByIdx(arrayToBinaryTree(new int[]{3, 1, 5, 0, 2}), 4).val);
        }

        private BinaryTreeNode getTreeNodeByIdx(BinaryTreeNode root, int i) {
            return new BinaryTree(root).getNodeByIndex(i);
        }
    }

    public static class GetNodeByValueTest {

        @Test
        public void case1() {
            assertNull(getTreeNodeByVal(null, 1));
            assertNull(getTreeNodeByVal(arrayToBinaryTree(new int[]{1}), 2));
        }

        @Test
        public void case2() {
            assertEquals(1, getTreeNodeByVal(arrayToBinaryTree(new int[]{1}), 1).val);
            assertEquals(3, getTreeNodeByVal(arrayToBinaryTree(new int[]{1, 2, 3}), 3).val);
        }

        @Test
        public void case3() {
            assertEquals(2, getTreeNodeByVal(arrayToBinaryTree(new int[]{1, 2, 3}), 2).val);
            assertEquals(2, getTreeNodeByVal(arrayToBinaryTree(new int[]{3, 1, 5, 0, 2}), 2).val);
        }

        private BinaryTreeNode getTreeNodeByVal(BinaryTreeNode root, int v) {
            return new BinaryTree(root).getNodeByValue(v);
        }
    }

    public static class DepthTest {
        @Test
        public void case1() {
            BinaryTreeNode root = new Array(new int[]{5, 1, 4, 0, 0, 3, 6}).toBinaryTree();
            assertEquals(3, new BinaryTree(root).depth());
        }
    }

    public static class ToArrayTest {
        @Test
        public void nullTree() {
            assertNull(toArray(null));
        }

        @Test
        public void case1() {
            int[] ary = {3, 1, 5, 0, 2};
            assertArrayEquals(ary, toArray(arrayToBinaryTree(ary)));
        }

        @Test
        public void case2() {
            int[] ary = {5, 1, 4, 0, 6, 3, 6};
            assertArrayEquals(ary, toArray(arrayToBinaryTree(ary)));
        }

        @Test
        public void case3() {
            int[] ary = {5, 1, 4, 0, 0, 3, 6};
            assertArrayEquals(ary, toArray(arrayToBinaryTree(ary)));
        }

        private int[] toArray(BinaryTreeNode root) {
            return new BinaryTree(root).toArray();
        }
    }

    public static class GetArraySizeForBinaryTreeTest {
        @Test
        public void case1() {
            BinaryTreeNode root = new Array(new int[]{3, 1, 5, 0, 2}).toBinaryTree();
            assertEquals(7, BinaryTree.getArraySizeForBinaryTree(root));
        }
    }

    public static class SizeTest {

        @Test
        public void case1() {
            assertEquals(0, getTreeSize(null));
        }

        @Test
        public void case2() {
            assertEquals(1, getTreeSize(arrayToBinaryTree(new int[]{1})));
            assertEquals(3, getTreeSize(arrayToBinaryTree(new int[]{1, 2, 3})));
        }

        @Test
        public void case3() {
            assertEquals(4, getTreeSize(arrayToBinaryTree(new int[]{3, 1, 5, 0, 2})));
        }

        private int getTreeSize(BinaryTreeNode root) {
            return new BinaryTree(root).size();
        }

    }

    public static class LowestCommonAncestorTest {

        private BinaryTreeNode getLowestCommonAncestor(BinaryTreeNode root, BinaryTreeNode p, BinaryTreeNode q) {
            return new BinaryTree(root).lowestCommonAncestor(p, q);
        }

        @Test
        public void case1() {
            BinaryTreeNode root = arrayToBinaryTree(new int[]{3, 5, 1, 6, 2, 0, 8, 0, 0, 7, 4});
            BinaryTreeNode p = getTreeNodeByValue(root, 5);
            BinaryTreeNode q = getTreeNodeByValue(root, 1);
            assertEquals(3, getLowestCommonAncestor(root, p, q).val);
        }

        @Test
        public void case2() {
            BinaryTreeNode root = arrayToBinaryTree(new int[]{3, 5, 1, 6, 2, 0, 8, 0, 0, 7, 4});
            BinaryTreeNode p = getTreeNodeByValue(root, 5);
            BinaryTreeNode q = getTreeNodeByValue(root, 4);
            assertEquals(5, getLowestCommonAncestor(root, p, q).val);
        }
    }
}
