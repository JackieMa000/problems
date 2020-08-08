package threeSum;

import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import static org.junit.Assert.assertEquals;

public class SolutionTest {
    private Solution solution;

    @Before
    public void setUp() {
        solution = new Solution();
    }

    @Test
    public void threeSum() {
        List<List<Integer>> expected = new ArrayList<>();
        expected.add(new ArrayList<>(Arrays.asList(0, 0, 0)));
        assertEquals(expected, solution.threeSum(new int[]{0, 0, 0, 0}));
    }

    @Test
    public void threeSum1() {
        List<List<Integer>> expected = new ArrayList<>();
        expected.add(new ArrayList<>(Arrays.asList(-2, 0, 2)));
        assertEquals(expected, solution.threeSum(new int[]{-2, 0, 0, 2, 2}));
    }

    @Test
    public void threeSum2() {
        List<List<Integer>> expected = new ArrayList<>();
        expected.add(new ArrayList<>(Arrays.asList(-1, 0, 1)));
        assertEquals(expected, solution.threeSum(new int[]{-1, 0, 1, 0}));
    }

    @Test
    public void threeSum3() {
        List<List<Integer>> expected = new ArrayList<>();
        expected.add(new ArrayList<>(Arrays.asList(-1, -1, 2)));
        expected.add(new ArrayList<>(Arrays.asList(-1, 0, 1)));
        assertEquals(expected, solution.threeSum(new int[]{-1, 0, 1, 2, -1, -4}));
    }
}
