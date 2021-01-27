package dsa.lib.algo.sort;


public class BubbleSort {
    public static void sort(int[] ary) {
        int n = ary.length;

        for (int i = 0; i < n; i++) {
            boolean swapped = false;
            for (int j = 0; j < n - 1 - i; j++) {
                if (ary[j] > ary[j + 1]) {
                    arraySwap(ary, j, j + 1);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }

    private static void arraySwap(int[] ary, int i, int j) {
        int tmp = ary[i];
        ary[i] = ary[j];
        ary[j] = tmp;
    }
}
