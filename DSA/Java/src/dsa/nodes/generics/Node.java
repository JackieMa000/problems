package dsa.nodes.generics;

public class Node<T> {
    public T val;

    Node() {
        int val = 0;
    }

    Node(T val) {
        this.val = val;
    }
}
