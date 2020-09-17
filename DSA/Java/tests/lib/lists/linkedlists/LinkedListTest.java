package lib.lists.linkedlists;

import lib.lists.arrays.Array;
import nodes.ListNode;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class LinkedListTest {
    public static class SizeTest {

        @Test
        public void case1() {
//            ToDo
        }
    }

    public static class GetNodeByIndexTest {

        @Test
        public void case1() {
            ListNode head = getSinglyLinkedList(new int[]{1});
            ListNode actual = new LinkedList(head).getNodeByIndex(0);
            assertEquals(1, actual.val);
        }

        @Test
        public void case2() {
            ListNode head = getSinglyLinkedList(new int[]{1, 2, 3});
            ListNode actual = new LinkedList(head).getNodeByIndex(2);
            assertEquals(3, actual.val);
        }

        private ListNode getSinglyLinkedList(int[] ary) {
            return new Array(ary).toSinglyLinkedList();
        }
    }
}
