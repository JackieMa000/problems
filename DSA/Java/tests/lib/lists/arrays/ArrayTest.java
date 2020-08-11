package lib.lists.arrays;

import nodes.BinaryTreeNode;
import org.junit.Test;

import static testing.DSAAssert.assertArrayEqualsLinkedList;
import static testing.DSAAssert.assertTreeEqualsArray;

public class ArrayTest {
    public static class toSinglyLinkedListTest {
        @Test
        public void case1() {
            assertArrayEqualsLinkedList(new int[]{1, 2, 3, 4}, new Array(new int[]{1, 2, 3, 4}).toSinglyLinkedList());
        }
    }

    public static class toBinaryTreeTest {
        @Test
        public void case1() {
            BinaryTreeNode actual = new Array(new int[]{3, 1, 5, 0, 2}).toBinaryTree();
            assertTreeEqualsArray(actual, new int[]{3, 1, 5, 0, 2}, 0);
        }

        @Test
        public void case2() {
            BinaryTreeNode actual = new Array(new int[]{5, 1, 4, 0, 6, 3, 6}).toBinaryTree();
            assertTreeEqualsArray(actual, new int[]{5, 1, 4, 0, 6, 3, 6}, 0);
        }
    }
}
