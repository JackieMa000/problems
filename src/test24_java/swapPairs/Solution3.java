package swapPairs;

import nodes.ListNode;


public class Solution3 {
    // Recursion
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) return head;

        ListNode newStart = head.next.next;
        ListNode p = head, q = p.next;
        head = q;p.next = swapPairs(newStart);q.next = p;

        return head;
    }
}
