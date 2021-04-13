package dsa.lib.arrays;

import dsa.nodes.ListNode;
import org.junit.Test;

import static dsa.testing.DSAAssert.assertArrayEqualsLinkedList;
import static dsa.testing.DSAAssert.assertArrayEqualsTree;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNull;

public class ArrayTest extends ArrayTestFx {

    public static class toSinglyLinkedListTest {
        @Test
        public void emptyArray() {
            assertNull(toLinkedList(new int[]{}));
        }

        @Test
        public void firstElement0() {
            assertNull(toLinkedList(new int[]{0}));
            assertNull(toLinkedList(new int[]{0, 1}));
        }

        @Test
        public void case1() {
            int[] ary = {1, 2, 3, 4};
            assertArrayEqualsLinkedList(ary, toLinkedList(ary));
        }

        private ListNode toLinkedList(int[] ary) {
            return arrayToSinglyLinkedlist(ary);
        }
    }

    public static class toCyclicSinglyLinkedListTest {

        @Test
        public void posMinus() {
            int[] ary = {1, 2, 3};
            assertArrayEqualsLinkedList(ary, getCyclicSinglyLinkedList(ary, -1));
        }

        @Test
        public void posMinus1() {
            int[] ary = {1, 2, 3};
            assertArrayEqualsLinkedList(ary, getCyclicSinglyLinkedList(ary, -2));
        }

        @Test
        public void case1() {
            ListNode head = getCyclicSinglyLinkedList(new int[]{1, 2}, 0);
            assertEquals(2, getLinkedListNodeByIndex(head, 3).val);
        }

        @Test
        public void case2() {
            ListNode head = getCyclicSinglyLinkedList(new int[]{1, 2, 3}, 1);
            assertEquals(2, getLinkedListNodeByIndex(head, 3).val);
        }

        @Test
        public void case3() {
            ListNode head = getCyclicSinglyLinkedList(new int[]{1, 2, 3}, 2);
            assertEquals(3, getLinkedListNodeByIndex(head, 4).val);
        }

        private ListNode getCyclicSinglyLinkedList(int[] ary, int pos) {
            return arrayToCyclicSinglyLinkedlist(ary, pos);
        }
    }

    public static class toBinaryTreeTest {
        @Test
        public void emptyArray() {
            assertNull(arrayToBinaryTree(new int[]{}));
        }

        @Test
        public void firstElement0() {
            assertNull(arrayToBinaryTree(new int[]{0}));
            assertNull(arrayToBinaryTree(new int[]{0, 1}));
        }

        @Test
        public void case1() {
            int[] array = {3, 1, 5, 0, 2};
            assertArrayEqualsTree(array, arrayToBinaryTree(array));
        }

        @Test
        public void case2() {
            int[] array = {5, 1, 4, 0, 6, 3, 6};
            assertArrayEqualsTree(array, arrayToBinaryTree(array));
        }

        @Test
        public void case3() {
            int[] ary = {1, 0};
            assertArrayEqualsTree(ary, arrayToBinaryTree(ary));
        }

    }
}
