package reverseList;


import converter.ListNode;

class Solution2 {
    public ListNode reverseList(ListNode head) {
        return recursion(head, null);
    }

    private ListNode recursion(ListNode head, ListNode prev) {
        if (head == null) return prev;
        ListNode next = head.next;head.next = prev;
        return recursion(next, head);
    }
}
