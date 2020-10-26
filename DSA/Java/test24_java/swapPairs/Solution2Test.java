package test24_java.swapPairs;

import converter.Converter;
import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.assertArrayEquals;

public class Solution2Test {

    private Converter converter;
    private Solution2 solution;

    @Before
    public void setUp() throws Exception {
        converter = new Converter();
        solution = new Solution2();
    }

    @Test
    public void swapPairs() {
        assertArrayEquals(new int[]{2, 1, 4, 3}, converter.convertLinkedListToArray(solution.swapPairs(
                converter.convertArrayToLinkedList(new int[]{1, 2, 3, 4}))));
        assertArrayEquals(new int[]{2, 1, 4, 3, 5}, converter.convertLinkedListToArray(solution.swapPairs(
                converter.convertArrayToLinkedList(new int[]{1, 2, 3, 4, 5}))));
    }
}