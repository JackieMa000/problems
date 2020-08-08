package detectCycle;

import nodes.ListNode;


public class Solution3 {
    // Clean Code Version
    public ListNode detectCycle(ListNode head) {
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next; fast = fast.next.next;
            if (isCyclic(slow, fast)) {
                return getCycleNode(slow, head);
            }
        }
        return null;
    }

    private ListNode getCycleNode(ListNode slow, ListNode head) {
        ListNode start = head;
        while (slow != start) {
            slow = slow.next; start = start.next;
        }
        return start;
    }

    private boolean isCyclic(ListNode slow, ListNode fast) {
        return slow == fast;
    }
}
