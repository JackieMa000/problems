package dsa.lib.utils.range;

import dsa.lib.utils.Range;
import org.junit.Test;

import static org.junit.Assert.assertArrayEquals;

public class StripTest {
    public static class LStripTest {
        private int[] lstripIt(int[] nums) {
            return Range.lstripIt(nums);
        }

        private int[] lstripDfs(int[] nums) {
            return Range.lstripDfs(nums);
        }

        @Test
        public void empty_returnEmpty() {
            assertLStrip(new int[]{}, new int[]{});
        }

        private void assertLStrip(int[] expected, int[] nums) {
            assertArrayEquals(expected, lstripIt(nums));
            assertArrayEquals(expected, lstripDfs(nums));
        }

        @Test
        public void all0s_returnEmpty() {
            assertLStrip(new int[]{}, new int[]{0});
            assertLStrip(new int[]{}, new int[]{0, 0});
        }

        @Test
        public void leftNot0s() {
            assertLStrip(new int[]{1}, new int[]{1});
            assertLStrip(new int[]{1, 2}, new int[]{1, 2});
        }

        @Test
        public void left0s() {
            assertLStrip(new int[]{1}, new int[]{0, 1});
            assertLStrip(new int[]{1}, new int[]{0, 0, 1});
            assertLStrip(new int[]{1, 2}, new int[]{0, 0, 1, 2});
            assertLStrip(new int[]{1, 0, 2}, new int[]{0, 0, 1, 0, 2});
        }
    }

    public static class RStripTest {
        private int[] rstripIt(int[] nums) {
            return Range.rstripIt(nums);
        }

        private int[] rstripDfs(int[] nums) {
            return Range.rstripDfs(nums);
        }

        private void assertRStrip(int[] expected, int[] nums) {
            assertArrayEquals(expected, rstripIt(nums));
            assertArrayEquals(expected, rstripDfs(nums));
        }

        @Test
        public void empty_returnEmpty() {
            assertRStrip(new int[]{}, new int[]{});
        }

        @Test
        public void all0s_returnEmpty() {
            assertRStrip(new int[]{}, new int[]{0});
            assertRStrip(new int[]{}, new int[]{0, 0});
        }

        @Test
        public void rightNot0s() {
            assertRStrip(new int[]{1}, new int[]{1});
            assertRStrip(new int[]{1, 2}, new int[]{1, 2});
        }

        @Test
        public void right0s() {
            assertRStrip(new int[]{1}, new int[]{1, 0});
            assertRStrip(new int[]{1}, new int[]{1, 0, 0});
            assertRStrip(new int[]{1, 2}, new int[]{1, 2, 0, 0});
            assertRStrip(new int[]{1, 0, 2}, new int[]{1, 0, 2, 0, 0});
        }

    }

    public static class _StripTest {
        private int[] stripIt(int[] nums) {
            return Range.stripIt(nums);
        }

        private int[] stripDfs(int[] nums) {
            return Range.stripDfs(nums);
        }

        private void assertStrip(int[] expected, int[] nums) {
            assertArrayEquals(expected, stripIt(nums));
            assertArrayEquals(expected, stripDfs(nums));
        }

        @Test
        public void empty_returnEmpty() {
            assertStrip(new int[]{}, new int[]{});
        }

        @Test
        public void all0s_returnEmpty() {
            assertStrip(new int[]{}, new int[]{0});
            assertStrip(new int[]{}, new int[]{0, 0});
        }

        @Test
        public void leftRightNot0s() {
            assertStrip(new int[]{1}, new int[]{1});
            assertStrip(new int[]{1, 2}, new int[]{1, 2});
        }

        @Test
        public void leftRight0s() {
            assertStrip(new int[]{1}, new int[]{0, 1, 0});
            assertStrip(new int[]{1}, new int[]{0, 0, 1, 0});
            assertStrip(new int[]{1, 2}, new int[]{0, 0, 1, 2});
            assertStrip(new int[]{1, 2}, new int[]{0, 0, 1, 2, 0, 0});
            assertStrip(new int[]{1, 0, 2}, new int[]{0, 0, 1, 0, 2});
            assertStrip(new int[]{1, 0, 2}, new int[]{0, 0, 1, 0, 2, 0, 0});
        }
    }
}
