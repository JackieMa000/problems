package dsa.nodes.generics;

public class ListNode<T> extends Node {
    public ListNode next;

//    public ListNode() {
//        super();
//    }

    public ListNode(T val) {
        super(val);
    }

    public ListNode(T val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}
