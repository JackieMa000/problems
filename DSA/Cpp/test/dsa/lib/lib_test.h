#ifndef DSA_TEST_DSA_LIB_LIB_TEST_H_
#define DSA_TEST_DSA_LIB_LIB_TEST_H_

#include <dsa/testing/testing.h>
#include <dsa/lib/arrays/array.h>
#include <dsa/lib/trees/bt.h>
#include <dsa/lib/lists/linkedlists/sls.h>
#include <dsa/config.h>

namespace dsa::lib {

class LibTest : public testing::DSATest {
 public:
    NODISCARD static BinaryTreeNode *arrayToBinaryTree(int *ary, length_t length) {
        arrays::Array array(ary, length);
        return array.toBinaryTree();
    }
    NODISCARD static ListNode *arrayToSinglyLinkedlist(int *ary, length_t length) {
        arrays::Array array(ary, length);
        return array.toSinglyLinkedList();
    }
    static ListNode *arrayToCyclicSinglyLinkedlist(int *ary, length_t length, pos_t pos) {
        arrays::Array array(ary, length);
        return array.toCyclicSinglyLinkedList(pos);
    }
    static ListNode *getLinkedListNodeByIndex(ListNode *head, pos_t idx) {
        lists::linkedlists::SinglyLinkedList ls(head);
        return ls.getNodeByIndex(idx);
    }
    static ListNode *getLinkedListNodeByValue(ListNode *head, int val) {
        lists::linkedlists::SinglyLinkedList ls(head);
        return ls.getNodeByValue(val);
    }
    static BinaryTreeNode *getTreeNodeByIndex(BinaryTreeNode *root, pos_t idx) {
        trees::BinaryTree bt(root);
        return bt.getNodeByIndex(idx);
    }
    static BinaryTreeNode *getTreeNodeByValue(BinaryTreeNode *root, int val) {
        trees::BinaryTree bt(root);
        return bt.getNodeByValue(val);
    }
    static array_s singlyLinkedListToArray(ListNode *head) {
        return lists::linkedlists::LinkedList(head).toArray();
    }
};

}
#endif //DSA_TEST_DSA_LIB_LIB_TEST_H_
