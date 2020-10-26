package dsa.nodes.generics;

public class ListNode<T> extends Node<T> {
    public ListNode<T> next;

    public ListNode() {
        super();
        next = null;
    }

    public ListNode(T val) {
        super(val);
        next = null;
    }

    public ListNode(T val, ListNode<T> next) {
        this.val = val;
        this.next = next;
    }
}
