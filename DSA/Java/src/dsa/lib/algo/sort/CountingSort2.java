package dsa.lib.algo.sort;

/**
 * sort the elements in the basis of significant places for String.
 * only handles the small case of letters so far.
 */
public class CountingSort2 {
    /**
     * @param ary   the array of String to sort
     * @param place the index of character you want to sort
     */
    final int charRangeSize = 26;
    final int rangeStart = 97;

    public void sort(String[] ary, int place) {
        int length = ary.length;
        if (length <= 1) return;

        int[] counts = new int[charRangeSize];

        initCounts(counts);
        storeCounts(counts, ary, place);
        accumulateCounts(counts);

        String[] result = new String[length];
        generateResult(result, ary, counts, place);

        arraycopy(result, 0, ary, 0, length);
    }

    private void initCounts(int[] counts) {
        for (int i = 0; i < counts.length; ++i) counts[i] = 0;
    }

    private void storeCounts(int[] counts, String[] ary, int place) {
        for (final String cur : ary) {
            int lastIndex = cur.length() - 1;
            int placeValue = place > lastIndex ? cur.charAt(lastIndex) : cur.charAt(place);
            counts[placeValue - rangeStart]++;
        }
    }

    private void accumulateCounts(int[] counts) {
        for (int i = 1; i < counts.length; ++i) {
            counts[i] += counts[i - 1];
        }
    }

    private void generateResult(String[] result, String[] ary, int[] counts, int place) {
        for (int i = ary.length - 1; i >= 0; --i) {
            final String s = ary[i];
            final int lastIndex = s.length() - 1;
            int placeValue = place > lastIndex ? s.charAt(lastIndex) : s.charAt(place);
            int index = counts[placeValue -= rangeStart] - 1;
            result[index] = s;
            counts[placeValue]--;
        }
    }

    private static void arraycopy(String[] src, int srcPos, String[] dest, int destPos, int length) {
        for (int i = 0; i < length; i++) {
            dest[destPos + i] = src[srcPos + i];
        }
    }

}
