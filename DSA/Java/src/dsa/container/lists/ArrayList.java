package dsa.container.lists;

import dsa.lib.lists.List;

public class ArrayList implements List {
    private static final int DEFAULT_LENGTH = 10;
    private final int[] lst;

    public ArrayList() {
        this.lst = new int[DEFAULT_LENGTH];
    }

    @Override
    public int size() {
        return 0;
    }
}
