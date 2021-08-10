package dsa.lib.algo.sort.countingSort;

//Only handles small case letters
class CountingSortString extends CountingSortAbstract<String> {
    private final int FIRST_OF_ALPHABET = 97, LAST_OF_ALPHABET = 122;
    private final int index;

    public CountingSortString(String[] ss, int index) {
        super(ss);
        this.index = index;
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
