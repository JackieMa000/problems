package dsa.lib.lists.linkedlists;

import dsa.lib.arrays.Array;
import dsa.nodes.ListNode;
import org.junit.Test;

import static dsa.testing.DSAAssert.*;
import static org.junit.Assert.*;

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
            return new SinglyLinkedList(head).toArray();
        }
    }

    public static class ReverseTest {
        @Test
        public void case1() {
            ListNode head = new Array(new int[]{1}).toSinglyLinkedList();
            assertArrayEqualsLinkedList(new int[]{1}, new SinglyLinkedList(head).reverse());
        }

        @Test
        public void case2() {
            ListNode head = new Array(new int[]{1, 2, 3}).toSinglyLinkedList();
            assertArrayEqualsLinkedList(new int[]{3, 2, 1}, new SinglyLinkedList(head).reverse());
        }
    }

    public static class ReverseBeforeTest {
        @Test
        public void case1() {
            ListNode head = new Array(new int[]{1, 2, 3}).toSinglyLinkedList();
            SinglyLinkedList ls = new SinglyLinkedList(head);
            assertArrayEqualsLinkedList(new int[]{1, 2, 3}, ls.reverseBefore(ls.getNodeByIndex(0)));
        }

        @Test
        public void case2() {
            ListNode head = new Array(new int[]{1, 2, 3}).toSinglyLinkedList();
            SinglyLinkedList ls = new SinglyLinkedList(head);
            assertArrayEqualsLinkedList(new int[]{2, 1, 3}, ls.reverseBefore(ls.getNodeByIndex(2)));
        }
    }

    public static class ReverseFromToTest {
        @Test
        public void case1() {
            ListNode head = new Array(new int[]{1, 2}).toSinglyLinkedList();
            SinglyLinkedList ls = new SinglyLinkedList(head);
            ListNode fnode = ls.getNodeByIndex(0);
            ListNode tnode = ls.getNodeByIndex(0);
            assertArrayEqualsLinkedList(new int[]{1, 2}, ls.reverseFromTo(fnode, tnode));
        }

        @Test
        public void case2() {
            ListNode head = new Array(new int[]{1, 2, 3, 4, 5}).toSinglyLinkedList();
            SinglyLinkedList ls = new SinglyLinkedList(head);
            ListNode fnode = ls.getNodeByIndex(0);
            ListNode tnode = ls.getNodeByIndex(4);
            assertArrayEqualsLinkedList(new int[]{4, 3, 2, 1, 5}, ls.reverseFromTo(fnode, tnode));
        }

        @Test
        public void case3() {
            ListNode head = new Array(new int[]{1, 2, 3, 4, 5}).toSinglyLinkedList();
            SinglyLinkedList ls = new SinglyLinkedList(head);
            ListNode fnode = ls.getNodeByIndex(1);
            ListNode tnode = ls.getNodeByIndex(4);
            assertArrayEqualsLinkedList(new int[]{1, 4, 3, 2, 5}, ls.reverseFromTo(fnode, tnode));
        }

    }

}
