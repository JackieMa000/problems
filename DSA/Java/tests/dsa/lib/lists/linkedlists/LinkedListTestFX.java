package dsa.lib.lists.linkedlists;

import dsa.lib.arrays.ArrayInt;
import dsa.lib.lists.ListFX;
import dsa.nodes.ListNode;

public class LinkedListTestFX extends ListFX {
    protected static ListNode arrayToSinglyLinkedlist(int[] ary) {
        return new ArrayInt(ary).toSinglyLinkedList();
    }
}
