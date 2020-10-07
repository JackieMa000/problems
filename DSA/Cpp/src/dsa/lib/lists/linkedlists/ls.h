#ifndef LIB_LISTS_LINKEDLISTS_LS_H
#define LIB_LISTS_LINKEDLISTS_LS_H

#include <tuple>
#include <dsa/lib/lists/list.h>
#include <dsa/nodes.h>

namespace dsa::lib::lists::linkedlists {

class LinkedList : public List {
 public:
    ListNode *head;

    explicit LinkedList(ListNode *head);
    static void destroy(ListNode *head);

    length_t length() final;
    [[nodiscard]] virtual std::tuple<length_t, int *> toArray() final;
    [[nodiscard]] ListNode *getNodeByIndex(int idx) const;
    [[nodiscard]] ListNode *getNodeByValue(int val) const;
};

}  // namespace dsa::lib::lists::linkedlists

#endif