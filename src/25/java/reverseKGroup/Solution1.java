package reverseKGroup;

import lib.lists.linkedlists.SinglyLinkedList;
import nodes.ListNode;

public class Solution1 {
    //    Iterative
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummy = new ListNode();
        dummy.next = head;
        ListNode pre = dummy, cur = head;

        while (true) {
            //        1. Generate current kgroup nodes;
            for (int i = 0; i < k; i++) {
                if (cur == null) return dummy.next;
                cur = cur.next;
            }

            //        2. Reverse the current kgroup nodes;
            //        4. Append the current reversed group nodes to the group prev node.
            pre.next = new SinglyLinkedList(head).reverseBefore(cur);

            //  go to the next group;
            pre = head;
            head = cur;
        }
    }

    public ListNode reverseKGroup1(ListNode head, int k) {
        ListNode groupHead = head;
        ListNode cur = head;

        while (true) {
//        1. Generate current kgroup nodes;
            for (int i = 0; i < k; i++) {
                if (cur == null) return head;
                cur = cur.next;
            }

//        2. Reverse the current kgroup nodes;
            head = new SinglyLinkedList(head).reverseFromTo(groupHead, cur);

//        3. go to the next group
            groupHead = cur;
        }
    }
}
