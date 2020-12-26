package dsa.lib;

import dsa.lib.arrays.ArrayInt;
import dsa.lib.lists.linkedlists.SinglyLinkedList;
import dsa.lib.trees.BinaryTree;
import dsa.nodes.BinaryTreeNode;
import dsa.nodes.ListNode;

public class LibTestFX {
    public static BinaryTreeNode arrayToBinaryTree(int[] ary) {
        return new ArrayInt(ary).toBinaryTree();
    }

    public static ListNode arrayToSinglyLinkedlist(int[] ary) {
        return new ArrayInt(ary).toSinglyLinkedList();
    }

    public static ListNode arrayToCyclicSinglyLinkedlist(int[] ary, int pos) {
        return new ArrayInt(ary).toCyclicSinglyLinkedList(pos);
    }

    public static ListNode getLinkedListNodeByIndex(ListNode head, int idx) {
        return new SinglyLinkedList(head).getNodeByIndex(idx);
    }

    public static ListNode getLinkedListNodeByValue(ListNode head, int val) {
        return new SinglyLinkedList(head).getNodeByValue(val);
    }

    public static BinaryTreeNode getTreeNodeByIndex(BinaryTreeNode root, int idx) {
        return new BinaryTree(root).getNodeByIndex(idx);
    }

    public static BinaryTreeNode getTreeNodeByValue(BinaryTreeNode root, int val) {
        return new BinaryTree(root).getNodeByValue(val);
    }
}
