#include <stddef.h>

#include "lib/lists/linkedlists.h"
#include "nodes.h"

using namespace dsa::lib;
using namespace dsa::nodes;

class Solution1
{
public:
    ListNode *reverseList(ListNode *head)
    {
        SinglyLinkedList *ls;
        ls = new SinglyLinkedList(head);
        return ls->reverse();
    }
};

class Solution2
{
    // Recursion
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !(head->next))
            return head;
        ListNode *newHead = reverseList(head->next);
        ListNode *tail = head->next;
        tail->next = head;
        head->next = NULL;
        return newHead;
    }
};

class Solution3
{
public:
    ListNode *reverseList(ListNode *head)
    {
        return recursion(head, NULL);
    }

    ListNode *recursion(ListNode *head, ListNode *prev)
    {
        if (!head)
            return prev;
        ListNode *next = head->next;
        head->next = prev;
        return recursion(next, head);
    }
};