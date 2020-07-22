#include "nodes.h"

// reverse the nodes before a certain node
ListNode *reverseBefore(ListNode *head, ListNode *node) {
    ListNode *pre = node, *cur = head, *next;
    while (cur != node) {
        next = cur->next;
        cur->next = pre;
        pre = cur; cur = next;
    }
    return pre;
};

// Reverse the node from node1 to node2 (node2 not included in reversed group)
ListNode *reverseFromTo(ListNode *head, ListNode *from, ListNode *to) {
    // ToDo
};