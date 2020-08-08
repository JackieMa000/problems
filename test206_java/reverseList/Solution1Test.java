package reverseList;

import converter.Converter;
import converter.ListNode;
import org.junit.Test;

import static org.junit.Assert.assertArrayEquals;

public class Solution1Test {

    @Test
    public void reverseList() {
        ListNode head = new Converter().convertArrayToLinkedList(new int[]{1, 2, 3, 4, 5});
        ListNode actual = new Solution1().reverseList(head);
        assertArrayEquals(new int[]{5, 4, 3, 2, 1}, new Converter().convertLinkedListToArray(actual));
    }
}