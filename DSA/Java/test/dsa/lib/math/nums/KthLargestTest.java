package dsa.lib.math.nums;

import org.junit.Test;

import static org.junit.Assert.*;

public class KthLargestTest {
    public static class AddTest {
        @Test
        public void case1() {
            KthLargest kl = new KthLargest(3, new int[]{4, 5, 8, 2});
            assertEquals(4, kl.add(3));
            assertEquals(5, kl.add(5));
            assertEquals(5, kl.add(10));
            assertEquals(8, kl.add(9));
            assertEquals(8, kl.add(4));
        }
    }

}