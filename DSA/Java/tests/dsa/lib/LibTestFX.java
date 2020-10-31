package dsa.lib;

import dsa.lib.arrays.ArrayInt;
import dsa.lib.lists.linkedlists.SinglyLinkedList;
import dsa.nodes.BinaryTreeNode;
import dsa.nodes.ListNode;

public class LibTestFX {
    public static BinaryTreeNode arrayToBinaryTree(int[] ary) {
        return new ArrayInt(ary).toBinaryTree();
    }

    public static ListNode getLinkedListNodeByIndex(ListNode head, int idx) {
        return new SinglyLinkedList(head).getNodeByIndex(idx);
    }

}
