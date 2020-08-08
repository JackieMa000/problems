package reverseKGroup;

import lib.lists.arrays.Array;
import nodes.ListNode;
import org.junit.Before;
import org.junit.Test;

import static testing.DSAAssert.assertArrayEqualsLinkedList;

public class Solution2Test {

    private Solution2 solution;
    private ListNode head;

    @Before
    public void setUp() {
        solution = new Solution2();
        head = new Array(new int[]{1, 2, 3, 4, 5}).toSinglyLinkedList();
    }

    @Test
    public void reverse1Group() {
        assertArrayEqualsLinkedList(new int[]{1, 2, 3, 4, 5}, solution.reverseKGroup(head, 1));
    }

    @Test
    public void reverse2Group() {
        assertArrayEqualsLinkedList(new int[]{2, 1, 4, 3, 5}, solution.reverseKGroup(head, 2));
    }

    @Test
    public void reverse3Group() {
        assertArrayEqualsLinkedList(new int[]{3, 2, 1, 4, 5}, solution.reverseKGroup(head, 3));
    }
}