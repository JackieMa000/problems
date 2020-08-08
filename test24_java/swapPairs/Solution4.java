package swapPairs;

import nodes.ListNode;

public class Solution4 {
    public ListNode swapPairs(ListNode head) {
        ListNode dummyNode = new ListNode();dummyNode.next = head;
        return recursion(dummyNode);
    }

    private ListNode recursion(ListNode prev) {
        if (prev.next != null && prev.next.next != null) {
            ListNode p = prev.next, q = p.next;
            prev.next = q; p.next = q.next; q.next = p;
            recursion(prev.next.next);
        }
        return prev.next;
    }
}
