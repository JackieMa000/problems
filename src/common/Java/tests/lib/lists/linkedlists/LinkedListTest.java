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
            ListNode head = new Array(new int[]{1}).toSinglyLinkedList();
            ListNode actual = new LinkedList(head).getNodeByIndex(0);
            assertEquals(1, actual.val);
        }

        @Test
        public void case2() {
            ListNode head = new Array(new int[]{1, 2, 3}).toSinglyLinkedList();
            ListNode actual = new LinkedList(head).getNodeByIndex(2);
            assertEquals(3, actual.val);
        }
    }
}
