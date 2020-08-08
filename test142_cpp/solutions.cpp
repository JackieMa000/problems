#include "includes.h"
#include "nodes.h"

class Solution1 {
    // Fast and Slow pinters
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        // Determine whethere there's a cycle
        while (true) {
            if (not fast || not fast->next) return NULL; // No cycle
            slow = slow->next; fast = fast->next->next;
            if (slow == fast) break;
        }

        // Get the entry node of cycle
        ListNode *start = head;
        while (start != slow) {
            start = start->next; slow = slow->next;
        }
        return start;
    }
};

class Solution2 {
    // 2 pointers
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head, *start = head;
        while (fast && fast->next) {
            slow = slow->next; fast = fast->next->next;
            if (slow == fast) { // There is a cycle
                while (slow != start) { 
                    slow = slow->next; start = start->next;
                }
                return start;
            }
        }
        return NULL; // There is no cycle
    }
};