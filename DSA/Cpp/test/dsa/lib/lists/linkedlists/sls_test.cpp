#include "sls_test.h"

namespace dsa::lib::lists::linkedlists {
namespace {

class ToArrayTest : public SinglyLinkedListTest {
 protected:
    static void run(int *ary, length_t length) {
        ListNode *head = arrayToSinglyLinkedlist(ary, length);
        arrayStruct actual = toArray(head);
        EXPECT_ARRAY_EQ(ary, length, actual.ary, actual.length);

        LinkedList::destroy(head);
        delete[] actual.ary;
    }
    static arrayStruct toArray(ListNode *head) {
        SinglyLinkedList ls(head);
        return ls.toArray();
    }
};
TEST_F(ToArrayTest, case1) {
    int ary[] = {1, 2, 3};
    run(ary, aryLength(ary));
}

class ReverseTest : public SinglyLinkedListTest {
 protected:
    static void run(int *ary, length_t length, int *expected, length_t expectedLength) {
        ListNode *actual = reverse(arrayToSinglyLinkedlist(ary, length));
        EXPECT_ARRAY_EQ_LINKEDLIST(expected, expectedLength, actual);
        LinkedList::destroy(actual);
    }
    static ListNode *reverse(ListNode *head) {
        SinglyLinkedList ls(head);
        return ls.reverse();
    }
};
TEST_F(ReverseTest, case1) {
    int ary[] = {1}, expected[] = {1};
    run(ary, aryLength(ary), expected, aryLength(expected));
}
TEST_F(ReverseTest, case2) {
    int ary[] = {1, 2, 3}, expected[] = {3, 2, 1};
    run(ary, aryLength(ary), expected, aryLength(expected));
}
TEST_F(ReverseTest, nullList) {
    ListNode *actual = reverse(nullptr);
    EXPECT_EQ(nullptr, actual);
}

class ReverseBeforeTest : public SinglyLinkedListTest {
 protected:
    static void run(int *ary, length_t length, int *expected, length_t expectedLength, pos_t idx) {
        ListNode *head = arrayToSinglyLinkedlist(ary, length);
        ListNode *actual = reverseBefore(head, idx);
        EXPECT_ARRAY_EQ_LINKEDLIST(expected, expectedLength, actual);
        SinglyLinkedList::destroy(actual);
    }
    static ListNode *reverseBefore(ListNode *head, int idx) {
        SinglyLinkedList ls(head);
        return ls.reverseBefore(ls.getNodeByIndex(idx));
    }
};
TEST_F(ReverseBeforeTest, case1) {
    int ary[] = {1, 2, 3}, expected[] = {1, 2, 3};
    run(ary, aryLength(ary), expected, aryLength(expected), 0);
}
TEST_F(ReverseBeforeTest, case2) {
    int ary[] = {1, 2, 3}, expected[] = {2, 1, 3};
    run(ary, aryLength(ary), expected, aryLength(expected), 2);
}
TEST_F(ReverseBeforeTest, nullList) {
    ListNode *actual = reverseBefore(nullptr, 0);
    EXPECT_EQ(nullptr, actual);
}

class ReverseFromToTest : public SinglyLinkedListTest {
 protected:
    static void run(int *ary, length_t length, int *expected, length_t expectedLength, pos_t from, pos_t to) {
        ListNode *head = arrayToSinglyLinkedlist(ary, length);
        ListNode *actual = reverseFromTo(head, from, to);
        EXPECT_ARRAY_EQ_LINKEDLIST(expected, expectedLength, actual);
        SinglyLinkedList::destroy(actual);
    }
    static ListNode *reverseFromTo(ListNode *head, pos_t from, pos_t to) {
        SinglyLinkedList ls(head);
        return ls.reverseFromTo(ls.getNodeByIndex(from), ls.getNodeByIndex(to));
    }
};
TEST_F(ReverseFromToTest, case1) {
    int ary[] = {1, 2}, expected[] = {1, 2};
    run(ary, aryLength(ary), expected, aryLength(ary), 0, 0);
}
TEST_F(ReverseFromToTest, case2) {
    int ary[] = {1, 2, 3, 4, 5}, expected[] = {4, 3, 2, 1, 5};
    run(ary, aryLength(ary), expected, aryLength(ary), 0, 4);
}
TEST_F(ReverseFromToTest, case3) {
    int ary[] = {1, 2, 3, 4, 5}, expected[] = {1, 4, 3, 2, 5};
    run(ary, aryLength(ary), expected, aryLength(ary), 1, 4);
}
}  // namespace
}  // namespace dsa