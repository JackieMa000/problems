package reverseKGroup;

import lib.lists.linkedlists.SinglyLinkedList;
import nodes.ListNode;


public class Solution2 {
//    Recursive
    public ListNode reverseKGroup(ListNode head, int k) {
//        1. Generate nodes for the current group;
        ListNode cur = head;
        for (int i = 0; i < k; i++) {
            // Edge case. Terminator
            if (cur == null) return head;
            cur = cur.next;
        }
//        2. Reverse the nodes for the current group;
        ListNode newHead = new SinglyLinkedList(head).reverseBefore(cur);

//        3. Reverse the nodes for the next group;
//        4. Append the next group to the current
        head.next = reverseKGroup(cur, k);

        return newHead;
    }
}
