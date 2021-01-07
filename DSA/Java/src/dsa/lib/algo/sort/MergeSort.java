package dsa.lib.algo.sort;

/**
 * A = A[p..r]
 * A1 = A[p..q]
 * A2 = A[q+1..r]
 */
public class MergeSort {
    public void sort(int[] ary, int n) {
        split(ary, 0, n - 1);
    }

    private void split(int[] ary, int p, int r) {
        if (p >= r) return;

        int q = p + (r - p) / 2;
        split(ary, p, q);
        split(ary, q + 1, r);

        // 将A1和A2合并为A
        merge(ary, p, q, r);
    }

    /*
     * 我们申请一个临时数组 tmp，大小与 A相同。我们用两个游标 i 和 j，分别指向 A1和 A2的第一个元素。
     * 比较这两个元素 A[i]和 A[j]，如果 A[i]<=A[j]，我们就把 A[i]放入到临时数组 tmp，并且 i 后移一位，
     * 否则将 A[j]放入到数组 tmp，j 后移一位。
     * 继续上述比较过程，直到其中一个子数组中的所有数据都放入临时数组tmp中，再把另一个数组中的数据依次加入到临时数组tmp的末尾(
     * 判断哪个子数组中有剩余的数据, 将剩余的数据拷贝到临时数组tmp)
     * 将tmp中的数组拷贝回A
     * A1 or A2 leftover(tmp is not fully filled):
     *   A1 and A2 leftover:
     *   A1 leftover:
     *   A2 leftover:
     */
    private void merge(int[] ary, int p, int q, int r) {
        final int n = r - p + 1;

//        generate data for tmp
        int[] tmp = new int[n];
        for (int i = p, j = q + 1, k = 0; k < n; ++k) {
//        for (int i = p, j = q + 1, k = 0; i <= q || j <= r; ++k) {
            if (i <= q && j <= r) {
                if (ary[i] <= ary[j]) {
                    tmp[k] = ary[i++];
                } else {
                    tmp[k] = ary[j++];
                }
            } else if (i <= q) {
                tmp[k] = ary[i++];
            } else {
                tmp[k] = ary[j++];
            }
        }

        // 将tmp中的数组拷贝回A
        arraycopy(tmp, 0, ary, p, n);
    }

    private static void arraycopy(int[] src, int srcPos, int[] dest, int destPos, int length) {
        for (int i = 0; i < length; i++) {
            dest[destPos + i] = src[srcPos + i];
        }
    }
}
