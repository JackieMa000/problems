#include "sls_test.h"

namespace dsa::lib::lists::linkedlists {
namespace {

class ToArrayTest : public SinglyLinkedListTest {
 protected:
    static void run(int *ary, length_t length) {
        arrays::Array array(ary, length);
        ListNode *head = array.toSinglyLinkedList();

        SinglyLinkedList ls(head);
        auto[actLen, actAry] = ls.toArray();

        EXPECT_ARRAY_EQ(ary, length, actAry, actLen);
        LinkedList::destroy(head);
    }
};

TEST_F(ToArrayTest, case1) {
    int ary[] = {1, 2, 3};
    run(ary, sizeof(ary) / sizeof(ary[0]));
}

}  // namespace
}  // namespace dsa