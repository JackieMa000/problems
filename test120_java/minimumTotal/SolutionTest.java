package minimumTotal;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.Assert.assertEquals;

public class SolutionTest {

    private List<List<Integer>> getInput() {
        List<List<Integer>> input = new ArrayList<>();

        List<Integer> a1 = new ArrayList<>(Collections.singletonList(2));
        input.add(a1);

        List<Integer> a2 = new ArrayList<>(Arrays.asList(3, 4));
        input.add(a2);

        List<Integer> a3 = new ArrayList<>(Arrays.asList(6, 5, 7));
        input.add(a3);

        List<Integer> a4 = new ArrayList<>(Arrays.asList(4, 1, 8, 3));
        input.add(a4);
        return input;
    }

    @Test
    public void dfsSolution() {
        SolutionDFS solution = new SolutionDFS();
        assertEquals(11, solution.minimumTotal(getInput()));
    }

    @Test
    public void dpSolution() {
        SolutionDP solution = new SolutionDP();
        assertEquals(11, solution.minimumTotal(getInput()));
    }
}
