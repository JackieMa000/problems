package dsa.lib.arrays;

import dsa.lib.lists.linkedlists.SinglyLinkedList;
import dsa.nodes.BinaryTreeNode;
import dsa.nodes.ListNode;
import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static dsa.testing.DSAAssert.assertArrayEqualsLinkedList;
import static dsa.testing.DSAAssert.assertArrayEqualsTree;

public class ArrayTest {

    public static class toSinglyLinkedListTest {
        @Test
        public void case1() {
            int[] ary = {1, 2, 3, 4};
            assertArrayEqualsLinkedList(ary, new Array(ary).toSinglyLinkedList());
        }
    }

    public static class toCyclicSinglyLinkedListTest {

        @Test
        public void case1() {
            ListNode head = getCyclicSinglyLinkedList(new int[]{3, 2, 1, -1}, 1);
            assertEquals(2, getLinkedListNodeByIndex(head, 4).val);
        }

        @Test
        public void case2() {
            ListNode head = getCyclicSinglyLinkedList(new int[]{1, 2}, 0);
            assertEquals(2, getLinkedListNodeByIndex(head, 3).val);
        }

        @Test
        public void case3() {
            ListNode head = getCyclicSinglyLinkedList(new int[]{1}, -1);
            assertEquals(1, new SinglyLinkedList(head).size());
        }

        private static ListNode getLinkedListNodeByIndex(ListNode head, int idx) {
            return new SinglyLinkedList(head).getNodeByIndex(idx);
        }

        private ListNode getCyclicSinglyLinkedList(int[] ary, int pos) {
            return new Array(ary).toCyclicSinglyLinkedList(pos);
        }
    }

    public static class toBinaryTreeTest {
        @Test
        public void case1() {
            BinaryTreeNode actual = new Array(new int[]{3, 1, 5, 0, 2}).toBinaryTree();
            assertArrayEqualsTree(new int[]{3, 1, 5, 0, 2}, actual);
        }

        @Test
        public void case2() {
            BinaryTreeNode actual = new Array(new int[]{5, 1, 4, 0, 6, 3, 6}).toBinaryTree();
            assertArrayEqualsTree(new int[]{5, 1, 4, 0, 6, 3, 6}, actual);
        }
    }
}
