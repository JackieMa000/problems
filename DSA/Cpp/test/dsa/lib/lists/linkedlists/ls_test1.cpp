#include "ls_test.h"

namespace dsa::lib::lists::linkedlists {
namespace {

class HasCycleTest : public LinkedListTest {
 protected:
    static bool hasCycle(ListNode *head) {
        LinkedList ls(head);
        return ls.hasCycle();
    }
};
TEST_F(HasCycleTest, case1) {
    int ary[] = {1};
    ListNode *head = arrayToSinglyLinkedlist(ary, aryLength(ary));
    bool actual = hasCycle(head);
    EXPECT_FALSE(actual);
    LinkedList::destroy(head);
}
TEST_F(HasCycleTest, case2) {
    int ary[] = {1, 2};
    ListNode *head = arrayToCyclicSinglyLinkedlist(ary, aryLength(ary), 0);
    bool actual = hasCycle(head);
    EXPECT_TRUE(actual);
    LinkedList::destroyCycle(head, aryLength(ary));
}
TEST_F(HasCycleTest, case3) {
    int ary[] = {3, 2, 0, 4};
    ListNode *head = arrayToCyclicSinglyLinkedlist(ary, aryLength(ary), 1);
    bool actual = hasCycle(head);
    EXPECT_TRUE(actual);
    LinkedList::destroyCycle(head, aryLength(ary));
}

class DetectCycleTest : public LinkedListTest {
 protected:
    static ListNode *detectCycle(ListNode *head) {
        LinkedList ls(head);
        return ls.detectCycle();
    }
};
TEST_F(DetectCycleTest, case1) {
    int ary[] = {1};
    ListNode *head = arrayToSinglyLinkedlist(ary, aryLength(ary));

    ListNode *actual = detectCycle(head);

    EXPECT_EQ(nullptr, actual);
    LinkedList::destroy(head);
}
TEST_F(DetectCycleTest, case2) {
    int ary[] = {1, 2};
    ListNode *head = arrayToCyclicSinglyLinkedlist(ary, aryLength(ary), 0);
    ListNode *expected = getLinkedListNodeByIndex(head, 0);

    ListNode *actual = detectCycle(head);

    EXPECT_EQ(expected, actual);
    LinkedList::destroyCycle(head, aryLength(ary));
}
TEST_F(DetectCycleTest, case3) {
    int ary[] = {3, 2, 0, -4};
    ListNode *head = arrayToCyclicSinglyLinkedlist(ary, aryLength(ary), 1);
    ListNode *expected = getLinkedListNodeByIndex(head, 1);

    ListNode *actual = detectCycle(head);

    EXPECT_EQ(expected, actual);
    LinkedList::destroyCycle(head, aryLength(ary));
}

class SwapPairsTest : public LinkedListTest {
 protected:
    static ListNode *swapPairs(ListNode *head) {
        LinkedList ls(head);
        return ls.swapPairs();
    }
};
TEST_F(SwapPairsTest, emptyList) {
    int ary[] = {};
    int expected[] = {};
    ListNode *actual = swapPairs(arrayToSinglyLinkedlist(ary, aryLength(ary)));
    EXPECT_ARRAY_EQ_LINKEDLIST(expected, aryLength(expected), actual);
    LinkedList::destroy(actual);
}
TEST_F(SwapPairsTest, oneNode) {
    int ary[] = {1};
    int expected[] = {1};
    ListNode *actual = swapPairs(arrayToSinglyLinkedlist(ary, aryLength(ary)));
    EXPECT_ARRAY_EQ_LINKEDLIST(expected, aryLength(expected), actual);
    LinkedList::destroy(actual);
}
TEST_F(SwapPairsTest, case1) {
    int ary[] = {1, 2, 3, 4};
    int expected[] = {2, 1, 4, 3};
    ListNode *actual = swapPairs(arrayToSinglyLinkedlist(ary, aryLength(ary)));
    EXPECT_ARRAY_EQ_LINKEDLIST(expected, aryLength(expected), actual);
    LinkedList::destroy(actual);
}

class ReverseKGroupTest : public LinkedListTest {
 protected:
    static ListNode *reverseKGroup(ListNode *head, int k) {
        LinkedList ls(head);
        return ls.reverseKGroup(k);
    }
};
TEST_F(ReverseKGroupTest, case1) {
    int ary[] = {1};
    int expected[] = {1};
    ListNode *actual = reverseKGroup(arrayToSinglyLinkedlist(ary, aryLength(ary)), 1);
    EXPECT_ARRAY_EQ_LINKEDLIST(expected, aryLength(expected), actual);
    LinkedList::destroy(actual);
}
TEST_F(ReverseKGroupTest, case2) {
    int ary[] = {1, 2, 3, 4, 5};
    int expected[] = {1, 2, 3, 4, 5};
    ListNode *actual = reverseKGroup(arrayToSinglyLinkedlist(ary, aryLength(ary)), 1);
    EXPECT_ARRAY_EQ_LINKEDLIST(expected, aryLength(expected), actual);
    LinkedList::destroy(actual);
}
TEST_F(ReverseKGroupTest, case3) {
    int ary[] = {1, 2, 3, 4, 5};
    int expected[] = {2, 1, 4, 3, 5};
    ListNode *actual = reverseKGroup(arrayToSinglyLinkedlist(ary, aryLength(ary)), 2);
    EXPECT_ARRAY_EQ_LINKEDLIST(expected, aryLength(expected), actual);
    LinkedList::destroy(actual);
}
TEST_F(ReverseKGroupTest, case4) {
    int ary[] = {1, 2, 3, 4, 5};
    int expected[] = {3, 2, 1, 4, 5};
    ListNode *actual = reverseKGroup(arrayToSinglyLinkedlist(ary, aryLength(ary)), 3);
    EXPECT_ARRAY_EQ_LINKEDLIST(expected, aryLength(expected), actual);
    LinkedList::destroy(actual);
}

}
}