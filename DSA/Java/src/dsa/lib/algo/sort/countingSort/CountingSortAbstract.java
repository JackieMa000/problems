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

    public void sort() {
        if (size < 2) return;

        initFields();
        storeCounts();
        accumulateCounts();
        produceSorted();
    }

    protected abstract void initMinMax();

    protected abstract int countsIndexOf(T e);

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
        for (int i = 1; i < COUNTS_SIZE; ++i) counts[i] += counts[i - 1];
    }

    private void produceSorted() {
        Object[] r = new Object[size];
        generateResult(r);
        Arrays.copy(r, 0, ary, 0, size);
    }

    protected void generateResult(Object[] res) {
        for (int i = size - 1; i >= 0; --i) {
            final T e = ary[i];
            final int ci = countsIndexOf(e);
            final int index = counts[ci] - 1;

            res[index] = e;
            --counts[ci];
        }
    }
}
