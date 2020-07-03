package swapPairs;

import nodes.ListNode;

public class Solution1 {
    public ListNode swapPairs(ListNode head) {
        ListNode dummyNode = new ListNode();dummyNode.next = head;

        ListNode prev = dummyNode;
        while (prev.next != null && prev.next.next != null) {
            ListNode p = prev.next, q = p.next;
            prev.next = q;p.next = q.next;q.next = p;
            prev = prev.next.next;
        }

        return dummyNode.next;
    }
}
