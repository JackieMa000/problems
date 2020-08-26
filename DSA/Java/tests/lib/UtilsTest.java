package lib;

import org.junit.Ignore;
import org.junit.Test;

import static org.junit.Assert.*;

public class UtilsTest {

    public static class ArrayStripTrailingTest {

        @Ignore("FixMe")
        @Test
//        FixMe
        public void case1() {
            assertArrayEquals(new int[]{}, Utils.arrayStripTrailing(new int[]{}));
        }

        @Ignore("FixMe")
        @Test
//        FixMe
        public void case2() {
            assertArrayEquals(new int[]{}, Utils.arrayStripTrailing(new int[]{0, 0}));
        }

        @Test
        public void case3() {
            assertArrayEquals(new int[]{1}, Utils.arrayStripTrailing(new int[]{1}));
            assertArrayEquals(new int[]{1}, Utils.arrayStripTrailing(new int[]{1, 0}));
            assertArrayEquals(new int[]{1}, Utils.arrayStripTrailing(new int[]{1, 0, 0}));
            assertArrayEquals(new int[]{1, 2}, Utils.arrayStripTrailing(new int[]{1, 2, 0, 0}));
        }
    }

    public static class ArrayStripTrailingDfsTest {

        @Test
        public void arrayStripTrailingDfs() {
//        ToDo
        }
    }
}
