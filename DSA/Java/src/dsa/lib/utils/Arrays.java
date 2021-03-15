package dsa.lib.utils;

public class Arrays {
    /**
     * Rule:
     * 1. array length is 0 -> empty array
     * 2. array length is 1 and last element is 0 -> empty array
     * 3. array last element is not 0 -> array
     * 4. Array length is bigger than 1, last element is 0 -> remove the trailing 0s by loop.
     */
    //    Remove all the trailing 0s from an array
    public static int[] rstrip(int[] ary) {
        return rstripIt(ary);
    }

    private static int[] rstripIt(int[] ary) {
        int n = ary.length;
        if (n == 0 || (n == 1 && ary[0] == 0)) return new int[0];
        if (ary[n - 1] != 0) return ary;

        int newLength = n - 1;
        while (newLength > 0 && ary[newLength - 1] == 0) newLength--;
        return java.util.Arrays.copyOf(ary, newLength);
    }

    private static int[] rstripDfs(int[] ary) {
        int n = ary.length;
        if (n == 0 || (n == 1 && ary[0] == 0)) return new int[0];
        if (ary[n - 1] != 0) return ary;

        return rstripDfs(java.util.Arrays.copyOf(ary, n - 1));
    }

    /**
     * Swap 2 elements of an array.
     *
     * @param ary The array.
     * @param i   The position of 1st element.
     * @param j   The position of 2nd element.
     */
    public static void swap(int[] ary, int i, int j) {
        int tmp = ary[i];
        ary[i] = ary[j];
        ary[j] = tmp;
    }

    public static void copy(int[] src, int srcPos, int[] dest, int destPos, int length) {
        for (int i = 0; i < length; i++) dest[destPos + i] = src[srcPos + i];
    }

    public static void fill(int[] ary, int val) {
        for (int i = 0; i < ary.length; ++i) ary[i] = val;
    }

    public static int max(int[] ary) {
        int max = ary[0];
        for (int i = 1; i < ary.length; ++i) {
            if (ary[i] > max) max = ary[i];
        }
        return max;
    }

    public static int min(int[] ary) {
        int min = ary[0];
        for (int i = 1; i < ary.length; i++) {
            if (ary[i] < min) min = ary[i];
        }
        return min;
    }
}
