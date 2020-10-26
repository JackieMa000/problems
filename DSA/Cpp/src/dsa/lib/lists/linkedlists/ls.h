#ifndef LIB_LISTS_LINKEDLISTS_LS_H
#define LIB_LISTS_LINKEDLISTS_LS_H

#include "base.h"

namespace dsa::lib::lists::linkedlists {

class LinkedList : public Base {
 public:
    explicit LinkedList(ListNode *head);

    ListNode *reverseBefore(ListNode *node) const;

    // LeetCode206
    [[nodiscard]] ListNode *reverse() const;
    ListNode *reverseFromTo(ListNode *fnode, ListNode *tnode) const;

    // LeetCode141
    [[nodiscard]] bool hasCycle() const;

//    LeetCode142
    [[nodiscard]] ListNode *detectCycle() const;

//    LeetCode24
    ListNode *swapPairs();

 private:
    static ListNode *reverseBefore1(ListNode *head, ListNode *node);

    static bool hasCycle1(ListNode *head);

    static ListNode *detectCycle1(ListNode *head);
    static ListNode *detectCycle11(ListNode *head);

    static ListNode *swapPairs1(ListNode *head);
    static ListNode *swapPairs2(ListNode *head);
    static ListNode *swapPairs3(ListNode *head);
    static ListNode *swapPairsRecur(ListNode *prev);

};

}  // namespace dsa::lib::lists::linkedlists

#endif