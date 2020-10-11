#include "ls_test.h"

namespace dsa::lib::lists::linkedlists {
namespace {

class ToArrayTest : public LinkedListTest {
 protected:
    static void run(int *ary, length_t length) {
        ListNode *head = arrayToSinglyLinkedlist(ary, length);
        auto actual = toArray(head);
        EXPECT_ARRAY_EQ(ary, length, actual.ary, actual.length);

        LinkedList::destroy(head);
        delete[] actual.ary;
    }

    static arrayStruct toArray(ListNode *head) {
        LinkedList ls(head);
        return ls.toArray();
    }
};
TEST_F(ToArrayTest, nullList) {
    auto actual = toArray(nullptr);
    EXPECT_EQ(0, actual.length);
    EXPECT_EQ(nullptr, actual.ary);
}
TEST_F(ToArrayTest, case1) {
    int ary[] = {1};
    run(ary, aryLength(ary));
}
TEST_F(ToArrayTest, case2) {
    int ary[] = {1, 2};
    run(ary, aryLength(ary));
}
TEST_F(ToArrayTest, case3) {
    int ary[] = {1, 2, 3};
    run(ary, aryLength(ary));
}

class LengthTest : public LinkedListTest {
 protected:
    static void run(int *ary, length_t length) {
        ListNode *head = arrayToSinglyLinkedlist(ary, length);
        length_t actual = getLength(head);
        EXPECT_EQ(length, actual);
        LinkedList::destroy(head);
    }

 private:
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
        ListNode *head = arrayToSinglyLinkedlist(ary, length);
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
    run(ary, aryLength(ary), 0, 1);
}
TEST_F(GetNodeByIndexTest, case2) {
    int ary[] = {1, 2, 3};
    run(ary, aryLength(ary), 2, 3);
}
TEST_F(GetNodeByIndexTest, case3) {
    int ary[] = {1};
    run(ary, aryLength(ary), 0, 1);
}
TEST_F(GetNodeByIndexTest, indexNotExist) {
    int ary[] = {1};
    ListNode *head = arrayToSinglyLinkedlist(ary, aryLength(ary));
    ListNode *actual = getNode(2, head);
    EXPECT_EQ(nullptr, actual);
    LinkedList::destroy(head);
}

class GetNodeByValueTest : public LinkedListTest {
 protected:
    static void run(int *ary, length_t length, int val, int expected) {
        ListNode *head = arrayToSinglyLinkedlist(ary, length);
        ListNode *actual = getNode(val, head);
        EXPECT_EQ(expected, actual->val);
        LinkedList::destroy(head);
    }
    static ListNode *getNode(int val, ListNode *head) {
        LinkedList ls(head);
        return ls.getNodeByValue(val);
    }

};
TEST_F(GetNodeByValueTest, case1) {
    int ary[] = {1};
    run(ary, aryLength(ary), 1, 1);
}
TEST_F(GetNodeByValueTest, case2) {
    int ary[] = {1, 2, 3};
    run(ary, aryLength(ary), 3, 3);
}
TEST_F(GetNodeByValueTest, valueNotExist) {
    int ary[] = {1};
    ListNode *head = arrayToSinglyLinkedlist(ary, aryLength(ary));
    ListNode *actual = getNode(2, head);
    EXPECT_EQ(nullptr, actual);
    LinkedList::destroy(head);
}

}  // namespace
}  // namespace dsa::lib::lists::linkedlists