package dsa.lib.utils.range;

import dsa.lib.utils.Range;
import org.junit.Test;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

import static org.junit.Assert.*;

public class SwapTest {
    @Test
    public void integerArray() {
        int[] nums = {1, 2};
        Range.swap(nums, 0, 1);
        assertArrayEquals(new int[]{2, 1}, nums);
    }

    @Test
    public void genericArray() {
        Character[] s = {'a', 'b'};
        Range.swap(s, 0, 1);
        assertArrayEquals(new Character[]{'b', 'a'}, s);
    }

    @Test
    public void genericList() {
        List<Character> in = new LinkedList<>(Arrays.asList('a', 'b'));
        List<Character> want = new LinkedList<>(Arrays.asList('b', 'a'));
        Range.swap(in, 0, 1);
        assertEquals(want, in);
    }
}
