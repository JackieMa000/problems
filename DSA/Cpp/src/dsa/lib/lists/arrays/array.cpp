#include "array.h"

namespace dsa::lib::lists::arrays {

Array::Array(int *ary, length_t length) : ary(ary), length(length) {}

nodes::ListNode *Array::toSinglyLinkedList() const {
    auto *dummy = new nodes::ListNode();
    auto *head = new nodes::ListNode(*this->ary);
    dummy->next = head;

    for (int i = 1; i < this->length; i++) {
        head->next = new nodes::ListNode(*(this->ary + i));
        head = head->next;
    }

    return dummy->next;
}

// Copy the array based on the index range, including the end pos.
//int *Array::copy(int *p_ary, unsigned int start, unsigned int end) {
////ToDo: Need to be deleted
//    for (unsigned int i = start; i <= end; i++) *(p_ary + i) = *(this->ary + i);
//    return p_ary;
//}

nodes::BinaryTreeNode *Array::toBinaryTree() const {
    auto *root = new nodes::BinaryTreeNode(*this->ary);
    generateTreeFromArray(this->ary, this->length, root, 0);
    return root;
}
void Array::generateTreeFromArray(int *ary, length_t length, nodes::BinaryTreeNode *root, pos_t i) {
    pos_t lpos = 2 * i + 1, rpos = 2 * i + 2;
    if (lpos < length && *(ary + lpos) != 0) {
        root->left = new nodes::BinaryTreeNode(*(ary + lpos));
        generateTreeFromArray(ary, length, root->left, lpos);
    }
    if (rpos < length && *(ary + rpos) != 0) {
        root->right = new nodes::BinaryTreeNode(*(ary + rpos));
        generateTreeFromArray(ary, length, root->right, rpos);
    }
}

}  // namespace dsa::lib::lists::arrays