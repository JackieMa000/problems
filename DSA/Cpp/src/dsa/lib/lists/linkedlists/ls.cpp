#include "ls.h"

namespace dsa::lib::lists::linkedlists {

LinkedList::LinkedList(ListNode *head) : Base(head) {}

// reverse the nodes before a certain node
ListNode *LinkedList::reverseBefore(ListNode *node) const { return reverseBefore1(this->head, node); }
ListNode *LinkedList::reverseBefore1(ListNode *head, ListNode *node) {
    ListNode *pre, *cur, *next;
    pre = node;
    cur = head;

    while (cur != node) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}
ListNode *LinkedList::reverse() const {
    ListNode *pre, *cur, *next;
    pre = nullptr;
    cur = this->head;

    while (cur) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}
// Reverse the nodes from *fnode* to *tnode*, does not include the *tnode* node
ListNode *LinkedList::reverseFromTo(ListNode *fnode, ListNode *tnode) const {
    return reverseFromTo1(this->head, fnode, tnode);
}
ListNode *LinkedList::reverseFromTo1(ListNode *head, ListNode *fnode, ListNode *tnode) {
    ListNode *cur = head;
    ListNode dummy;
    dummy.next = cur;
    ListNode *groupPre = &dummy;

    while (cur != fnode) {
        groupPre = cur;
        cur = cur->next;
    }

    groupPre->next = reverseBefore1(fnode, tnode);

    return dummy.next;
}

bool LinkedList::hasCycle() const {
    return hasCycle1(this->head);
}
/**
 * Rule:
 * Two Pointers
 * Fast and Slow Pointers
 * Tortoise and Hare Algorithm
 */
bool LinkedList::hasCycle1(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

ListNode *LinkedList::detectCycle() const {
    return detectCycle1(this->head);
}
// 2 pointers
// Fast and Slow pointers
ListNode *LinkedList::detectCycle1(ListNode *head) {
    ListNode *slow = head, *fast = head, *start = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) { // There is a cycle
            while (slow != start) {
                slow = slow->next;
                start = start->next;
            }
            return start;
        }
    }
    return nullptr; // There is no cycle
}
ListNode *LinkedList::detectCycle11(ListNode *head) {
    ListNode *slow = head, *fast = head;

    // Determine whether there's a cycle
    while (true) {
        if (not fast || not fast->next) return nullptr; // No cycle
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    // Get the cycle entry node
    ListNode *start = head;
    while (start != slow) {
        start = start->next;
        slow = slow->next;
    }
    return start;
}

ListNode *LinkedList::swapPairs() {
    return swapPairs2(this->head);
}
//Iteration
ListNode *LinkedList::swapPairs1(ListNode *head) {
    ListNode dummy;
    dummy.next = head;

    ListNode *pre = &dummy;
    while (pre->next && pre->next->next) {
        ListNode *p = pre->next, *q = p->next;
//        swap
        pre->next = q;
        p->next = q->next;
        q->next = p;

        pre = pre->next->next;
    }

    return dummy.next;
}
// Recursion
ListNode *LinkedList::swapPairs2(ListNode *head) {
    if (head && head->next) {
        ListNode *newHead = head->next->next;
        ListNode *p = head, *q = p->next;
//        swap
        head = q;
        p->next = swapPairs2(newHead);
        q->next = p;
    }
    return head;
}
ListNode *LinkedList::swapPairs3(ListNode *head) {
    ListNode dummy;
    dummy.next = head;
    return swapPairsRecur(&dummy);
}
ListNode *LinkedList::swapPairsRecur(ListNode *prev) {
    if (prev->next && prev->next->next) {
        ListNode *p = prev->next, *q = p->next;
        prev->next = q;
        p->next = swapPairsRecur(q);
        q->next = p;
    }
    return prev->next;
}

ListNode *LinkedList::reverseKGroup(int k) {
    return reverseKGroup3(this->head, k);
}
// Iterative
// Rule: Cut the LinkedList into the small piece of individual LinkedLists
ListNode *LinkedList::reverseKGroup1(ListNode *head, int k) {
    ListNode dummy;
    dummy.next = head;

    ListNode *pre = &dummy, *cur = head;
    while (true) {
//        generate the nodes for a group
        for (int i = 0; i < k; i++) {
            if (!cur) return dummy.next;
            cur = cur->next;
        }

//        reverse the nodes in the group
//        connect it with group prev node(aka, last piece of LinkedList)
        pre->next = reverseBefore1(head, cur);
//        go to the next LinkedList
        pre = head;
        head = cur;
    }
}
// Rule: Treat the LinkedList as a whole, group the LinkedList nodes.
ListNode *LinkedList::reverseKGroup2(ListNode *head, int k) {
    ListNode *groupHead = head, *cur = head;
    while (true) {
        for (int i = 0; i < k; ++i) {
            if (!cur) return head;
            cur = cur->next;
        }
        head = reverseFromTo1(head, groupHead, cur);
        groupHead = cur;
    }
}
// Recursive
ListNode *LinkedList::reverseKGroup3(ListNode *head, int k) {
    ListNode *cur = head;
    for (int i = 0; i < k; ++i) {
        if (!cur) return head;
        cur = cur->next;
    }

    ListNode *newHead = reverseBefore1(head, cur);
    head->next = reverseKGroup3(cur, k);
    return newHead;
}

}  // namespace dsa::lib::lists::linkedlists