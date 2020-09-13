#include "dsa/nodes.h"

namespace dsa
{
    namespace nodes
    {
        Node::Node() : val(0) {}
        Node::Node(int val) : val(val) {}

        ListNode::ListNode() : Node(0), next(nullptr) {}
        ListNode::ListNode(int val) : Node(val), next(nullptr) {}
        ListNode::ListNode(int val, ListNode *next) : Node(val), next(nullptr) {}

        TreeNode::TreeNode() : Node() {}
        TreeNode::TreeNode(int val) : Node(val) {}

        BinaryTreeNode::BinaryTreeNode() : TreeNode() {}
        BinaryTreeNode::BinaryTreeNode(int val) : TreeNode(val) {}
        BinaryTreeNode::BinaryTreeNode(int val, BinaryTreeNode *left, BinaryTreeNode *right)
        {
            this->val = val;
            this->left = left;
            this->right = right;
        }

    }; // namespace nodes
} // namespace dsa