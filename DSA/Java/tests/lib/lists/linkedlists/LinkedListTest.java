package lib.lists.linkedlists;

import nodes.ListNode;
import org.junit.Test;

import static org.junit.Assert.*;

public class LinkedListTest extends LinkedListTestFX {

    public static class SizeTest {

        private int getSize(ListNode head) {
            return new LinkedList(head).size();
        }

        @Test
        public void case1() {
            assertEquals(1, getSize(generateSinglyLinkedListFromArray(new int[]{1})));
        }

        @Test
        public void case2() {
            assertEquals(3, getSize(generateSinglyLinkedListFromArray(new int[]{1, 2, 3})));
        }

        @Test
        public void case3() {
            assertEquals(4, getSize(generateSinglyLinkedListFromArray(new int[]{1, 2, 3, 4})));
        }
    }

    public static class GetNodeByIndexTest {

        @Test
        public void case1() {
            assertEquals(1, getNodeByIndex(generateSinglyLinkedListFromArray(new int[]{1}), 0).val);
        }

        @Test
        public void case2() {
            assertEquals(3, getNodeByIndex(generateSinglyLinkedListFromArray(new int[]{1, 2, 3}), 2).val);
        }

        @Test
        public void indexNotExist() {
            assertNull(getNodeByIndex(generateSinglyLinkedListFromArray(new int[]{1}), 2));
        }

        private ListNode getNodeByIndex(ListNode head, int idx) {
            return new LinkedList(head).getNodeByIndex(idx);
        }

    }

    public static class GetNodeByValueTest {
        @Test
        public void case1() {
            assertEquals(1, getNodeByValue(generateSinglyLinkedListFromArray(new int[]{1}), 1).val);
        }

        @Test
        public void case2() {
            assertEquals(2, getNodeByValue(generateSinglyLinkedListFromArray(new int[]{1, 2, 3}), 2).val);
        }

        @Test
        public void valueNotExist() {
            assertNull(getNodeByValue(generateSinglyLinkedListFromArray(new int[]{1}), 4));
        }

        private ListNode getNodeByValue(ListNode head, int val) {
            return new LinkedList(head).getNodeByValue(val);
        }

    }
}
