package converter;

import nodes.ListNode;
import nodes.TreeNode;
import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;

public class ConverterTest {

    private Converter converter;

    @Before
    public void setUp() {
        converter = new Converter();
    }

    @Test
    public void convertArrayToTree() {
        TreeNode actual = converter.convertArrayToTree(new int[]{3, 1, 5, 0, 2});
        assertTreeEqualsArray(actual, new int[]{3, 1, 5, 0, 2}, 0);
    }

    @Test
    public void convertArrayToTree1() {
        TreeNode actual = converter.convertArrayToTree(new int[]{5, 1, 4, 0, 6, 3, 6});
        assertTreeEqualsArray(actual, new int[]{5, 1, 4, 0, 6, 3, 6}, 0);
    }

    private void assertTreeEqualsArray(TreeNode root, int[] array, int i) {
        if (i >= array.length) return;
        if (root == null) {
            assertEquals(0, array[i]);
            return;
        }
        assertEquals(root.val, array[i]);
        assertTreeEqualsArray(root.left, array, 2 * i + 1);
        assertTreeEqualsArray(root.right, array, 2 * i + 2);
    }

    @Test
    public void convertTreeToArray() {
        assertArrayEquals(new int[]{3, 1, 5, 0, 2}, converter.convertTreeToArray(generateTestTree()));
    }

    @Test
    public void convertTreeToArray1() {
        TreeNode root = converter.convertArrayToTree(new int[]{5, 1, 4, 0, 6, 3, 6});
        assertArrayEquals(new int[]{5, 1, 4, 0, 6, 3, 6}, converter.convertTreeToArray(root));
    }

    @Test
    public void convertTreeToArray2() {
        TreeNode root = converter.convertArrayToTree(new int[]{5, 1, 4, 0, 0, 3, 6});
        assertArrayEquals(new int[]{5, 1, 4, 0, 0, 3, 6}, converter.convertTreeToArray(root));
    }

    @Test
    public void getArraySizeForTree() {
        assertEquals(7, converter.getArraySizeForTree(generateTestTree()));
    }

    @Test
    public void getTreeDepth() {
        assertEquals(3, converter.getTreeDepth(generateTestTree()));
    }

    private TreeNode generateTestTree() {
        return converter.convertArrayToTree(new int[]{3, 1, 5, 0, 2});
    }

    @Test
    public void convertArrayToLinkedList() {
        int[] array = {1, 2, 3, 4};
        assertLinkedListEqualsArray(converter.convertArrayToLinkedList(array), array);
    }

    private void assertLinkedListEqualsArray(ListNode root, int[] array) {
        for (int value : array) {
            assertEquals(value, root.val);
            root = root.next;
        }
        assertNull(root);
    }

    @Test
    public void convertLinkedListToArray() {
        int[] expected = {1, 2, 3, 4};
        ListNode root = converter.convertArrayToLinkedList(expected);
        assertArrayEquals(expected, converter.convertLinkedListToArray(root));
    }
}
