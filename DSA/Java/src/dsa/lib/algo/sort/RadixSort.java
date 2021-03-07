package dsa.lib.algo.sort;

class RadixSort {
    private int getArrayMax(int[] ary) {
        int max = ary[0];
        for (int i = 1; i < ary.length; i++)
            if (ary[i] > max) max = ary[i];
        return max;
    }

    void sort(int[] ary) {
        if (ary.length <= 1) return;

        int max = getArrayMax(ary);
        for (int place = 1; max / place > 0; place *= 10) {
            new CountingSort1().sort(ary, place);
        }
    }
}
