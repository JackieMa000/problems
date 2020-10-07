#include "nodes.h"

namespace dsa::nodes {

Node::Node() : val(0) {
}

Node::Node(int val) : val(val) {
}

ListNode::ListNode() : Node(0), next(nullptr) {
}

ListNode::ListNode(int val) : Node(val), next(nullptr) {
}

ListNode::ListNode(int val, ListNode *next) : Node(val), next(next) {
}

TreeNode::TreeNode() : Node() {
}

TreeNode::TreeNode(int val) : Node(val) {
}

BinaryTreeNode::BinaryTreeNode() : TreeNode(), left(nullptr), right(nullptr) {
}

BinaryTreeNode::BinaryTreeNode(int val) : TreeNode(val), left(nullptr), right(nullptr) {
}

BinaryTreeNode::BinaryTreeNode(int val, BinaryTreeNode *left, BinaryTreeNode *right)
    : TreeNode(val), left(left), right(right) {
}

}  // namespace dsa