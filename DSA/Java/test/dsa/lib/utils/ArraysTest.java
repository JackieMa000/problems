package dsa.lib.utils;

import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;

public class ArraysTest {
    public static class MinTest {
        @Test
        public void min() {
            assertMin(0, new int[]{0});
            assertMin(1, new int[]{1, 2, 3});
        }

        private void assertMin(int expected, int[] nums) {
            assertEquals(expected, Arrays.min(nums));
        }
    }

    public static class MaxTest {
        @Test
        public void max() {
            assertMax(new int[]{0}, 0);
            assertMax(new int[]{1, 2, 3}, 3);
        }

        private void assertMax(int[] nums, int expected) {
            assertEquals(expected, Arrays.max(nums));
        }
    }

    public static class MaxSizeElementTest {
        @Test
        public void charArrayElement() {
            Character[][] ss = {{'a'}, {'a', 'b'}, {'a', 'b', 'c'}};
            Character[] expected = {'a', 'b', 'c'};
            assertArrayEquals(expected, Arrays.maxSizeElement(ss));
        }

        @Test
        public void intArrayElement() {
            Integer[][] ints = {{1}, {1, 2}, {1, 2, 3}};
            Integer[] expected = {1, 2, 3};
            assertArrayEquals(expected, Arrays.maxSizeElement(ints));
        }

        @Test
        public void stringArrayElement() {
            String[] ss = {"a", "ab", "abc"};
            String expected = "abc";
            assertEquals(expected, Arrays.maxSizeElement(ss));
        }

        @Test
        public void charListElement() {
            final List<Character> l1 = Arrays.asList('a');
            final List<Character> l2 = Arrays.asList('a', 'b');
            final List<Character> l3 = Arrays.asList('a', 'b', 'c');

            List<List<Character>> ss = new ArrayList<>();
            ss.add(new ArrayList<>(l1));
            ss.add(new ArrayList<>(l2));
            ss.add(new ArrayList<>(l3));

            ArrayList<Character> expected = new ArrayList<>(l3);
            assertEquals(expected, Arrays.maxSizeElement(ss));
            assertEquals(expected, Arrays.maxSizeElement(ss.iterator()));
        }
    }
}