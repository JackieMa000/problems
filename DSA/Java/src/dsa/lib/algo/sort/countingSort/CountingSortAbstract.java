package dsa.lib.algo.sort.countingSort;

import dsa.lib.utils.Arrays;

abstract class CountingSortAbstract<T> {
    protected T[] ary;
    protected final int size;
    int min, max;

    protected int[] counts;
    protected int COUNTS_SIZE;

    protected CountingSortAbstract(T[] ary) {
        this.ary = ary;
        this.size = ary.length;
    }

    public abstract void sort();

    protected void initFields() {
        initMinMax();
        COUNTS_SIZE = max - min + 1;
        initCounts();
    }

    protected void initCounts() {
        counts = new int[COUNTS_SIZE];
        Arrays.fill(counts, 0);
    }

    protected void storeCounts() {
        for (final T e : ary) ++counts[countsIndexOf(e)];
    }

    protected void accumulateCounts() {
        for (int i = 1; i < counts.length; ++i) counts[i] += counts[i - 1];
    }

    protected void generateResult(T[] result) {
        for (int i = size - 1; i >= 0; --i) {
            final T e = ary[i];
            final int ci = countsIndexOf(e);
            final int index = counts[ci] - 1;

            result[index] = e;
            --counts[ci];
        }
    }

    protected abstract void initMinMax();

    protected abstract int countsIndexOf(T e);
}
