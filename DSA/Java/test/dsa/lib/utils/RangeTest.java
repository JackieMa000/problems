package dsa.lib.utils;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

import static org.junit.Assert.*;

public class RangeTest {
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

    public static class MaxSizeElementTest {
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

            final Integer[] actual = maxSizeElement(nums);

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

        private Integer[] maxSizeElement(Integer[][] nums) {
            return Range.maxSize(nums);
        }

        @Test
        public void empty() {
            Integer[][] a = {};
            assertNull(maxSizeElement(a));
        }

        @Test
        public void oneElement() {
            Integer[][] a = {{0}};
            var actual = maxSizeElement(a);
            assertSame(a[0], actual);
            assertArrayEquals(a[0], actual);
        }

        @Test
        public void multiResults_returnFirst() {
            Integer[][] a = {{0}, {1}};
            var actual = maxSizeElement(a);
            assertSame(a[0], actual);
            assertArrayEquals(a[0], actual);
        }
    }

    public static class MinSizeElement {
        private Integer[] minSizeElement(Integer[][] nums) {
            return Range.minSize(nums);
        }

        @Test
        public void empty() {
            Integer[][] a = {};
            assertNull(minSizeElement(a));
        }

        @Test
        public void oneElement() {
            Integer[][] a = {{0}};
            var actual = minSizeElement(a);
            assertSame(a[0], actual);
            assertArrayEquals(a[0], actual);
        }

        @Test
        public void multiResults_returnFirst() {
            Integer[][] a = {{0}, {1}};
            var actual = minSizeElement(a);
            assertSame(a[0], actual);
            assertArrayEquals(a[0], actual);
        }

        @Test
        public void case1() {
            Integer[][] a = {{0, 0}, {1}};
            var actual = minSizeElement(a);
            assertSame(a[1], actual);
            assertArrayEquals(a[1], actual);
        }
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

    public static class ArrayRStripTest {
        private int[] rstrip(int[] nums) {
            return Range.rstrip(nums);
        }

        @Test
        public void emptyArray_returnEmpty() {
            assertArrayEquals(new int[]{}, rstrip(new int[]{}));
        }

        @Test
        public void all0_returnEmpty() {
            assertArrayEquals(new int[]{}, rstrip(new int[]{0}));
            assertArrayEquals(new int[]{}, rstrip(new int[]{0, 0}));
        }

        @Test
        public void lastElementNot0() {
            assertArrayEquals(new int[]{1}, rstrip(new int[]{1}));
            assertArrayEquals(new int[]{1, 2}, rstrip(new int[]{1, 2}));
        }

        @Test
        public void lastElement0() {
            assertArrayEquals(new int[]{1}, rstrip(new int[]{1, 0}));
            assertArrayEquals(new int[]{1}, rstrip(new int[]{1, 0, 0}));
            assertArrayEquals(new int[]{1, 2}, rstrip(new int[]{1, 2, 0, 0}));
            assertArrayEquals(new int[]{1, 0, 2}, rstrip(new int[]{1, 0, 2, 0, 0}));
        }
    }

    public static class ArrayLStripTest {
        private int[] lstrip(int[] nums) {
            return Range.lstrip(nums);
        }

        @Test
        public void emptyArray_returnEmpty() {
            assertArrayEquals(new int[]{}, lstrip(new int[]{}));
        }

        @Test
        public void all0_returnEmpty() {
            assertArrayEquals(new int[]{}, lstrip(new int[]{0}));
        }

        @Test
        public void lastElementNot0() {
            assertArrayEquals(new int[]{1}, lstrip(new int[]{1}));
            assertArrayEquals(new int[]{1, 2}, lstrip(new int[]{1, 2}));
        }

        @Test
        public void lastElement0() {
            assertArrayEquals(new int[]{1}, lstrip(new int[]{0, 1}));
            assertArrayEquals(new int[]{1}, lstrip(new int[]{0, 0, 1}));
            assertArrayEquals(new int[]{1, 2}, lstrip(new int[]{0, 0, 1, 2}));
            assertArrayEquals(new int[]{1, 0, 2}, lstrip(new int[]{0, 0, 1, 0, 2}));
        }
    }

    public static class ArrayStripTest {
        private int[] strip(int[] nums) {
            return Range.strip(nums);
        }

        @Test
        public void emptyArray_returnEmpty() {
            assertArrayEquals(new int[]{}, strip(new int[]{}));
        }

        @Test
        public void all0_returnEmpty() {
            assertArrayEquals(new int[]{}, strip(new int[]{0}));
            assertArrayEquals(new int[]{}, strip(new int[]{0, 0}));
        }

        @Test
        public void no0s() {
            assertArrayEquals(new int[]{1}, strip(new int[]{1}));
            assertArrayEquals(new int[]{1, 2}, strip(new int[]{1, 2}));
        }

        @Test
        public void has0s() {
            assertArrayEquals(new int[]{1}, strip(new int[]{0, 1, 0}));
            assertArrayEquals(new int[]{1}, strip(new int[]{0, 0, 1, 0}));
            assertArrayEquals(new int[]{1, 2}, strip(new int[]{0, 0, 1, 2}));
            assertArrayEquals(new int[]{1, 2}, strip(new int[]{0, 0, 1, 2, 0, 0}));
            assertArrayEquals(new int[]{1, 0, 2}, strip(new int[]{0, 0, 1, 0, 2}));
            assertArrayEquals(new int[]{1, 0, 2}, strip(new int[]{0, 0, 1, 0, 2, 0, 0}));
        }
    }

    public static class SwapTest {
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

    public static class FillTest {
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
}