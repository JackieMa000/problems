package commons;

import nodes.ListNode;

public class LinkedList {
//    ToDo: Need to add unit tests
    //    reverse the nodes before a certain node
    public static ListNode reverseBefore(ListNode head, ListNode node) {
        ListNode pre = node, cur = head, next;
        while (cur != node) {
            next = cur.next;
            cur.next = pre;
            pre = cur;cur = next;
        }
        return pre;
    }

    //    Reverse the commons.linkedlist from node1 to node2.
    public static ListNode reverseFromTo(ListNode head, ListNode from, ListNode to) {
        ListNode dummy = new ListNode();dummy.next = head;
        ListNode groupPre = dummy;

//        Search for "from" node
        ListNode cur = head;
        while (cur != from) {
            groupPre = cur;
            cur = cur.next;
        }

//        Reverse from the current node to the "to" node
        ListNode pre = to, next;
        while (cur != to) {
            next = cur.next;
            cur.next = pre;
            pre = cur;cur = next;
        }

//        Append the reversed group nodes to the groupPre
        groupPre.next = pre;

        return dummy.next;
    }
}
