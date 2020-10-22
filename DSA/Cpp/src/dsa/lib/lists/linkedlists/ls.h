#ifndef LIB_LISTS_LINKEDLISTS_LS_H
#define LIB_LISTS_LINKEDLISTS_LS_H

#include "base.h"

namespace dsa::lib::lists::linkedlists {

class LinkedList : public Base {
 public:
    explicit LinkedList(ListNode *head);

    ListNode *reverseBefore(ListNode *node) const;
    [[nodiscard]] ListNode *reverse() const;
    ListNode *reverseFromTo(ListNode *fnode, ListNode *tnode) const;

    // LeetCode141
    [[nodiscard]] bool hasCycle() const;
    //LeetCode142
    [[nodiscard]] ListNode *detectCycle() const;

 private:
    static ListNode *reverseBefore1(ListNode *head, ListNode *node);

    static bool hasCycle1(ListNode *head);
    static ListNode *detectCycle1(ListNode *head);
    static ListNode *detectCycle2(ListNode *head);
};

}  // namespace dsa::lib::lists::linkedlists

#endif