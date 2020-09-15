#include "array_test.h"
#include "dsa/lib/lists/arrays/array.h"
#include "dsa/lib/lists/linkedlists/sls.h"


namespace dsa::lib::lists::arrays {
namespace {

nodes::ListNode *
ArrayTest::createSinglyLinkedList(int *ary, unsigned int length) {
    Array array(ary, length);
    return array.toSinglyLinkedList();
}

void
ArrayTest::destroyLinkedList(nodes::ListNode *head) {
    linkedlists::LinkedList ls(head);
    ls.destroy();
}

void
ToSinglyLinkedListTest::run(int ary[], int length) {
    nodes::ListNode *actual = createSinglyLinkedList(ary, length);
    EXPECT_ARRAY_EQ_LINKEDLIST(ary, length, actual);
    destroyLinkedList(actual);
}

TEST_F(ArrayTest, case_array_eq) {
    int expected[] = {1, 2, 3}, actual[] = {1, 2, 3};
    EXPECT_ARRAY_EQ(expected, sizeof(expected) / 4, actual, sizeof(actual) / 4);
}

TEST_F(ToSinglyLinkedListTest, case1) {
    int ary[] = {1};
    run(ary, sizeof(ary) / 4);
}

TEST_F(ToSinglyLinkedListTest, case2) {
    int ary[] = {1, 2, 3};
    run(ary, sizeof(ary) / 4);
}

}  // namespace
}  // namespace dsa::lib::lists::arrays