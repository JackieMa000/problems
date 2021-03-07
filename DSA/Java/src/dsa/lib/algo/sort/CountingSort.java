package dsa.lib.algo.sort;

public class CountingSort {
    public void sort(int[] ary) {
        int length = ary.length;
        if (length <= 1) return;

        int max = getArrayMax(ary);
        int[] counts = new int[max + 1];

        initCounts(counts);
        storeCounts(counts, ary);
        accumulateCounts(counts);

        int[] result = new int[length];
        generateResult(result, ary, counts);

        arraycopy(result, 0, ary, 0, length);
    }

    private void generateResult(int[] result, int[] ary, int[] counts) {
        int n = ary.length;
        for (int i = n - 1; i >= 0; --i) {
            final int cur = ary[i];
            int index = counts[cur] - 1;
            result[index] = cur;
            counts[cur]--;
        }
    }

    private static void arraycopy(int[] src, int srcPos, int[] dest, int destPos, int length) {
        for (int i = 0; i < length; i++) {
            dest[destPos + i] = src[srcPos + i];
        }
    }

    private void initCounts(int[] counts) {
        for (int i = 0; i < counts.length; ++i) counts[i] = 0;
    }

    private void storeCounts(int[] counts, int[] ary) {
        for (int e : ary) counts[e]++;
    }

    private void accumulateCounts(int[] counts) {
        for (int i = 1; i < counts.length; ++i) counts[i] += counts[i - 1];
    }

    private int getArrayMax(int[] ary) {
        int max = ary[0];
        for (int i = 1; i < ary.length; ++i) {
            if (ary[i] > max) max = ary[i];
        }
        return max;
    }
}
