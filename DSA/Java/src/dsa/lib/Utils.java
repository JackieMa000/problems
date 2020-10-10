package dsa.lib;

import java.util.Arrays;

public class Utils {
    /**
     * Rule:
     * 1. array length is 0 -> empty array
     * 2. array length is 1 and last element is 0 -> empty array
     * 3. array last element is not 0 -> array
     * 4. Array length is bigger than 1, last element is 0 -> remove the trailing 0s by loop.
     */
    //    Remove all the trailing 0s from an array
    public static int[] arrayStripTrailing(int[] ary) {
        return arrayStripTrailingIt(ary);
    }

    private static int[] arrayStripTrailingIt(int[] ary) {
        int n = ary.length;
        if (n == 0 || (n == 1 && ary[0] == 0)) return new int[0];
        if (ary[n - 1] != 0) return ary;

        int newLength = n - 1;
        while (newLength > 0 && ary[newLength - 1] == 0) newLength--;
        return Arrays.copyOf(ary, newLength);
    }

    private static int[] arrayStripTrailingDfs(int[] ary) {
        int n = ary.length;
        if (n == 0 || (n == 1 && ary[0] == 0)) return new int[0];
        if (ary[n - 1] != 0) return ary;

        return arrayStripTrailingDfs(Arrays.copyOf(ary, n - 1));
    }
}
