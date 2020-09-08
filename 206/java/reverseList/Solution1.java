package reverseList;

import lib.lists.linkedlists.SinglyLinkedList;
import nodes.ListNode;

class Solution1 {
    public ListNode reverseList(ListNode head) {
        return new SinglyLinkedList(head).reverse();
    }
}
