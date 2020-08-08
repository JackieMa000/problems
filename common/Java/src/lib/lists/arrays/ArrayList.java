package lib.lists.arrays;

import lib.lists.List;

public class ArrayList implements List {
    private static final int DEFAULT_LENGTH = 10;
    private final int[] lst;

    public ArrayList() {
        this.lst = new int[DEFAULT_LENGTH];
    }

    public ArrayList(int[] array) {
        this.lst = array;
    }

    @Override
    public int size() {
        return 0;
    }
}
