package dsa.lib.algo.sort;

//RadixSort for String
class RadixSort1 {
    private String getArrayMax(String[] ary) {
        String max = ary[0];
        for (int i = 1; i < ary.length; i++) {
            String cur = ary[i];
            if (cur.length() > max.length()) max = cur;
        }
        return max;
    }

    void sort(String[] ary) {
        if (ary.length <= 1) return;

        String max = getArrayMax(ary);
        for (int place = max.length() - 1; place >= 0; --place) {
            new CountingSort2().sort(ary, place);
        }
    }
}
