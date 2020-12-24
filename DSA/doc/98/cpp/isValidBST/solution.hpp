#include <dsa/nodes/nodes.h>
#include <stack>

typedef dsa::lib::BinaryTreeNode TreeNode;

//inorder traversal.
//recursion
//inorder Rule: left(all nodes) < root < right(all nodes), or prev < cur.
class Solution1 {
 private:
//   prev: global scope for all the recursion subroutines
    TreeNode *prev = nullptr;

 public:
    bool isValidBST(TreeNode *root) {
        // Terminator
        if (!root) { return true; }

        // Left subTree. Recursive case
        if (!isValidBST(root->left)) { return false; }

        // Root. Process or Logic, Action.
        if (prev && prev->val >= root->val)return false;

        // Right subTree. Recursive case
        prev = root;
        return isValidBST(root->right);
    }
};

class Solution2 {
 public:
    bool isValidBST(TreeNode *root) {
        TreeNode *prev = nullptr;
        return isValid(root, prev);
    }

//    TreeNode *&prev, lvalue TreeNode pointer, does not copy.
//prev is global scope for all the recursive function
    bool isValid(TreeNode *root, TreeNode *&prev) {
        // Terminator
        if (!root) { return true; }

        // Left subTree. Recursive case
        if (!isValid(root->left, prev)) { return false; }

        // Root. Process or Logic, Action.
        if (prev && prev->val >= root->val) { return false; }

        // Right Tree. Recursive case
//        update the global(for all the recursion subroutines) lvalue prev
        prev = root;
        return isValid(root->right, prev);
    }
};

/**
 * Rule: prev < cur, using stack
 * self-implemented recursive stack
 * produce to the stack.
 * produce on the left subTree.
 * consume the stack.
 * do the logic. prev < cur.
 * produce on the right subTree.
 */
class Solution3 {
 public:
    bool isValidBST(TreeNode *root) {
        std::stack<TreeNode *> stack;
        TreeNode *prev = nullptr;

        while (root || !stack.empty()) {
//            recursion equivalent: go
//            produce on the left subTree;
            while (root) {
                stack.push(root);
                root = root->left;
            }

//            consume;
            root = stack.top();
            stack.pop();
//            recursion equivalent: back
//            process, logic
            if (prev && prev->val >= root->val) { return false; }

//           recursion equivalent: recursive case, drill down
//            produce on the right
            prev = root;
            root = root->right;
        }

        return true;
    }
};
