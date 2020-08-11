package nodes;

public class ListNode extends Node {
    public ListNode next;

    public ListNode() {
        super();
    }

    public ListNode(int val) {
        super(val);
    }

    public ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}
