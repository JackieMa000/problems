#include "array.h"

namespace dsa::lib::arrays {

Array::Array(int *ary, length_t length) : ary(ary), length(length) {}

ListNode *Array::toSinglyLinkedList() const {
    nodes::ListNode dummy;
    auto *head = new nodes::ListNode(*this->ary);
    dummy.next = head;

    for (int i = 1; i < this->length; i++) {
        head->next = new nodes::ListNode(*(this->ary + i));
        head = head->next;
    }

    return dummy.next;
}

BinaryTreeNode *Array::toBinaryTree() const {
    if (!*this->ary) return nullptr;
    auto *root = new nodes::BinaryTreeNode(*this->ary);
    generateTreeFromArray(this->ary, this->length, root, 0);
    return root;
}
void Array::generateTreeFromArray(int *ary, length_t length, BinaryTreeNode *root, pos_t i) {
    pos_t lpos = 2 * i + 1, rpos = 2 * i + 2;
    if (lpos < length && *(ary + lpos)) {
        root->left = new nodes::BinaryTreeNode(*(ary + lpos));
        generateTreeFromArray(ary, length, root->left, lpos);
    }
    if (rpos < length && *(ary + rpos)) {
        root->right = new nodes::BinaryTreeNode(*(ary + rpos));
        generateTreeFromArray(ary, length, root->right, rpos);
    }
}

}  // namespace dsa::lib::arrays