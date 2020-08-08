package testing;

import nodes.ListNode;
import nodes.BinaryTreeNode;

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

    public static void assertTreeEqualsArray(BinaryTreeNode root, int[] array, int i) {
//        ToDo: refactor
        if (i >= array.length) return;
        if (root == null) {
            assertEquals(0, array[i]);
            return;
        }
        assertEquals(root.val, array[i]);
        assertTreeEqualsArray(root.left, array, 2 * i + 1);
        assertTreeEqualsArray(root.right, array, 2 * i + 2);
    }
}
