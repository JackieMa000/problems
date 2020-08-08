package detectCycle;

import nodes.ListNode;

import java.util.HashSet;
import java.util.Set;

public class Solution1 {
    // Hash Set
    public ListNode detectCycle(ListNode head) {
        Set<ListNode> found = new HashSet<>();
        while (head != null) {
            if (found.contains(head)) return head; // There is a cycle
            found.add(head);
            head = head.next;
        }
        return null; // There is no cycle

    }
}
