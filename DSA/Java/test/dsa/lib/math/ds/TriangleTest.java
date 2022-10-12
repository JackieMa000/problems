package dsa.lib.math.ds;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.Assert.assertEquals;

public class TriangleTest {
    public static class MinimumTotalTest {
        private List<List<Integer>> createTriangle() {
            List<List<Integer>> triangle = new ArrayList<>();

            List<Integer> row1 = new ArrayList<>(Collections.singletonList(2));
            triangle.add(row1);

            List<Integer> row2 = new ArrayList<>(Arrays.asList(3, 4));
            triangle.add(row2);

            List<Integer> row3 = new ArrayList<>(Arrays.asList(6, 5, 7));
            triangle.add(row3);

            List<Integer> row4 = new ArrayList<>(Arrays.asList(4, 1, 8, 3));
            triangle.add(row4);

            return triangle;
        }

        private List<List<Integer>> createTriangle1() {
            List<List<Integer>> triangle = new ArrayList<>();

            List<Integer> row1 = new ArrayList<>(Collections.singletonList(-10));
            triangle.add(row1);

            return triangle;
        }

        @Test
        public void case1() {
            assertEquals(11, minimumTotal(createTriangle()));
            assertEquals(-10, minimumTotal(createTriangle1()));
        }

        private static int minimumTotal(List<List<Integer>> triangle) {
            int r = new Triangle().minimumTotal(triangle);
            int r1 = new Triangle().minimumTotal1(triangle);
            int r2 = new Triangle().minimumTotal2(triangle);
            int r3 = new Triangle().minimumTotal3(triangle);
            assert r == r1 && r == r2 && r == r3 : "Results from multiple same functions are different.";

            return r;
        }
    }

}