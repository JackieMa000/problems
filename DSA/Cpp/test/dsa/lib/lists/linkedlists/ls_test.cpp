#include "ls_test.h"

namespace dsa::lib::lists::linkedlists {
namespace {

class ToArrayTest : public LinkedListTest {
 protected:
    static void run(int *ary, length_t length) {
        ListNode *head = generateSinglyLinkedListFromArray(ary, length);
        auto[actLen, actAry] = toArray(head);
        EXPECT_ARRAY_EQ(ary, length, actAry, actLen);

        LinkedList::destroy(head);
        delete[] actAry;
    }

    static std::tuple<length_t, int *> toArray(ListNode *head) {
        LinkedList ls(head);
        return ls.toArray();
    }
};
TEST_F(ToArrayTest, case1) {
    int ary[] = {1};
    run(ary, sizeof(ary) / sizeof(ary[0]));
}
TEST_F(ToArrayTest, case2) {
    int ary[] = {1, 2};
    run(ary, sizeof(ary) / sizeof(ary[0]));
}
TEST_F(ToArrayTest, case3) {
    int ary[] = {1, 2, 3};
    run(ary, sizeof(ary) / sizeof(ary[0]));
}

class LengthTest : public LinkedListTest {
 protected:
    static void run(int *ary, length_t length) {
        ListNode *head = generateSinglyLinkedListFromArray(ary, length);
        length_t actual = getLength(head);
        EXPECT_EQ(length, actual);
        LinkedList::destroy(head);
    }

    static length_t getLength(ListNode *head) {
        LinkedList ls(head);
        return ls.length();
    }
};
TEST_F(LengthTest, case1) {
    int ary[] = {1};
    run(ary, 1);
}
TEST_F(LengthTest, case2) {
    int ary[] = {1, 2, 3};
    run(ary, 3);
}
TEST_F(LengthTest, case3) {
    int ary[] = {1, 2, 3, 4};
    run(ary, 4);
}

class GetNodeByIndexTest : public LinkedListTest {
 protected:
    static void run(int *ary, length_t length, int idx, int expected) {
        ListNode *head = generateSinglyLinkedListFromArray(ary, length);
        ListNode *actual = getNode(idx, head);
        EXPECT_EQ(expected, actual->val);
        LinkedList::destroy(head);
    }
    static ListNode *getNode(int idx, ListNode *head) {
        LinkedList ls(head);
        return ls.getNodeByIndex(idx);
    }
};
TEST_F(GetNodeByIndexTest, case1) {
    int ary[] = {1, 2, 3};
    run(ary, sizeof(ary) / sizeof(ary[0]), 0, 1);
}
TEST_F(GetNodeByIndexTest, case2) {
    int ary[] = {1, 2, 3};
    run(ary, sizeof(ary) / sizeof(ary[0]), 2, 3);
}
TEST_F(GetNodeByIndexTest, case3) {
    int ary[] = {1};
    run(ary, sizeof(ary) / sizeof(ary[0]), 0, 1);
}

}  // namespace
}  // namespace dsa::lib::lists::linkedlists