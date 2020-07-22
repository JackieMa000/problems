package tests;

import nodes.ListNode;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNull;

public class DSAAssert {
    public static void assertArrayEqualsLinkedList(int[] array, ListNode head) {
        int i = 0, n = array.length;
        while (i < n && head != null) {
            assertEquals(array[i], head.val);
            i++; head = head.next;
        }
        assertEquals(n, i);
        assertNull(head);
    }
}
