package dsa.lib.trees;

import dsa.lib.arrays.ArrayInt;
import dsa.nodes.BinaryTreeNode;
import org.junit.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.Assert.*;

public class BinaryTreeTest extends BinaryTreeTestFX {

    public static class GetNodeByIndexTest {
        @Test
        public void case1() {
            assertNull(getTreeNodeByIndex(null, 0));
            assertNull(getTreeNodeByIndex(null, 1));
            assertNull(getTreeNodeByIndex(arrayToBinaryTree(1), 1));
            assertNull(getTreeNodeByIndex(arrayToBinaryTree(1, 0, 3), 1));
        }

        @Test
        public void case2() {
            assertEquals(1, getTreeNodeByIndex(arrayToBinaryTree(1), 0).val);
            assertEquals(3, getTreeNodeByIndex(arrayToBinaryTree(1, 2, 3), 2).val);
        }

        @Test
        public void case3() {
            assertEquals(2, getTreeNodeByIndex(arrayToBinaryTree(3, 1, 5, 0, 2), 4).val);
        }
    }

    public static class GetNodeByValueTest {

        @Test
        public void case1() {
            assertNull(getTreeNodeByValue(null, 1));
            assertNull(getTreeNodeByValue(arrayToBinaryTree(1), 2));
        }

        @Test
        public void case2() {
            assertEquals(1, getTreeNodeByValue(arrayToBinaryTree(1), 1).val);
            assertEquals(3, getTreeNodeByValue(arrayToBinaryTree(1, 2, 3), 3).val);
        }

        @Test
        public void case3() {
            assertEquals(2, getTreeNodeByValue(arrayToBinaryTree(1, 2, 3), 2).val);
            assertEquals(2, getTreeNodeByValue(arrayToBinaryTree(3, 1, 5, 0, 2), 2).val);
        }
    }

    public static class DepthTest {
        @Test
        public void case1() {
            BinaryTreeNode root = new ArrayInt(new int[]{5, 1, 4, 0, 0, 3, 6}).toBinaryTree();
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
            return new BinaryTree(root).toArrayInt();
        }
    }

    public static class GetArraySizeForBinaryTreeTest {
        @Test
        public void case1() {
            BinaryTreeNode root = new ArrayInt(new int[]{3, 1, 5, 0, 2}).toBinaryTree();
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
            assertEquals(1, getTreeSize(arrayToBinaryTree(1)));
            assertEquals(3, getTreeSize(arrayToBinaryTree(1, 2, 3)));
        }

        @Test
        public void case3() {
            assertEquals(4, getTreeSize(arrayToBinaryTree(3, 1, 5, 0, 2)));
        }

        private int getTreeSize(BinaryTreeNode root) {
            return new BinaryTree(root).size();
        }

    }

    public static class LowestCommonAncestorTest {

        private BinaryTreeNode lca(BinaryTreeNode root, BinaryTreeNode p, BinaryTreeNode q) {
            return new BinaryTree(root).lowestCommonAncestor(p, q);
        }

        @Test
        public void case1() {
            BinaryTreeNode root = arrayToBinaryTree(3, 5, 1, 6, 2, 0, 8, 0, 0, 7, 4);
            BinaryTreeNode p = getTreeNodeByValue(root, 5);
            BinaryTreeNode q = getTreeNodeByValue(root, 1);
            assertEquals(3, lca(root, p, q).val);
        }

        @Test
        public void case2() {
            BinaryTreeNode root = arrayToBinaryTree(3, 5, 1, 6, 2, 0, 8, 0, 0, 7, 4);
            BinaryTreeNode p = getTreeNodeByValue(root, 5);
            BinaryTreeNode q = getTreeNodeByValue(root, 4);
            assertEquals(5, lca(root, p, q).val);
        }

        @Test
        public void case3() {
            BinaryTreeNode root = arrayToBinaryTree(1, 2);
            BinaryTreeNode p = getTreeNodeByValue(root, 1);
            BinaryTreeNode q = getTreeNodeByValue(root, 2);
            assertEquals(1, lca(root, p, q).val);
        }
    }

    public static class PreOrderTest {
        private List<Integer> preorder(BinaryTreeNode root) {
            return new BinaryTree(root).preorderTraversal();
        }

        @Test
        public void emptyTree() {
            assertEquals(Collections.<Integer>emptyList(), preorder(null));
        }

        @Test
        public void oneNodeTree() {
            assertEquals(Collections.singletonList(1), preorder(arrayToBinaryTree(1)));
        }

        @Test
        public void case1() {
            assertEquals(Arrays.asList(1, 2), preorder(arrayToBinaryTree(1, 0, 2)));
        }

        @Test
        public void case2() {
            assertEquals(Arrays.asList(1, 2), preorder(arrayToBinaryTree(1, 2)));
        }

        @Test
        public void case3() {
            assertEquals(Arrays.asList(1, 2, 3), preorder(arrayToBinaryTree(1, 0, 2, 0, 0, 3)));
        }
    }

    public static class InOrderTest {
        private List<Integer> inorder(BinaryTreeNode root) {
            return new BinaryTree(root).inorderTraversal();
        }

        @Test
        public void emptyTree() {
            assertEquals(Collections.<Integer>emptyList(), inorder(null));
        }

        @Test
        public void oneNodeTree() {
            assertEquals(Collections.singletonList(1), inorder(arrayToBinaryTree(1)));
        }

        @Test
        public void case1() {
            assertEquals(Arrays.asList(1, 2), inorder(arrayToBinaryTree(1, 0, 2)));
        }

        @Test
        public void case2() {
            assertEquals(Arrays.asList(2, 1), inorder(arrayToBinaryTree(1, 2)));
        }

        @Test
        public void case3() {
            assertEquals(Arrays.asList(1, 3, 2), inorder(arrayToBinaryTree(1, 0, 2, 0, 0, 3)));
        }
    }

    public static class PostOrderTest {
        private List<Integer> postorder(BinaryTreeNode root) {
            return new BinaryTree(root).postorderTraversal();
        }

        @Test
        public void emptyTree() {
            assertEquals(Collections.<Integer>emptyList(), postorder(null));
        }

        @Test
        public void oneNodeTree() {
            assertEquals(Collections.singletonList(1), postorder(arrayToBinaryTree(1)));
        }

        @Test
        public void case1() {
            assertEquals(Arrays.asList(2, 1), postorder(arrayToBinaryTree(1, 0, 2)));
        }

        @Test
        public void case2() {
            assertEquals(Arrays.asList(2, 1), postorder(arrayToBinaryTree(1, 2)));
        }

        @Test
        public void case3() {
            assertEquals(Arrays.asList(3, 2, 1), postorder(arrayToBinaryTree(1, 0, 2, 0, 0, 3)));
        }
    }

    public static class LevelOrderTest {

        @Test
        public void emptyTree() {
            assertEquals(Collections.emptyList(), levelOrder(null));
        }

        @Test
        public void case1() {
            List<List<Integer>> expected = asList(asList(3), asList(9, 20), asList(15, 7));
            assertEquals(expected, levelOrder(arrayToBinaryTree(3, 9, 20, 0, 0, 15, 7)));
        }

        private List<List<Integer>> levelOrder(BinaryTreeNode root) {
            return new BinaryTree(root).levelOrder();
        }

        @SafeVarargs
        private static <T> List<T> asList(T... a) {
            return Arrays.asList(a);
        }
    }

}
