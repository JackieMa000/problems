package dsa.lib.math.nums;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import static org.junit.Assert.assertEquals;

public class ThreeSumTest {

    private List<List<Integer>> threeSum(int[] nums) {
        return new ThreeSum().threeSum(nums);
    }

    @Test
    public void case1() {
        List<List<Integer>> expected = new ArrayList<>();
        expected.add(new ArrayList<>(Arrays.asList(0, 0, 0)));
        assertEquals(expected, threeSum(new int[]{0, 0, 0, 0}));
    }

    @Test
    public void case2() {
        List<List<Integer>> expected = new ArrayList<>();
        expected.add(new ArrayList<>(Arrays.asList(-2, 0, 2)));
        assertEquals(expected, threeSum(new int[]{-2, 0, 0, 2, 2}));
    }

    @Test
    public void case3() {
        List<List<Integer>> expected = new ArrayList<>();
        expected.add(new ArrayList<>(Arrays.asList(-1, 0, 1)));
        assertEquals(expected, threeSum(new int[]{-1, 0, 1, 0}));
    }

    @Test
    public void case4() {
        List<List<Integer>> expected = new ArrayList<>();
        expected.add(new ArrayList<>(Arrays.asList(-1, -1, 2)));
        expected.add(new ArrayList<>(Arrays.asList(-1, 0, 1)));
        assertEquals(expected, threeSum(new int[]{-1, 0, 1, 2, -1, -4}));
    }
}
