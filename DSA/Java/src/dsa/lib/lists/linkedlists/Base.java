package dsa.lib.lists.linkedlists;

import dsa.lib.lists.List;
import dsa.nodes.ListNode;

public class Base implements List {
    final ListNode head;

    public Base(ListNode head) {
        this.head = head;
    }

    @Override
    public final int size() {
        ListNode cur = this.head;
        int n;
        for (n = 0; cur != null; n++) cur = cur.next;
        return n;
    }

    public final int[] toArrayInt() {
        if (this.head == null) return null;
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
