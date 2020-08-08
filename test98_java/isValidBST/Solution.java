package isValidBST;


//Recursion
class Solution {
    public boolean isValidBST(TreeNode root) {
        return isValid(root, null, null);
    }

    public boolean isValid(TreeNode root, Integer lowerLimit, Integer upperLimit) {
        if (root == null) return true;
        if (lowerLimit != null && root.val <= lowerLimit) return false;
        if (upperLimit != null && root.val >= upperLimit) return false;
        return isValid(root.left, lowerLimit, root.val) && isValid(root.right, root.val, upperLimit);
    }
}
