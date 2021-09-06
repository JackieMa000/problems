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

    static array_s toArray(ListNode *head) {
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
    run(ary, arylen(ary));
}
TEST_F(ToArrayTest, case2) {
    int ary[] = {1, 2};
    run(ary, arylen(ary));
}
TEST_F(ToArrayTest, case3) {
    int ary[] = {1, 2, 3};
    run(ary, arylen(ary));
}

class ReverseTest : public LinkedListTest {
 protected:
    static void run(int *ary, length_t length, int *expected, length_t expectedLength) {
        ListNode *actual = reverse(arrayToSinglyLinkedlist(ary, length));
        EXPECT_ARRAY_EQ_LINKEDLIST(expected, expectedLength, actual);
        LinkedList::destroy(actual);
    }
    static ListNode *reverse(ListNode *head) {
        LinkedList ls(head);
        return ls.reverse();
    }
};
TEST_F(ReverseTest, case1) {
    int ary[] = {1}, expected[] = {1};
    run(ary, arylen(ary), expected, arylen(expected));
}
TEST_F(ReverseTest, case2) {
    int ary[] = {1, 2, 3}, expected[] = {3, 2, 1};
    run(ary, arylen(ary), expected, arylen(expected));
}
TEST_F(ReverseTest, nullList) {
    ListNode *actual = reverse(nullptr);
    EXPECT_EQ(nullptr, actual);
}

class ReverseBeforeTest : public LinkedListTest {
 protected:
    static void run(int *ary, length_t length, int *expected, length_t expectedLength, pos_t idx) {
        ListNode *head = arrayToSinglyLinkedlist(ary, length);
        ListNode *actual = reverseBefore(head, idx);
        EXPECT_ARRAY_EQ_LINKEDLIST(expected, expectedLength, actual);
        LinkedList::destroy(actual);
    }
    static ListNode *reverseBefore(ListNode *head, int idx) {
        LinkedList ls(head);
        return ls.reverseBefore(ls.getNodeByIndex(idx));
    }
};
TEST_F(ReverseBeforeTest, case1) {
    int ary[] = {1, 2, 3}, expected[] = {1, 2, 3};
    run(ary, arylen(ary), expected, arylen(expected), 0);
}
TEST_F(ReverseBeforeTest, case2) {
    int ary[] = {1, 2, 3}, expected[] = {2, 1, 3};
    run(ary, arylen(ary), expected, arylen(expected), 2);
}
TEST_F(ReverseBeforeTest, nullList) {
    ListNode *actual = reverseBefore(nullptr, 0);
    EXPECT_EQ(nullptr, actual);
}

class ReverseFromToTest : public LinkedListTest {
 protected:
    static void run(int *ary, length_t length, int *expected, length_t expectedLength, pos_t from, pos_t to) {
        ListNode *head = arrayToSinglyLinkedlist(ary, length);
        ListNode *actual = reverseFromTo(head, from, to);
        EXPECT_ARRAY_EQ_LINKEDLIST(expected, expectedLength, actual);
        LinkedList::destroy(actual);
    }
    static ListNode *reverseFromTo(ListNode *head, pos_t from, pos_t to) {
        LinkedList ls(head);
        return ls.reverseFromTo(ls.getNodeByIndex(from), ls.getNodeByIndex(to));
    }
};
TEST_F(ReverseFromToTest, case1) {
    int ary[] = {1, 2}, expected[] = {1, 2};
    run(ary, arylen(ary), expected, arylen(ary), 0, 0);
}
TEST_F(ReverseFromToTest, case2) {
    int ary[] = {1, 2, 3, 4, 5}, expected[] = {4, 3, 2, 1, 5};
    run(ary, arylen(ary), expected, arylen(ary), 0, 4);
}
TEST_F(ReverseFromToTest, case3) {
    int ary[] = {1, 2, 3, 4, 5}, expected[] = {1, 4, 3, 2, 5};
    run(ary, arylen(ary), expected, arylen(ary), 1, 4);
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
    run(ary, arylen(ary), 0, 1);
}
TEST_F(GetNodeByIndexTest, case2) {
    int ary[] = {1, 2, 3};
    run(ary, arylen(ary), 2, 3);
}
TEST_F(GetNodeByIndexTest, case3) {
    int ary[] = {1};
    run(ary, arylen(ary), 0, 1);
}
TEST_F(GetNodeByIndexTest, indexNotExist) {
    int ary[] = {1};
    ListNode *head = arrayToSinglyLinkedlist(ary, arylen(ary));
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
    run(ary, arylen(ary), 1, 1);
}
TEST_F(GetNodeByValueTest, case2) {
    int ary[] = {1, 2, 3};
    run(ary, arylen(ary), 3, 3);
}
TEST_F(GetNodeByValueTest, valueNotExist) {
    int ary[] = {1};
    ListNode *head = arrayToSinglyLinkedlist(ary, arylen(ary));
    ListNode *actual = getNode(2, head);
    EXPECT_EQ(nullptr, actual);
    LinkedList::destroy(head);
}

}  // namespace
}  // namespace dsa::lib::lists::linkedlists