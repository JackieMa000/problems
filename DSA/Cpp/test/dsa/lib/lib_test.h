#ifndef DSA_TEST_DSA_LIB_LIB_TEST_H_
#define DSA_TEST_DSA_LIB_LIB_TEST_H_

#include <dsa/testing/testing.h>
#include <dsa/lib/arrays/array.h>
#include <dsa/lib/lists/linkedlists/ls.h>
#include <dsa/lib/trees/bt.h>
#include <dsa/lib/lists/linkedlists/sls.h>

namespace dsa::lib {

class LibTest : public testing::DSATest {
 protected:
    [[nodiscard]] static BinaryTreeNode *arrayToBinaryTree(int *ary, length_t length) {
        arrays::Array array(ary, length);
        return array.toBinaryTree();
    }
    static ListNode *arrayToSinglyLinkedlist(int *ary, length_t length) {
        arrays::Array array(ary, length);
        return array.toSinglyLinkedList();
    }
    static ListNode *getLinkedListNodeByIndex(ListNode *head, pos_t i) {
        lists::linkedlists::SinglyLinkedList ls(head);
        return ls.getNodeByIndex(i);
    }
};

}
#endif //DSA_TEST_DSA_LIB_LIB_TEST_H_
