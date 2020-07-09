package detectCycle;

import nodes.ListNode;

public class Solution2 {
    // 2 pointers
    public ListNode detectCycle(ListNode head) {
        ListNode slow = head, fast = head, start = head;
        while (fast != null && fast.next != null) {
            slow = slow.next; fast = fast.next.next;
            if (slow == fast) { // There is a cycle
//                Get the entry location node of the cycle
                while (slow != start) {
                    slow = slow.next; start = start.next;
                }
                return start;
            }
        }
        return null; // There is no a cycle
    }
}
