package coinChange;

import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class SolutionTest {
    private Solution solution;

    @Before
    public void setup() {
        solution = new Solution();
    }

    @Test
    public void canCoinChange() {
        assertEquals(2, solution.coinChange(new int[]{1, 2, 5}, 3));
        assertEquals(3, solution.coinChange(new int[]{1, 2, 5}, 11));
    }
}