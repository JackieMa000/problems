package hasCycle;

import nodes.ListNode;

public class Solution2 {
    /**
     * Two Pointers
     * Fast and Slow Pointers
     * Tortoise and Hare Algorithm
     */
    public boolean hasCycle(ListNode head) {
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next; fast = fast.next.next;
            if (slow == fast) return true;
        }
        return false;
    }
}
