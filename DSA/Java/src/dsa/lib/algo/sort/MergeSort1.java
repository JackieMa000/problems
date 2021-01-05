package dsa.lib.algo.sort;

public class MergeSort1 {
    public void sort(int[] ary, int n) {
        split(ary, 0, n - 1);
    }

    private void split(int[] ary, int p, int r) {
        // 递归终止条件
        if (p >= r) return;

        // 取p到r之间的中间位置q
        int q = p + (r - p) / 2;

        // 分治递归
        split(ary, p, q);
        split(ary, q + 1, r);

        // 将A[p...q]和A[q+1...r]合并为A[p...r]
        merge(ary, p, q, r);
    }

    /**
     * A = A[p..r]
     * A1 = A[p..q]
     * A2 = A[q+1..r]
     * 我们申请一个临时数组 tmp，大小与 A相同。我们用两个游标 i 和 j，分别指向 A1和 A2的第一个元素。
     * 比较这两个元素 A[i]和 A[j]，如果 A[i]<=A[j]，我们就把 A[i]放入到临时数组 tmp，并且 i 后移一位，
     * 否则将 A[j]放入到数组 tmp，j 后移一位。
     * 继续上述比较过程，直到其中一个子数组中的所有数据都放入临时数组tmp中，再把另一个数组中的数据依次加入到临时数组tmp的末尾，
     */
    private void merge(int[] ary, int p, int q, int r) {
        // 初始化变量i, j, k
        int i = p;
        int j = q + 1;
        int k = 0;

        // 申请一个大小跟A[p...r]一样的临时数组
        int[] tmp = new int[r - p + 1];

        while (i <= q && j <= r) {
            if (ary[i] <= ary[j]) {
                tmp[k++] = ary[i++];
            } else {
                tmp[k++] = ary[j++];
            }
        }
        // 判断哪个子数组中有剩余的数据
//        Assume A1 is left over.
        int start = i, end = q;
//        check if A2 is left over
        if (j <= r) {
            start = j;
            end = r;
        }
        // 将剩余的数据拷贝到临时数组tmp
        while (start <= end) {
            tmp[k++] = ary[start++];
        }

        // 将tmp中的数组拷贝回A[p...r]
        for (i = 0; i <= r - p; i++) {
            ary[p + i] = tmp[i];
        }
    }
}
