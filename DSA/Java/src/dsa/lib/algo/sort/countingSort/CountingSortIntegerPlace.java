package dsa.lib.algo.sort.countingSort;

import dsa.lib.utils.Algorithm.Nums;

class CountingSortIntegerPlace extends CountingSortIntegerAbstract {
    private final int place;

    public CountingSortIntegerPlace(Integer[] nums, int place) {
        super(nums);
        this.place = place;
    }

    @Override
    protected void initMinMax() {
        min = 0;
        max = 9;
    }

    @Override
    protected int countsIndexOf(Integer e) {
        return Nums.placeValueOf(e, place) - min;
    }
}
