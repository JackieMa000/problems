#ifndef LIB_LISTS_LINKEDLISTS_LS_H
#define LIB_LISTS_LINKEDLISTS_LS_H

#include <dsa/lib/lists/list.h>
#include <dsa/nodes/nodes.h>

namespace dsa::lib::lists::linkedlists {

class LinkedList : public List {
 public:
    ListNode *head;

    explicit LinkedList(ListNode *head);

    static void destroy(ListNode *head);
//    Destroy the a cyclic LinkedList. length: the length of the LinkedList
    static void destroyCycle(ListNode *head, length_t length);

    length_t length() final;
    [[nodiscard]] virtual arrayStruct toArray() final;

    [[nodiscard]] ListNode *getNodeByIndex(int idx) const;
    [[nodiscard]] ListNode *getNodeByValue(int val) const;

    ListNode *reverseBefore(ListNode *node) const;
    [[nodiscard]] ListNode *reverse() const;
    ListNode *reverseFromTo(ListNode *fnode, ListNode *tnode) const;

    [[nodiscard]] bool hasCycle() const;

 private:
    static bool hasCycle1(ListNode *head);
};

}  // namespace dsa::lib::lists::linkedlists

#endif