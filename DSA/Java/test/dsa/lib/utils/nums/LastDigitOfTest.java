package dsa.lib.utils.nums;

import dsa.lib.utils.Nums;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class LastDigitOfTest {
    @Test
    public void case1() {
        assertLastDigitOf(0, 0);
        assertLastDigitOf(1, 1);
        assertLastDigitOf(10, 0);
        assertLastDigitOf(123, 3);
    }

    private void assertLastDigitOf(int num, int expected) {
        assertEquals(expected, Nums.lastDigitOf(num));
    }

}