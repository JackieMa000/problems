#include<stddef.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        while (head) {
            ListNode* tmp = head -> next; head -> next = prev;
            prev = head; head = tmp;
        }
        return prev;
    }
};

class Solution2 {
    // Recursion
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !(head -> next)) return head;
        ListNode* newHead = reverseList(head -> next);
        ListNode* tail = head -> next;
        tail -> next = head; head -> next = NULL;
        return newHead;
    }
};

class Solution3 {
public:
    ListNode* reverseList(ListNode* head) {
        return recursion(head, NULL);
    }

    ListNode* recursion(ListNode* head, ListNode* prev) {
        if (!head) return prev;
        ListNode* next = head -> next; head -> next = prev;
        return recursion(next, head);
    }
};