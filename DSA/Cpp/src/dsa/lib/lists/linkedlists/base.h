#ifndef DSA_SRC_DSA_LIB_LISTS_LINKEDLISTS_LS_CPP_BASE_H_
#define DSA_SRC_DSA_LIB_LISTS_LINKEDLISTS_LS_CPP_BASE_H_

#include <dsa/lib/lists/list.h>

namespace dsa::lib::lists::linkedlists {

class Base : public List {

 public:
    ListNode *head;
    explicit Base(ListNode *head);

    static void destroy(ListNode *head);
//    Destroy the a cyclic LinkedList. length: the length of the LinkedList
    static void destroyCycle(ListNode *head, length_t length);

    length_t length() final;
    [[nodiscard]] virtual array_s toArray() final;

    [[nodiscard]] ListNode *getNodeByIndex(int idx) const;
    [[nodiscard]] ListNode *getNodeByValue(int val) const;

};

}

#endif //DSA_SRC_DSA_LIB_LISTS_LINKEDLISTS_LS_CPP_BASE_H_
