package lib.lists.arrays;

import lib.lists.linkedlists.SinglyLinkedList;
import nodes.BinaryTreeNode;
import nodes.ListNode;

public class Array {
    private final int[] array;
    public final int length;

    public Array(int[] array) {
        this.array = array;
        this.length = this.array.length;
    }

    public ListNode toSinglyLinkedList() {
        ListNode dummyNode = new ListNode(0);
        ListNode head = new ListNode(this.array[0]);
        dummyNode.next = head;

        for (int i = 1; i < this.length; i++) {
            head.next = new ListNode(this.array[i]);
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
        BinaryTreeNode root = new BinaryTreeNode(this.array[0]);
        generateTreeFromArray(this.array, this.length, root, 0);
        return root;
    }

    private static void generateTreeFromArray(int[] array, int n, BinaryTreeNode root, int i) {
        int lpos = 2 * i + 1, rpos = 2 * i + 2;
        if (lpos < n && array[lpos] != 0) {
            root.left = new BinaryTreeNode(array[lpos]);
            generateTreeFromArray(array, n, root.left, lpos);
        }
        if (rpos < n && array[rpos] != 0) {
            root.right = new BinaryTreeNode(array[rpos]);
            generateTreeFromArray(array, n, root.right, rpos);
        }
    }
}
