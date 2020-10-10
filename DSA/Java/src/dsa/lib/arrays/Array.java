package dsa.lib.arrays;

import dsa.lib.lists.linkedlists.SinglyLinkedList;
import dsa.nodes.BinaryTreeNode;
import dsa.nodes.ListNode;

public class Array {
    private final int[] ary;
    public final int length;

    public Array(int[] ary) {
        this.ary = ary;
        this.length = ary.length;
    }

    public ListNode toSinglyLinkedList() {
        ListNode dummyNode = new ListNode(0);
        ListNode head = new ListNode(this.ary[0]);
        dummyNode.next = head;

        for (int i = 1; i < this.length; i++) {
            head.next = new ListNode(this.ary[i]);
            head = head.next;
        }

        return dummyNode.next;
    }

    /**
     * To represent a cycle in the given linked list, we use an integer pos which represents
     * the position (0-indexed) in the linked list where tail connects to. If pos is -1, then
     * there is no cycle in the linked list.
     */
    public ListNode toCyclicSinglyLinkedList(int pos) {
        ListNode head = this.toSinglyLinkedList();

        if (pos != -1) {
            SinglyLinkedList ls = new SinglyLinkedList(head);
            ListNode tail = ls.getNodeByIndex(ls.size() - 1);
            tail.next = ls.getNodeByIndex(pos);
        }

        return head;
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
