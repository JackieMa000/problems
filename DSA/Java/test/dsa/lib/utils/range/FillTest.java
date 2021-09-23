package dsa.lib.utils.range;

import dsa.lib.utils.Range;
import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import static org.junit.Assert.*;

public class FillTest {
    @Test
    public void integerArray() {
        int[] nums = new int[2];
        Range.fill(nums, 1);
        assertArrayEquals(new int[]{1, 1}, nums);
    }

    @Test
    public void genericArray() {
        Character[] s = new Character[2];
        Range.fill(s, 'a');
        assertArrayEquals(new Character[]{'a', 'a'}, s);
    }

    @Test
    public void genericList() {
        List<Character> in = new ArrayList<>(Arrays.asList('0', '0'));
        List<Character> want = new ArrayList<>(Arrays.asList('a', 'a'));
        Range.fill(in, 'a');
        assertEquals(want, in);
    }
}
