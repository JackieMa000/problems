#include "dsa/testing/testing.h"

#ifndef LIB_LISTS_ARRAYS_ARRAY_TEST_H
#define LIB_LISTS_ARRAYS_ARRAY_TEST_H

namespace dsa::lib::lists::arrays {
namespace {

class ArrayTest : public testing::DSATest {
};

class ToSinglyLinkedListTest : public ArrayTest {
 protected:
    static nodes::ListNode *
    createSinglyLinkedList(int ary[], int length);

    static void
    destroySinglyLinkedList(nodes::ListNode *head);

    static void
    run(int ary[], int length);
};

}  // namespace
}  // namespace dsa::lib::lists::arrays

#endif