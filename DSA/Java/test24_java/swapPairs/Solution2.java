package test24_java.swapPairs;

import nodes.ListNode;

public class Solution2 {
    public ListNode swapPairs(ListNode head) {
        ListNode dummyNode = new ListNode();dummyNode.next = head;
        return recursion(dummyNode);
    }

    private ListNode recursion(ListNode prev) {
        if (prev.next != null && prev.next.next != null) {
            ListNode p = prev.next, q = p.next;
            prev.next = q;p.next = recursion(q);q.next = p;
        }
        return prev.next;
    }
}
