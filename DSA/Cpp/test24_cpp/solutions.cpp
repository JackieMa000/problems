#include "src/cpp/includes.h"
#include <nodes.h>

class Solution1 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyNode = new ListNode(); dummyNode->next = head;

        ListNode *prev = dummyNode;
        while (prev->next && prev->next->next) {
            ListNode *p = prev->next, *q = p->next;
            prev->next = q; p->next = q->next; q->next = p;

            prev = prev->next->next;
        }

        return dummyNode->next;
    }
};


class Solution2 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyNode = new ListNode(); dummyNode->next = head;
        return recursion(dummyNode);
    }

private:
    ListNode* recursion(ListNode* prev) {
        if (prev->next && prev->next->next) {
            ListNode *p = prev->next, *q = p->next;
            prev->next = q; p->next = recursion(q); q->next = p;
        }
        return prev->next;
    }
};

class Solution3 {
    // Recursion
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *newHead = head->next->next;
        ListNode *p = head, *q = p->next;
        head = q; p->next = swapPairs(newHead); q->next = p;
        return head;
    }
};

class Solution4 {
    // Recursion
public:
    ListNode* swapPairs(ListNode* head) {
        if (head && head->next) {
            ListNode *newHead = head->next->next;
            ListNode *p = head, *q = p->next;
            head = q; p->next = swapPairs(newHead); q->next = p;
        } 
        return head;
    }
};