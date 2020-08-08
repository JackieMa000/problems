#include "lib/lists/linkedlists.h"
#include "nodes.h"

using namespace lib;
using namespace nodes;

class Solution1
{
    // Ierative
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;
        while (true)
        {
            for (int i = 0; i < k; i++)
            {
                if (!cur)
                    return dummy->next;
                cur = cur->next;
            }

            SinglyLinkedList ls(head);
            pre->next = ls.reverseBefore(cur);
            pre = head;
            head = cur;
        }
    }
};

class Solution2
{
    // Recursive
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *cur = head;
        for (int i = 0; i < k; ++i)
        {
            if (!cur)
                return head;
            cur = cur->next;
        }

        SinglyLinkedList ls(head);
        ListNode *newHead = ls.reverseBefore(cur);
        head->next = reverseKGroup(cur, k);
        return newHead;
    }
};