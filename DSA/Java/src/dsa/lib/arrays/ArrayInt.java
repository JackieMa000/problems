package dsa.lib.arrays;

import dsa.nodes.BinaryTreeNode;
import dsa.nodes.ListNode;

public class ArrayInt {
    public final int[] ary;
    public final int length;

    public ArrayInt(int[] ary) {
        this.ary = ary;
        this.length = ary.length;
    }

    public ListNode toSinglyLinkedList() {
        return toCyclicSinglyLinkedList(-1);
    }

    /**
     * To represent a cycle in the given linked list, we use an integer pos which represents
     * the position (0-indexed) in the linked list where tail connects to. If pos is -1, then
     * there is no cycle in the linked list.
     */
    public ListNode toCyclicSinglyLinkedList(int pos) {
        if (this.length == 0 || this.ary[0] == 0) return null;
        ListNode dummy = new ListNode();
        ListNode head = new ListNode(this.ary[0]);
        dummy.next = head;
        ListNode cycleEntryNode = head;

        for (int i = 1; i < this.length; i++) {
            ListNode node = new ListNode(this.ary[i]);
            head.next = node;
            if (i == pos) cycleEntryNode = node;
            head = head.next;
        }

        if (pos >= 0) head.next = cycleEntryNode;

        return dummy.next;
    }

    public BinaryTreeNode toBinaryTree() {
        if (this.ary.length == 0 || this.ary[0] == 0) return null;
        BinaryTreeNode root = new BinaryTreeNode(this.ary[0]);
        generateTreeFromArray(this.ary, this.length, root, 0);
        return root;
    }

    private static void generateTreeFromArray(int[] ary, int n, BinaryTreeNode root, int i) {
        int lpos = 2 * i + 1, rpos = 2 * i + 2;
        if (lpos < n && ary[lpos] != 0) {
            root.left = new BinaryTreeNode(ary[lpos]);
            generateTreeFromArray(ary, n, root.left, lpos);
        }
        if (rpos < n && ary[rpos] != 0) {
            root.right = new BinaryTreeNode(ary[rpos]);
            generateTreeFromArray(ary, n, root.right, rpos);
        }
    }
}
