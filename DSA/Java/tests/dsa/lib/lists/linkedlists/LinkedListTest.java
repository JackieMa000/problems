package dsa.lib.lists.linkedlists;

import dsa.nodes.ListNode;
import org.junit.Test;

import static org.junit.Assert.*;

public class LinkedListTest extends LinkedListTestFX {

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
            return new LinkedList(head).toArrayInt();
        }
    }

    public static class SizeTest {

        private int getSize(ListNode head) {
            return new LinkedList(head).size();
        }

        @Test
        public void case1() {
            assertEquals(1, getSize(arrayToSinglyLinkedlist(new int[]{1})));
        }

        @Test
        public void case2() {
            assertEquals(3, getSize(arrayToSinglyLinkedlist(new int[]{1, 2, 3})));
        }

        @Test
        public void case3() {
            assertEquals(4, getSize(arrayToSinglyLinkedlist(new int[]{1, 2, 3, 4})));
        }
    }

    public static class GetNodeByIndexTest {

        @Test
        public void case1() {
            assertEquals(1, getLinkedListNodeByIndex(arrayToSinglyLinkedlist(new int[]{1}), 0).val);
        }

        @Test
        public void case2() {
            assertEquals(3, getLinkedListNodeByIndex(arrayToSinglyLinkedlist(new int[]{1, 2, 3}), 2).val);
        }

        @Test
        public void indexNotExist() {
            assertNull(getLinkedListNodeByIndex(arrayToSinglyLinkedlist(new int[]{1}), 2));
        }
    }

    public static class GetNodeByValueTest {
        @Test
        public void case1() {
            assertEquals(1, getNodeByValue(arrayToSinglyLinkedlist(new int[]{1}), 1).val);
        }

        @Test
        public void case2() {
            assertEquals(2, getNodeByValue(arrayToSinglyLinkedlist(new int[]{1, 2, 3}), 2).val);
        }

        @Test
        public void valueNotExist() {
            assertNull(getNodeByValue(arrayToSinglyLinkedlist(new int[]{1}), 4));
        }

        private ListNode getNodeByValue(ListNode head, int val) {
            return new LinkedList(head).getNodeByValue(val);
        }

    }
}
