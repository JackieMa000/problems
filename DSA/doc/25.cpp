#include "includes.h"
#include "nodes.h"

using namespace std;

// There's no need for the dummy head if a 'pointer to the pointer' is used. 
// Plus we can avoid checking the remaining length (which effectively causes the list
//  to be traversed twice instead of once) by simply reversing the last segment back
//   when the end is reached:

class Solution3
{

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k > 1)
            for (auto pp = &head; *pp;)
                pp = reverse(pp, k);
        return head;
    }

private:
/**
    ListNode *head, *new, *next
    next = new->next;

    new->next = head; // reverse

//    go to next, iterate
    head = new;
    new = next;

    return new;
*/
    ListNode **reverse(ListNode **pphead, int k)
    {
        auto ppnew = &((*pphead)->next);
        for (int kr = 1; kr < k; kr++)
        {
            if (!*ppnew)
                return reverse(pphead, kr);
            auto pnext = (*ppnew)->next;

//            reverse
            (*ppnew)->next = *pphead;

//            go to next
            *pphead = *ppnew;
            *ppnew = pnext;
        }
        return ppnew;
    }
};