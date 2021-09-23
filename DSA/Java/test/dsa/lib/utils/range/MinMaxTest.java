package dsa.lib.utils.range;

import dsa.lib.utils.Range;
import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import static org.junit.Assert.*;

public class MinMaxTest {
    public static class MinTest {
        @Test
        public void min() {
            assertMin(0, new int[]{0});
            assertMin(1, new int[]{1, 2, 3});
        }

        private void assertMin(int expected, int[] nums) {
            assertEquals(expected, Range.min(nums));
        }
    }

    public static class MaxTest {
        @Test
        public void empty() {
            assertNull(Range.max(new Integer[]{}));
        }

        @Test
        public void oneElement() {
            final Integer[] nums = {0};
            assertMaxInteger(nums[0], nums);
        }

        @Test
        public void multiResults_returnFirst() {
            final Integer[] nums = {1, 1};
            assertMaxInteger(nums[0], nums);
        }

        @Test
        public void case1() {
            final Integer[] nums = {1, 2, 3};
            assertMaxInteger(nums[2], nums);
        }

        private void assertMaxInteger(Integer expected, Integer[] nums) {
            assertSame(expected, Range.max(nums));
            assertEquals(expected, Range.max(nums));
        }
    }

    public static class MaxSizeTest {
        @Test
        public void charArrayElement() {
            Character[][] ss = {{'a'}, {'a', 'b'}, {'a', 'b', 'c'}};
            Character[] expected = ss[2];

            final Character[] actual = Range.maxSize(ss);

            assertSame(expected, actual);
            assertArrayEquals(expected, actual);
        }

        @Test
        public void intArrayElement() {
            Integer[][] nums = {{1}, {1, 2}, {1, 2, 3}};
            Integer[] expected = nums[2];

            final Integer[] actual = maxSize(nums);

            assertSame(expected, actual);
            assertArrayEquals(expected, actual);
        }

        @Test
        public void stringArrayElement() {
            String[] ss = {"a", "ab", "abc"};
            String expected = ss[2];

            final String actual = Range.maxSize(ss);

            assertSame(expected, actual);
            assertEquals(expected, actual);
        }

        @Test
        public void charListElement() {
            final List<Character> l1 = List.of('a');
            final List<Character> l2 = Arrays.asList('a', 'b');
            final List<Character> l3 = Arrays.asList('a', 'b', 'c');

            List<List<Character>> ss = new ArrayList<>();
            ss.add(new ArrayList<>(l1));
            ss.add(new ArrayList<>(l2));
            ss.add(new ArrayList<>(l3));

            List<Character> expected = ss.get(2);

            final List<Character> actual = Range.maxSize(ss);
            final List<Character> actual1 = Range.maxSize(ss.iterator());

            assertSame(expected, actual);
            assertEquals(expected, actual);
            assertEquals(expected, actual1);
            assertSame(expected, actual1);
        }

        private Integer[] maxSize(Integer[][] nums) {
            return Range.maxSize(nums);
        }

        @Test
        public void empty() {
            Integer[][] a = {};
            assertNull(maxSize(a));
        }

        @Test
        public void oneElement() {
            Integer[][] a = {{0}};
            var actual = maxSize(a);
            assertSame(a[0], actual);
            assertArrayEquals(a[0], actual);
        }

        @Test
        public void multiResults_returnFirst() {
            Integer[][] a = {{0}, {1}};
            var actual = maxSize(a);
            assertSame(a[0], actual);
            assertArrayEquals(a[0], actual);
        }
    }

    public static class MinSizeTest {
        private Integer[] minSize(Integer[][] nums) {
            return Range.minSize(nums);
        }

        @Test
        public void empty() {
            Integer[][] a = {};
            assertNull(minSize(a));
        }

        @Test
        public void oneElement() {
            Integer[][] a = {{0}};
            var actual = minSize(a);
            assertSame(a[0], actual);
            assertArrayEquals(a[0], actual);
        }

        @Test
        public void multiResults_returnFirst() {
            Integer[][] a = {{0}, {1}};
            var actual = minSize(a);
            assertSame(a[0], actual);
            assertArrayEquals(a[0], actual);
        }

        @Test
        public void case1() {
            Integer[][] a = {{0, 0}, {1}};
            var actual = minSize(a);
            assertSame(a[1], actual);
            assertArrayEquals(a[1], actual);
        }

        @Test
        public void charArrayElement() {
            Character[][] ss = {{'a'}, {'a', 'b'}, {'a', 'b', 'c'}};
            final Character[] expected = ss[0];

            final Character[] actual = Range.minSize(ss);

            assertSame(expected, actual);
            assertArrayEquals(expected, actual);
        }

        @Test
        public void intArrayElement() {
            Integer[][] nums = {{1}, {1, 2}, {1, 2, 3}};
            Integer[] expected = nums[0];

            final Integer[] actual = Range.minSize(nums);

            assertSame(expected, actual);
            assertArrayEquals(expected, actual);
        }

        @Test
        public void stringArrayElement() {
            String[] ss = {"a", "ab", "abc"};
            String expected = ss[0];

            final String actual = Range.minSize(ss);

            assertSame(expected, actual);
            assertEquals(expected, actual);
        }

        @Test
        public void charListElement() {
            final List<Character> l1 = List.of('a');
            final List<Character> l2 = Arrays.asList('a', 'b');
            final List<Character> l3 = Arrays.asList('a', 'b', 'c');

            List<List<Character>> ss = new ArrayList<>();
            ss.add(new ArrayList<>(l1));
            ss.add(new ArrayList<>(l2));
            ss.add(new ArrayList<>(l3));

            List<Character> expected = ss.get(0);

            final List<Character> actual = Range.minSize(ss);
            final List<Character> actual1 = Range.minSize(ss.iterator());

            assertSame(expected, actual);
            assertEquals(expected, actual);
            assertSame(expected, actual1);
            assertEquals(expected, actual1);
        }
    }
}
