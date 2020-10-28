#ifndef LIB_LISTS_LINKEDLISTS_LS_H
#define LIB_LISTS_LINKEDLISTS_LS_H

#include "base.h"

namespace dsa::lib::lists::linkedlists {

class LinkedList : public Base {
 public:
    explicit LinkedList(ListNode *head);

    // LeetCode206
    [[nodiscard]] ListNode *reverse() const;
    ListNode *reverseFromTo(ListNode *fnode, ListNode *tnode) const;
    ListNode *reverseBefore(ListNode *node) const;

//    LeetCode25
    ListNode *reverseKGroup(int k);

    // LeetCode141
    [[nodiscard]] bool hasCycle() const;

//    LeetCode142
    [[nodiscard]] ListNode *detectCycle() const;

//    LeetCode24
    ListNode *swapPairs();

 protected:
    static ListNode *reverseBefore1(ListNode *head, ListNode *node);
    static ListNode *reverseFromTo1(ListNode *head, ListNode *fnode, ListNode *tnode);

 private:
    static bool hasCycle1(ListNode *head);

    static ListNode *reverseKGroup1(ListNode *head, int k);
    static ListNode *reverseKGroup2(ListNode *head, int k);
    static ListNode *reverseKGroup3(ListNode *head, int k);

    static ListNode *detectCycle1(ListNode *head);
    static ListNode *detectCycle11(ListNode *head);

    static ListNode *swapPairs1(ListNode *head);
    static ListNode *swapPairs2(ListNode *head);
    static ListNode *swapPairs3(ListNode *head);
    static ListNode *swapPairsRecur(ListNode *prev);
};

}  // namespace dsa::lib::lists::linkedlists

#endif