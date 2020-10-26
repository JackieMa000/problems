package dsa.lib.lists.linkedlists;

import dsa.nodes.ListNode;
import org.junit.Test;

import static dsa.testing.DSAAssert.assertArrayEqualsLinkedList;
import static org.junit.Assert.*;

public class LinkedListTest1 extends LinkedListTestFX {

    public static class ReverseTest {
        @Test
        public void case1() {
            ListNode head = arrayToSinglyLinkedlist(new int[]{1});
            assertArrayEqualsLinkedList(new int[]{1}, reverse(head));
        }

        @Test
        public void case2() {
            ListNode head = arrayToSinglyLinkedlist(new int[]{1, 2, 3});
            assertArrayEqualsLinkedList(new int[]{3, 2, 1}, reverse(head));
        }

        private ListNode reverse(ListNode head) {
            return new LinkedList(head).reverse();
        }
    }

    public static class ReverseBeforeTest {
        @Test
        public void case1() {
            ListNode head = arrayToSinglyLinkedlist(new int[]{1, 2, 3});
            assertArrayEqualsLinkedList(new int[]{1, 2, 3}, reverseBeforeIndex(head, 0));
        }

        @Test
        public void case2() {
            ListNode head = arrayToSinglyLinkedlist(new int[]{1, 2, 3});
            assertArrayEqualsLinkedList(new int[]{2, 1, 3}, reverseBeforeIndex(head, 2));
        }

        private ListNode reverseBeforeIndex(ListNode head, int idx) {
            LinkedList ls = new LinkedList(head);
            return ls.reverseBefore(ls.getNodeByIndex(idx));
        }
    }

    public static class ReverseFromToTest {
        @Test
        public void case1() {
            ListNode head = reverseFromTo(arrayToSinglyLinkedlist(new int[]{1, 2}), 0, 0);
            assertArrayEqualsLinkedList(new int[]{1, 2}, head);
        }

        @Test
        public void case2() {
            ListNode head = reverseFromTo(arrayToSinglyLinkedlist(new int[]{1, 2, 3, 4, 5}), 0, 4);
            assertArrayEqualsLinkedList(new int[]{4, 3, 2, 1, 5}, head);
        }

        @Test
        public void case3() {
            ListNode head = reverseFromTo(arrayToSinglyLinkedlist(new int[]{1, 2, 3, 4, 5}), 1, 4);
            assertArrayEqualsLinkedList(new int[]{1, 4, 3, 2, 5}, head);
        }

        private ListNode reverseFromTo(ListNode head, int from, int to) {
            LinkedList ls = new LinkedList(head);
            return ls.reverseFromTo(ls.getNodeByIndex(from), ls.getNodeByIndex(to));
        }
    }

    public static class HasCycleTest {
        @Test
        public void case1() {
            assertFalse(hasCycle(arrayToSinglyLinkedlist(new int[]{1, 2})));
        }

        @Test
        public void case2() {
            assertTrue(hasCycle(arrayToCyclicSinglyLinkedlist(new int[]{1, 2}, 0)));
        }

        @Test
        public void case3() {
            assertTrue(hasCycle(arrayToCyclicSinglyLinkedlist(new int[]{3, 2, 0, 4}, 1)));
        }

        private boolean hasCycle(ListNode head) {
            return new LinkedList(head).hasCycle();
        }
    }

    public static class DetectCycleTest {
        @Test
        public void case1() {
            assertNull(detectCycle(arrayToSinglyLinkedlist(new int[]{1})));
        }

        @Test
        public void case2() {
            ListNode head = arrayToCyclicSinglyLinkedlist(new int[]{1, 2}, 0);
            assertEquals(getLinkedListNodeByIndex(head, 0), detectCycle(head));
        }

        @Test
        public void case3() {
            ListNode head = arrayToCyclicSinglyLinkedlist(new int[]{3, 2, 0, -4}, 1);
            assertEquals(getLinkedListNodeByIndex(head, 1), detectCycle(head));
        }

        private ListNode detectCycle(ListNode head) {
            return new LinkedList(head).detectCycle();
        }
    }

    public static class SwapPairs {
        @Test
        public void emptyList() {
            assertArrayEqualsLinkedList(new int[]{}, swapPairs(arrayToSinglyLinkedlist(new int[]{})));
        }

        @Test
        public void oneNode() {
            assertArrayEqualsLinkedList(new int[]{1}, swapPairs(arrayToSinglyLinkedlist(new int[]{1})));
        }

        @Test
        public void case1() {
            assertArrayEqualsLinkedList(new int[]{2, 1, 4, 3}, swapPairs(arrayToSinglyLinkedlist(new int[]{1, 2, 3, 4})));
        }

        private ListNode swapPairs(ListNode head) {
            return new LinkedList(head).swapPairs();
        }
    }
}