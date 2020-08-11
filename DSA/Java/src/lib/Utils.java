package lib;

import java.util.Arrays;

public class Utils {
    public static int[] arrayStripTrailing(int[] array) {
//        FixMe: Edge case
        int n = array.length;
        if (array[n - 1] != 0) return array;
        int end = n - 1;
        for (int i = n - 1; i >=0; i--) {
            if (array[i] == 0 && (i - 1) >= 0 && array[i - 1] != 0) {
                end = i;
                break;
            }
        }
        return Arrays.copyOf(array, end);
    }

    public static int[] arrayStripTrailingDfs(int[] array) {
//        ToDo
        return array;
    }
}
