package lib.lists.linkedlists;

import lib.lists.List;
import nodes.ListNode;

public class LinkedList implements List {

    final ListNode head;

    public LinkedList(ListNode head) {
        this.head = head;
    }

    @Override
    public final int size() {
        ListNode cur = this.head;
        int n;
        for (n = 0; cur != null; n++) cur = cur.next;
        return n;
    }

    public final int[] toArray() {
        ListNode cur = this.head;
        int[] res = new int[this.size()];
        for (int i = 0; cur != null; i++, cur = cur.next) res[i] = cur.val;
        return res;
    }

    public ListNode getNodeByIndex(int idx) {
        ListNode cur = this.head;
        for (int i = 0; i < idx && cur != null; i++) cur = cur.next;
        return cur;
    }

    public ListNode getNodeByValue(int val) {
        ListNode cur = this.head;
        while (cur != null && cur.val != val) cur = cur.next;
        return cur;
    }
}
