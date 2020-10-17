#ifndef LIB_LISTS_LINKEDLISTS_LS_H
#define LIB_LISTS_LINKEDLISTS_LS_H

#include <tuple>
#include <dsa/lib/lists/list.h>
#include <dsa/nodes/nodes.h>

namespace dsa::lib::lists::linkedlists {

class LinkedList : public List {
 public:
    ListNode *head;

    explicit LinkedList(ListNode *head);
    static void destroy(ListNode *head);

    length_t length() final;
    [[nodiscard]] virtual arrayStruct toArray() final;
    [[nodiscard]] ListNode *getNodeByIndex(int idx) const;
    [[nodiscard]] ListNode *getNodeByValue(int val) const;
//    Destroy the LinkedList when it is a cycle. nums: how many nodes in the LinkedList
    static void destroyCyclic(ListNode *head, int nums);
};

}  // namespace dsa::lib::lists::linkedlists

#endif