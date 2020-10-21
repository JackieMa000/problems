#include "ls.h"

// reverse the nodes before a certain node
dsa::lib::ListNode *dsa::lib::lists::linkedlists::LinkedList::reverseBefore(ListNode *node) const {
    ListNode *pre, *cur, *next;
    pre = node;
    cur = this->head;

    while (cur != node) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}
dsa::lib::ListNode *dsa::lib::lists::linkedlists::LinkedList::reverse() const {
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
dsa::lib::ListNode *dsa::lib::lists::linkedlists::LinkedList::reverseFromTo(ListNode *fnode, ListNode *tnode) const {
    ListNode *cur = this->head;
    ListNode dummy;
    dummy.next = cur;
    ListNode *groupPre = &dummy;

    while (cur != fnode) {
        groupPre = cur;
        cur = cur->next;
    }

    LinkedList ls(fnode);
    groupPre->next = ls.reverseBefore(tnode);

    return dummy.next;
}
namespace dsa::lib::lists::linkedlists {

LinkedList::LinkedList(ListNode *head) : head(head) {
}

void LinkedList::destroy(ListNode *head) {
    ListNode *cur, *next;
    cur = head;
    while (cur) {
        next = cur->next;
        delete cur;
        cur = next;
    }
}
void LinkedList::destroyCycle(ListNode *head, length_t length) {
    ListNode *cur, *next;
    cur = head;
    for (int i = 0; cur && i < length; ++i) {
        next = cur->next;
        delete cur;
        cur = next;
    }
}

length_t LinkedList::length() {
    ListNode *cur = this->head;
    length_t n;
    for (n = 0; cur; n++) { cur = cur->next; }
    return n;
}

arrayStruct LinkedList::toArray() {
    arrayStruct as{0, nullptr};
    if (this->head) {
        int *ary = new int[this->length()];
        ListNode *cur = this->head;
        for (int i = 0; cur; i++, cur = cur->next) { *(ary + i) = cur->val; }
        as = {this->length(), ary};
    }
    return as;
}

ListNode *LinkedList::getNodeByIndex(int idx) const {
    ListNode *cur = this->head;
    for (int i = 0; i < idx && cur; ++i) { cur = cur->next; }
    return cur;
}
ListNode *LinkedList::getNodeByValue(int val) const {
    ListNode *cur = this->head;
    while (cur && cur->val != val) { cur = cur->next; }
    return cur;
}

// LeetCode141
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

}  // namespace dsa::lib::lists::linkedlists
