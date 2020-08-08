package lib.lists.arrays;

import nodes.BinaryTreeNode;
import nodes.ListNode;

public class Array {
    private final int[] array;

    public Array(int[] array) {
        this.array = array;
    }

    public ListNode toSinglyLinkedList() {
        ListNode dummyNode = new ListNode(0);
        ListNode head = new ListNode(this.array[0]);
        dummyNode.next = head;

        for (int i = 1; i < this.array.length; i++) {
            head.next = new ListNode(this.array[i]);
            head = head.next;
        }

        return dummyNode.next;
    }

    public BinaryTreeNode toBinaryTree() {
        BinaryTreeNode root = new BinaryTreeNode(this.array[0]);
        generateTreeFromArray(this.array, this.array.length, root, 0);
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
