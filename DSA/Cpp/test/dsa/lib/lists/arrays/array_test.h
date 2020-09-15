#include "dsa/testing/testing.h"

#ifndef LIB_LISTS_ARRAYS_ARRAY_TEST_H
#define LIB_LISTS_ARRAYS_ARRAY_TEST_H

namespace dsa::lib::lists::arrays {
namespace {

class ArrayTest : public testing::DSATest {
 protected:
    static nodes::ListNode *
    createSinglyLinkedList(int *ary, unsigned int length);

    static void
    destroyLinkedList(nodes::ListNode *head);
};

class ToSinglyLinkedListTest : public ArrayTest {
 protected:
    static void
    run(int ary[], int length);
};

}  // namespace
}  // namespace dsa::lib::lists::arrays

#endif