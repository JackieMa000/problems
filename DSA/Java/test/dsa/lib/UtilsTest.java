package dsa.lib;

import dsa.lib.utils.Arrays;
import org.junit.Test;

import static org.junit.Assert.*;

public class UtilsTest extends LibTestFX {

    public static class ArrayStripTrailingTest {

        @Test
        public void emptyArray() {
            assertArrayEquals(new int[]{}, Arrays.rstrip(new int[]{}));
        }

        @Test
        public void length1Element0() {
            assertArrayEquals(new int[]{}, Arrays.rstrip(new int[]{0}));
        }

        @Test
        public void case1() {
            assertArrayEquals(new int[]{1}, Arrays.rstrip(new int[]{1}));
            assertArrayEquals(new int[]{1, 2}, Arrays.rstrip(new int[]{1, 2}));
        }

        @Test
        public void case2() {
            assertArrayEquals(new int[]{1}, Arrays.rstrip(new int[]{1, 0}));
            assertArrayEquals(new int[]{1}, Arrays.rstrip(new int[]{1, 0, 0}));
            assertArrayEquals(new int[]{1, 2}, Arrays.rstrip(new int[]{1, 2, 0, 0}));
            assertArrayEquals(new int[]{1, 0, 2}, Arrays.rstrip(new int[]{1, 0, 2, 0, 0}));
        }
    }
}
