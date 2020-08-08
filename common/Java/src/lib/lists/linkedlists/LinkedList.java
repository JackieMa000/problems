package lib.lists.linkedlists;

import lib.lists.List;
import nodes.ListNode;

public class LinkedList implements List {

    ListNode head;

    public LinkedList(ListNode head) {
        this.head = head;
    }

    @Override
    public final int size() {
        ListNode cur = this.head;
        int len = 0;
        while (cur != null) {
            len++;
            cur = cur.next;
        }
        return len;
    }

    public final int[] toArray() {
        ListNode cur = this.head;
        int[] res = new int[this.size()];

        int i = 0;
        while (cur != null) {
            res[i] = cur.val;
            cur = cur.next;
            i++;
        }

        return res;
    }

    public final ListNode getNodeByIndex(int idx) {
        ListNode cur = this.head;
        for (int i = 0; i < idx; i++) {
            cur = cur.next;
        }
        return cur;
    }
}
