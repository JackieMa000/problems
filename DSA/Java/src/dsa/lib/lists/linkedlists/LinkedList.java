package dsa.lib.lists.linkedlists;

import dsa.nodes.ListNode;

import java.util.HashSet;
import java.util.Set;

public class LinkedList extends Base {

    public LinkedList(ListNode head) {
        super(head);
    }

    // LeetCode206
    public ListNode reverse() {
        ListNode pre = null;
        ListNode cur = this.head;
        ListNode next;

        while (cur != null) {
            next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }

    //    reverse the nodes before a certain node
    public ListNode reverseBefore(ListNode node) {
        return reverseBefore1(this.head, node);
    }

    private static ListNode reverseBefore1(ListNode head, ListNode node) {
        ListNode pre = node, cur = head, next;
        while (cur != node) {
            next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    //      Reverse the nodes range fnode tnode, doesn't include the *tnode* node.
    public ListNode reverseFromTo(ListNode fnode, ListNode tnode) {
        ListNode cur = this.head;
        ListNode dummy = new ListNode();
        dummy.next = cur;
        ListNode groupPre = dummy;

//      1. Search for the fnode node. Get the group previous node;
        while (cur != fnode) {
            groupPre = cur;
            cur = cur.next;
        }

//      2. Reverse the group nodes;
//        Append the reversed group dsa.nodes tnode the groupPre
        groupPre.next = reverseBefore1(fnode, tnode);

        return dummy.next;
    }

    // LeetCode141
    public boolean hasCycle() {
        return hasCycle2(this.head);
    }

    // Rule: Hash Table
    private static boolean hasCycle1(ListNode head) {
        Set<ListNode> found = new HashSet<>();
        while (head != null) {
            if (found.contains(head)) return true;
            found.add(head);
            head = head.next;
        }
        return false;
    }

    /**
     * Rule:
     * Two Pointers
     * Fast and Slow Pointers
     * Tortoise and Hare Algorithm
     */
    private static boolean hasCycle2(ListNode head) {
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) return true;
        }
        return false;
    }

    // LeetCode142
    public ListNode detectCycle() {
        return detectCycle1(this.head);
    }

    // Hash Set
    private static ListNode detectCycle1(ListNode head) {
        Set<ListNode> found = new HashSet<>();
        while (head != null) {
            if (found.contains(head)) return head; // There is a cycle
            found.add(head);
            head = head.next;
        }
        return null; // There is no cycle

    }

    // 2 pointers
    private static ListNode detectCycle2(ListNode head) {
        ListNode slow = head, fast = head, start = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) { // There is a cycle
//                Get the cycle entry node
                while (slow != start) {
                    slow = slow.next;
                    start = start.next;
                }
                return start;
            }
        }
        return null; // There is no a cycle
    }

    // Clean Code Version
    private static ListNode detectCycle21(ListNode head) {
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (isCyclic(slow, fast)) {
                return getCycleEntryNode(head, slow);
            }
        }
        return null;
    }

    private static ListNode getCycleEntryNode(ListNode head, ListNode slow) {
        ListNode start = head;
        while (slow != start) {
            slow = slow.next;
            start = start.next;
        }
        return start;
    }

    private static boolean isCyclic(ListNode slow, ListNode fast) {
        return slow == fast;
    }

}
