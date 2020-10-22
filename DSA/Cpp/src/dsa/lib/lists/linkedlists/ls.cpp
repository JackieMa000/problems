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
    ListNode *cur = this->head;
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
// Fast and Slow pinters
ListNode *LinkedList::detectCycle1(ListNode *head) {
    ListNode *slow = head, *fast = head;

    // Determine whethere there's a cycle
    while (true) {
        if (not fast || not fast->next) return nullptr; // No cycle
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    // Get the entry node of cycle
    ListNode *start = head;
    while (start != slow) {
        start = start->next;
        slow = slow->next;
    }
    return start;
}
// 2 pointers
ListNode *LinkedList::detectCycle2(ListNode *head) {
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

}  // namespace dsa::lib::lists::linkedlists