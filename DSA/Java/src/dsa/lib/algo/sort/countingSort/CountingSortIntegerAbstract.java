package dsa.lib.algo.sort.countingSort;

import dsa.lib.utils.Arrays;

public abstract class CountingSortIntegerAbstract extends CountingSortAbstract<Integer> {
    protected CountingSortIntegerAbstract(Integer[] ary) {
        super(ary);
    }

    @Override
    public void sort() {
        if (this.size < 2) return;

        initFields();
        storeCounts();
        accumulateCounts();

        Integer[] result = new Integer[size];
        generateResult(result);

        Arrays.copy(result, 0, ary, 0, result.length);
    }
}
