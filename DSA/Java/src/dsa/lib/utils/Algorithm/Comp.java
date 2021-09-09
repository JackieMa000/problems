package dsa.lib.utils.Algorithm;

import java.util.Iterator;
import java.util.List;
import java.util.function.BiPredicate;

public class Comp {
    public static <T> T comp(T[] ary, BiPredicate<T, T> pred) {
        if (ary.length == 0) return null;
        T r = ary[0];
        for (final T e : ary) if (pred.test(e, r)) r = e;
        return r;
    }

    public static <E> List<E> compSize(List<List<E>> ls, BiPredicate<List<E>, List<E>> pred) {
        if (ls.size() == 0) return null;
        List<E> r = ls.get(0);
        for (final List<E> e : ls) if (pred.test(e, r)) r = e;
        return r;
    }

    public static <E> List<E> compSize(Iterator<List<E>> it, BiPredicate<List<E>, List<E>> pred) {
        if (!it.hasNext()) return null;

        List<E> res = it.next();
        while (it.hasNext()) {
            List<E> e = it.next();
            if (pred.test(e, res)) res = e;
        }
        return res;
    }
}
