package lib.lists.linkedlists;

import lib.lists.arrays.Array;
import nodes.ListNode;

public class LinkedListTestFX {
    protected static ListNode generateSinglyLinkedListFromArray(int[] ary) {
        return new Array(ary).toSinglyLinkedList();
    }
}
