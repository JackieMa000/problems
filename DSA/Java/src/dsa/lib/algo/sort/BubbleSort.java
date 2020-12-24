package dsa.lib.algo.sort;


/**
 * 冒泡排序：
 * 一般需要进行n轮冒泡
 * 当某轮冒泡操作已经没有数据交换时，说明已经达到完全有序，不用再继续执行后续的冒泡操作
 * 第 i 轮冒泡会把第 i 大数，放置在 倒数第i位(n - 1 -i)
 * 每轮冒泡至少一个元素移动到它应该在的位置
 * <p>
 * 每轮冒泡从第一个元素开始比较，交换
 * 每轮冒泡的结束位置为 n - 1 - i
 * sorted in place
 */
public class BubbleSort {
    public static void sort(int[] ary) {
        int n = ary.length;

//        n round of bubble trip
        for (int i = 0; i < n; i++) {
//        compare and swap
            boolean swapped = false;
            for (int j = 0; j < n - 1 - i; j++) {
                if (ary[j] > ary[j + 1]) {
                    int tmp = ary[j];
                    ary[j] = ary[j + 1];
                    ary[j + 1] = tmp;
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }
}
