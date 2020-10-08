package dsa.lib.lists.linkedlists;

import dsa.lib.arrays.Array;
import dsa.nodes.ListNode;

public class LinkedListTestFX {
    protected static ListNode arrayToLinkedlist(int[] ary) {
        return new Array(ary).toSinglyLinkedList();
    }
}
