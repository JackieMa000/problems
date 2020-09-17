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

    public static void assertArrayEqualsTree(int[] array, BinaryTreeNode root) {
        assertArrayEqualsTreeDfs(array, root, 0);
    }

    private static void assertArrayEqualsTreeDfs(int[] array, BinaryTreeNode root, int i) {
        if (i >= array.length) return;
        if (root == null) {
            assertEquals(0, array[i]);
            return;
        }
        assertEquals(root.val, array[i]);
        assertArrayEqualsTreeDfs(array, root.left, 2 * i + 1);
        assertArrayEqualsTreeDfs(array, root.right, 2 * i + 2);
    }
}
