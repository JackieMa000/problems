package dsa.lib.algo.sort;

public class BucketSort {

    private int min;
    private int max;

    public void sort(int[] ary, int length) {
        bucketSort(ary, 3);
    }

    /**
     * @param ary
     * @param capacity: expected bucket capacity
     */
    public void bucketSort(int[] ary, int capacity) {
        if (ary.length < 2) return;

        int[] result = getMinMax(ary);
        min = result[0];
        max = result[1];

        int nBuckets = (max - min + 1) / capacity + 1;
        int[][] buckets = new int[nBuckets][capacity];

//        tracking the current size of bucket
        int[] sizes = new int[nBuckets];

        scatterToBuckets(ary, capacity, buckets, sizes);
        sortBuckets(ary, buckets, sizes);
    }

    private void sortBuckets(int[] ary, int[][] buckets, int[] sizes) {
        int k = 0;
        for (int idx = 0; idx < buckets.length; ++idx) {
//            actual bucket size, how many actual elements in the bucket
            int size = sizes[idx];
            if (size == 0) continue;
            int[] bucket = buckets[idx];

            new QuickSort().sort(bucket, size);

//            copy the bucket elements into the original array
            arraycopy(bucket, 0, ary, k, size);
            k += size;
        }
    }

    private void scatterToBuckets(int[] ary, int capacity, int[][] buckets, int[] sizes) {
        for (final int cur : ary) {
            //  get the bucket index
            int idx = (cur - min) / capacity;
            int[] bucket = buckets[idx];
            final int size = sizes[idx];

            int curCapacity = bucket.length;
            if (size >= curCapacity) resize(buckets, idx, curCapacity * 2);

//            put the element into the bucket
            bucket[size] = cur;
            sizes[idx]++;
        }
    }

    /**
     * resize the bucket from the buckets collection
     *
     * @param buckets bucket collection
     * @param idx     the index of bucket to resize
     * @param n       the new size of the bucket
     */
    private void resize(int[][] buckets, int idx, int n) {
        int[] bucket = buckets[idx];
        int[] newBucket = new int[n];
        arraycopy(bucket, 0, newBucket, 0, bucket.length);
        buckets[idx] = newBucket;
    }

    private int[] getMinMax(int[] ary) {
        int min = ary[0], max = ary[0];
        for (int cur : ary) {
            if (cur < min) min = cur;
            if (cur > max) max = cur;
        }
        return new int[]{min, max};
    }

    private static void arraycopy(int[] src, int srcPos, int[] dest, int destPos, int length) {
        for (int i = 0; i < length; i++) {
            dest[destPos + i] = src[srcPos + i];
        }
    }
}
