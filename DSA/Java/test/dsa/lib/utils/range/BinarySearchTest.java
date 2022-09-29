package dsa.lib.utils.range;

import dsa.lib.utils.Range;
import org.junit.Test;

import static org.junit.Assert.assertEquals;


public class BinarySearchTest {
    @Test
    public void emptyArray() {
        assertEquals(-1, Range.binarySearch(new int[]{}, 1));
    }

    @Test
    public void oneElement() {
        assertEquals(0, Range.binarySearch(new int[]{1}, 1));
    }

    @Test
    public void evenList() {
        assertEquals(0, Range.binarySearch(new int[]{1, 2}, 1));
        assertEquals(2, Range.binarySearch(new int[]{1, 2, 3, 4}, 3));
        assertEquals(-1, Range.binarySearch(new int[]{1, 2, 3, 4}, 25));
    }

    @Test
    public void oddList() {
        assertEquals(0, Range.binarySearch(new int[]{1}, 1));
        assertEquals(-1, Range.binarySearch(new int[]{1}, 5));
        assertEquals(2, Range.binarySearch(new int[]{1, 2, 3}, 3));
        assertEquals(4, Range.binarySearch(new int[]{1, 2, 3, 4, 5}, 5));
    }
}
