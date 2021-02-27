from typing import List


class BucketSort:

    def __init__(self, nums: List[int]) -> None:
        self.init_bucket_capacity: int = 2
        self.min = self.max = self.nums[0]
        self.nums: List[int] = nums

    def sort(self):
        """
        setMinMax

        initialize buckets.
        initialize sizes.

        scatterToBuckets.
        sortEachBucket.

        :return:
        """
        self.set_min_max()

        self.init_buckets()

        self.scatter_to_buckets()
        self.sort_each_buckets()

    def set_min_max(self):
        for num in self.nums:
            if num < self.min:
                self.min = num
            elif num > self.max:
                self.max = num

    def init_buckets(self):
        """
        initialize buckets.

        Buckets n or count. how many buckets the buckets collection can hold.

        :return:
        """
        n: int = self.get_bucket_count()
        # self.buckets = [[]] * n
        self.buckets = [[] for _ in range(n)]

    def get_bucket_count(self) -> int:
        return (self.max - self.min + 1) // self.init_bucket_capacity + 1
