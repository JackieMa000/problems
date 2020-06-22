package converter;

import java.util.Arrays;

import static java.lang.Math.max;
import static java.lang.Math.pow;

public class Converter {
    public TreeNode convertArrayToTree(int[] array) {
        TreeNode root = new TreeNode(array[0]);
        generateTreeFromArray(array, root, 0);
        return root;
    }

    private void generateTreeFromArray(int[] array, TreeNode root, int i) {
        int n = array.length;
        int lpos = 2 * i + 1, rpos = 2 * i + 2;
        if (lpos < n && array[lpos] != 0) {
            root.left = new TreeNode(array[lpos]);
            generateTreeFromArray(array, root.left, lpos);
        }
        if (rpos < n && array[rpos] != 0) {
            root.right = new TreeNode(array[rpos]);
            generateTreeFromArray(array, root.right, rpos);
        }
    }

    public int[] convertTreeToArray(TreeNode root) {
        int arraySize = getArraySizeForTree(root);
        int[] array = new int[arraySize];
        generateArrayFromTree(root, 0, array);
        return arrayStripTrailing(array);
    }

    private int[] arrayStripTrailing(int[] array) {
        int n = array.length;
        if (array[n - 1] != 0) return array;
        int end = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (array[i] == 0 && array[i - 1] != 0) {
                end = i;
                break;
            }
        }
        return Arrays.copyOf(array, end);
    }

    private void generateArrayFromTree(TreeNode root, int i, int[] array) {
        if (root == null || i >= array.length) return;
        array[i] = root.val;
        generateArrayFromTree(root.left, 2 * i + 1, array);
        generateArrayFromTree(root.right, 2 * i + 2, array);
    }

    protected int getArraySizeForTree(TreeNode root) {
        // Could use my own pow algorithm.
        return (int) (pow(2, getTreeDepth(root)) - 1);
    }

    protected int getTreeDepth(TreeNode root) {
        return (root == null) ? 0 : 1 + max(getTreeDepth(root.left), getTreeDepth(root.right));
    }
}
