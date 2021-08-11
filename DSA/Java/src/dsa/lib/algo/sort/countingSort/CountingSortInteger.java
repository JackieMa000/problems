package dsa.lib.algo.sort.countingSort;

class CountingSortInteger extends CountingSortIntegerAbstract {

    public CountingSortInteger(Integer[] nums) {
        super(nums);
    }

    @Override
    protected void initMinMax() {
        if (this.size == 0) return;

        min = max = this.ary[0];
        for (final int num : ary) {
            if (num < min) min = num;
            else if (num > max) max = num;
        }
    }

    @Override
    protected int countsIndexOf(Integer e) {
        return e - min;
    }
}
