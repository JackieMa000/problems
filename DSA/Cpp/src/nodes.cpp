#include "nodes.h"

namespace dsa
{
    namespace nodes
    {
        Node::Node(int val) { this->val = val; }

        ListNode::ListNode(int val) : Node(val) {}
        ListNode::ListNode(int val, ListNode *next)
        {
            this->val = val;
            this->next = next;
        }

        TreeNode::TreeNode(int val) : Node(val) {}

        BinaryTreeNode::BinaryTreeNode(int val) : TreeNode(val) {}
        BinaryTreeNode::BinaryTreeNode(int val, BinaryTreeNode *left, BinaryTreeNode *right)
        {
            this->val = val;
            this->left = left;
            this->right = right;
        }

    }; // namespace nodes
} // namespace dsa