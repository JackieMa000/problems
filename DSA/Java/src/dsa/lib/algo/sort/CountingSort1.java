package dsa.lib.algo.sort;

/**
 * sort the elements in the basis of significant places for integer
 */
public class CountingSort1 {
    /**
     * @param ary
     * @param place the place of integer you want to sort with. Can be 1(unit place), 10(tens place), 100(hundreds place).
     */
    void sort(int[] ary, int place) {
        int length = ary.length;
        if (length <= 1) return;

        int[] counts = new int[10];

        initCounts(counts);
        storeCounts(ary, counts, place);
        accumulateCounts(counts);

        int[] result = new int[length];
        generateResult(result, ary, counts, place);

        arraycopy(result, 0, ary, 0, length);
    }

    private void generateResult(int[] result, int[] ary, int[] counts, int place) {
        for (int i = ary.length - 1; i >= 0; i--) {
            final int placeValue = (ary[i] / place) % 10;
            final int index = counts[placeValue] - 1;
            result[index] = ary[i];
            counts[placeValue]--;
        }
    }

    private void initCounts(int[] counts) {
        for (int i = 0; i < counts.length; ++i) counts[i] = 0;
    }

    private void storeCounts(int[] ary, int[] counts, int place) {
        for (int i = 0; i < ary.length; i++) {
            final int placeValue = (ary[i] / place) % 10;
            counts[placeValue]++;
        }
    }

    private void accumulateCounts(int[] counts) {
        for (int i = 1; i < counts.length; i++) {
            counts[i] += counts[i - 1];
        }
    }

    private static void arraycopy(int[] src, int srcPos, int[] dest, int destPos, int length) {
        for (int i = 0; i < length; i++) {
            dest[destPos + i] = src[srcPos + i];
        }
    }
}
