package dsa.lib.utils.Algorithm;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class NumsTest {
    @Test
    public void lastDigitOf() {
        assertLastDigitOf(0, 0);
        assertLastDigitOf(1, 1);
        assertLastDigitOf(10, 0);
        assertLastDigitOf(123, 3);
    }

    private void assertLastDigitOf(int num, int expected) {
        assertEquals(expected, Nums.lastDigitOf(num));
    }

    public static class PlaceValueOf {
        @Test
        public void unitPlace() {
            assertPlaceValueOf(0, 1, 0);
            assertPlaceValueOf(1, 1, 1);
            assertPlaceValueOf(123, 1, 3);
        }

        @Test
        public void tensPlace() {
            assertPlaceValueOf(123, 10, 2);
        }

        @Test
        public void hundredsPlace() {
            assertPlaceValueOf(123, 100, 1);
        }

        private void assertPlaceValueOf(int num, int place, int expected) {
            assertEquals(expected, Nums.placeValueOf(num, place));
        }
    }
}