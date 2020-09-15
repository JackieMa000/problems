#ifndef LIB_LISTS_LINKEDLISTS_LS_TEST_H
#define LIB_LISTS_LINKEDLISTS_LS_TEST_H

#include <dsa/testing/testing.h>

namespace dsa::lib::lists::linkedlists {
namespace {

 class LinkedListTest : public testing::DSATest {
 protected:
    static nodes::ListNode *
    createSinglyLinkedList(int *ary, unsigned int length);

    static void
    destroyLinkedList(nodes::ListNode *head);
};

class ToArrayTest : public LinkedListTest {
};

}  // namespace
}  // namespace dsa::lib::lists::linkedlists

#endif