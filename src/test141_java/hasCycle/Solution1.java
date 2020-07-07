package hasCycle;

import nodes.ListNode;

import java.util.HashSet;
import java.util.Set;

public class Solution1 {
//    Hash Table
    public boolean hasCycle(ListNode head) {
        Set<ListNode> found = new HashSet<>();
        while (head != null) {
            if (found.contains(head)) return true;
            found.add(head);
            head = head.next;
        }
        return false;
    }
}
