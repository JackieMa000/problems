package dsa.lib.algo.sort.countingSort;

import dsa.lib.utils.Arrays;

//Only handles small case letters
class CountingSortString extends CountingSortAbstract<String> {
    private final int FIRST_OF_ALPHABET = 97, LAST_OF_ALPHABET = 122;
    private final int index;

    public CountingSortString(String[] ary, int index) {
        super(ary);
        this.index = index;
    }

    @Override
    public void sort() {
        if (size < 2) return;

        initFields();
        storeCounts();
        accumulateCounts();

        String[] result = new String[size];
        generateResult(result);

        Arrays.copy(result, 0, ary, 0, size);
    }

    @Override
    protected void initMinMax() {
        min = FIRST_OF_ALPHABET;
        max = LAST_OF_ALPHABET;
    }

    @Override
    protected int countsIndexOf(String e) {
        return getCharFrom(e) - min;
    }

    private char getCharFrom(String s) {
        final int lastIndex = s.length() - 1;
        return index > lastIndex ? s.charAt(lastIndex) : s.charAt(index);
    }
}
