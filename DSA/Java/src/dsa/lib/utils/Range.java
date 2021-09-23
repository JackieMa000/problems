package dsa.lib.utils;

import java.util.*;
import java.util.function.BiPredicate;

public class Range {

    // strip

    public static int[] lstripIt(int[] nums) {
        int i = 0;
        while (i < nums.length && nums[i] == 0) ++i;
        return i == 0 ? nums : Arrays.copyOfRange(nums, i, nums.length);
    }

    public static int[] lstripDfs(int[] nums) {
        if (nums.length == 0) return nums;
        return nums[0] != 0 ? nums : lstripDfs(Arrays.copyOfRange(nums, 1, nums.length));
    }

    public static int[] rstripIt(int[] nums) {
        int n = nums.length, i = n;
        while (i > 0 && nums[i - 1] == 0) --i;
        return i == n ? nums : Arrays.copyOfRange(nums, 0, i);
    }

    public static int[] rstripDfs(int[] nums) {
        final int n = nums.length;
        if (n == 0) return nums;
        return nums[n - 1] != 0 ? nums : rstripDfs(Arrays.copyOf(nums, n - 1));
    }

    public static int[] stripIt(int[] nums) {
        int n = nums.length;

        int i = 0, j = n;
        while (i < j && nums[i] == 0) ++i;
        while (i < j && nums[j - 1] == 0) --j;
        return i == 0 && j == n ? nums : Arrays.copyOfRange(nums, i, j);
    }

    public static int[] stripDfs(int[] nums) {
        int n = nums.length;
        if (n == 0) return nums;

        final boolean isFirst0 = nums[0] == 0;
        final boolean isLast0 = nums[n - 1] == 0;
        int i = isFirst0 ? 1 : 0;
        int j = (isLast0 && n > 1) ? n - 1 : n;
        return (!isFirst0 && !isLast0) ? nums : stripDfs(Arrays.copyOfRange(nums, i, j));
    }

    /**
     * Remove all the leading 0s from the given array
     */
    public static int[] lstrip(int[] nums) {
        return lstripIt(nums);
    }

    /**
     * Remove all the trailing 0s from the given array
     */
    public static int[] rstrip(int[] nums) {
        return rstripIt(nums);
    }

    /**
     * Remove all the leading and trailing 0s from the given array
     */
    public static int[] strip(int[] nums) {
        return stripIt(nums);
    }

    /**
     * Remove all the leading and trailing 0s from the given array
     */
    public static int[] trim(int[] nums) {
        return strip(nums);
    }


    // swap

    /**
     * Swap 2 elements of an array.
     *
     * @param nums The array.
     * @param i    The position of 1st element.
     * @param j    The position of 2nd element.
     */
    public static void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    public static <E> void swap(E[] ary, int i, int j) {
        E tmp = ary[i];
        ary[i] = ary[j];
        ary[j] = tmp;
    }

    public static <E> void swap(List<E> ls, int i, int j) {
        E tmp = ls.get(i);
        ls.set(i, ls.get(j));
        ls.set(j, tmp);
    }

    // copy

    /**
     * copy from primitive int array to primitive int array
     */
    public static void copy(int[] src, int srcPos, int[] des, int desPos, int n) {
        for (int i = 0; i < n; ++i) des[desPos + i] = src[srcPos + i];
    }

    /**
     * copy from array to array
     */
    public static <T> void copy(T[] src, int srcPos, T[] des, int desPos, int n) {
        for (int i = 0; i < n; ++i) des[desPos + i] = src[srcPos + i];
    }

    /**
     * copy from Integer wrapper array to primitive int array.
     */
    public static void copy(Integer[] src, int srcPos, int[] des, int desPos, int n) {
        for (int i = 0; i < n; ++i) des[desPos + i] = src[srcPos + i];
    }

    /**
     * copy from primitive int array to Integer wrapper array.
     */
    public static void copy(int[] src, int srcPos, Integer[] des, int desPos, int n) {
        for (int i = 0; i < n; ++i) des[desPos + i] = src[srcPos + i];
    }

    /**
     * copy from list to list.
     */
    public static <T> void copy(List<T> src, int srcPos, List<T> des, int desPos, int n) {
        for (int i = 0; i < n; ++i) des.set(desPos + i, src.get(srcPos + i));
    }

    /**
     * copy from list to array.
     */
    public static <T> void copy(List<T> src, int srcPos, T[] des, int desPos, int n) {
        for (int i = 0; i < n; ++i) des[desPos + i] = src.get(srcPos + i);
    }

    /**
     * copy from array to list.
     */
    public static <T> void copy(T[] src, int srcPos, List<T> des, int desPos, int n) {
        for (int i = 0; i < n; ++i) des.set(desPos + i, src[srcPos + i]);
    }

    // fill

    public static void fill(int[] nums, int v) {
        for (int i = 0; i < nums.length; ++i) nums[i] = v;
    }

    public static <E> void fill(E[] ary, E v) {
        for (int i = 0; i < ary.length; ++i) ary[i] = v;
    }

    public static <E> void fill(List<E> ls, E v) {
        for (int i = 0; i < ls.size(); ++i) ls.set(i, v);
    }

    // comp
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

    // max

    public static <T> T max(T[] ary, Comparator<T> comp) {
        return comp(ary, (x, y) -> comp.compare(x, y) > 0);
    }

    public static int max(int[] nums) {
        Integer r = max(integerValueOf(nums), Integer::compareTo);
        Objects.requireNonNull(r);
        return r;
    }

    public static Integer max(Integer[] nums) {
        return max(nums, Integer::compareTo);
    }

    public static String max(String[] ss) {
        return max(ss, String::compareTo);
    }

    public static String maxSize(String[] ss) {
        return max(ss, Comparator.comparingInt(String::length));
    }

    public static <E> E[] maxSize(E[][] ary) {
        return max(ary, Comparator.comparingInt(e -> e.length));
    }

    public static <E> List<E> maxSize(List<List<E>> ls, Comparator<List<E>> comp) {
        return compSize(ls, (x, y) -> comp.compare(x, y) > 0);
    }

    public static <E> List<E> maxSize(List<List<E>> ls) {
        return maxSize(ls, Comparator.comparingInt(List::size));
    }

    public static <E> List<E> maxSize(Iterator<List<E>> it, Comparator<List<E>> comp) {
        return compSize(it, (x, y) -> comp.compare(x, y) > 0);
    }

    public static <E> List<E> maxSize(Iterator<List<E>> it) {
        return maxSize(it, Comparator.comparingInt(List::size));
    }

    // min

    public static <T> T min(T[] ary, Comparator<T> comp) {
        return comp(ary, (x, y) -> comp.compare(x, y) < 0);
    }

    public static int min(int[] nums) {
        Integer r = min(integerValueOf(nums), Integer::compareTo);
        Objects.requireNonNull(r);
        return r;
    }

    public static Integer min(Integer[] nums) {
        return min(nums, Integer::compareTo);
    }

    public static String min(String[] ss) {
        return min(ss, String::compareTo);
    }

    public static String minSize(String[] ss) {
        return min(ss, Comparator.comparingInt(String::length));
    }

    public static <E> E[] minSize(E[][] ary) {
        return min(ary, Comparator.comparingInt(e -> e.length));
    }

    public static <E> List<E> minSize(List<List<E>> ls, Comparator<List<E>> comp) {
        return compSize(ls, (x, y) -> comp.compare(x, y) < 0);
    }

    public static <E> List<E> minSize(List<List<E>> lists) {
        return minSize(lists, Comparator.comparingInt(List::size));
    }

    public static <E> List<E> minSize(Iterator<List<E>> it, Comparator<List<E>> comp) {
        return compSize(it, (x, y) -> comp.compare(x, y) < 0);
    }

    public static <E> List<E> minSize(Iterator<List<E>> it) {
        return minSize(it, Comparator.comparingInt(List::size));
    }

    public static Integer[] integerValueOf(int[] nums) {
        Integer[] r = new Integer[nums.length];
        copy(nums, 0, r, 0, nums.length);
        return r;
    }

    public static int[] intValueOf(Integer[] nums) {
        int[] r = new int[nums.length];
        copy(nums, 0, r, 0, nums.length);
        return r;
    }

}
