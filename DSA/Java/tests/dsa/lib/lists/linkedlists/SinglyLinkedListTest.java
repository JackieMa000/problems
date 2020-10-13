package dsa.lib.lists.linkedlists;

import dsa.nodes.ListNode;
import org.junit.Test;

import static dsa.testing.DSAAssert.assertArrayEqualsLinkedList;
import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertNull;

public class SinglyLinkedListTest extends SinglyLinkedListTestFX {

    public static class ToArrayTest {
        @Test
        public void nullList() {
            assertNull(toArray(null));
        }

        @Test
        public void case1() {
            int[] ary = {1, 2, 3, 4};
            assertArrayEquals(ary, toArray(arrayToSinglyLinkedlist(ary)));
        }

        private int[] toArray(ListNode head) {
            return new SinglyLinkedList(head).toArrayInt();
        }
    }

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
            return new SinglyLinkedList(head).reverse();
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
            SinglyLinkedList ls = new SinglyLinkedList(head);
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
            SinglyLinkedList ls = new SinglyLinkedList(head);
            return ls.reverseFromTo(ls.getNodeByIndex(from), ls.getNodeByIndex(to));
        }
    }
}
