from typing import List

from dsa.lib import utils
from dsa.lib.algo.sort.quick_sort import QuickSort


class BucketSort:

    def __init__(self, nums: List[int], capacity: int = 2) -> None:
        self.nums: List[int] = nums
        self.capacity: int = capacity

        self.min: int = 0
        self.max: int = 0
        self.bucketCount: int = 0
        self.buckets: List[List[int]] = [[]]
        self.bucketSizes: List[int] = []

    def sort(self) -> None:
        if len(self.nums) < 2: return

        self.init_fields()
        self.scatterToEachBucket()
        self.sortEachBucket()

    def init_fields(self):
        self.init_minMax()
        self.init_bucketCount()
        self.init_buckets()
        self.init_bucketSizes()

    def init_minMax(self) -> None:
        self.min = self.max = self.nums[0]
        for num in self.nums:
            if num < self.min:
                self.min = num
            elif num > self.max:
                self.max = num

    def init_bucketCount(self) -> None:
        self.bucketCount = (self.max - self.min + 1) // self.capacity + 1

    def init_buckets(self) -> None:
        self.buckets = [[] for _ in range(self.bucketCount)]

    def init_bucketSizes(self) -> None:
        self.bucketSizes = [0] * self.bucketCount

    def scatterToEachBucket(self) -> None:
        for num in self.nums:
            i: int = self.bucketIndexOf(num)
            self.buckets[i].append(num)
            self.bucketSizes[i] += 1

    def bucketIndexOf(self, num: int) -> int:
        return (num - self.min) // self.capacity

    def sortEachBucket(self) -> None:
        k: int = 0
        for bucket in self.buckets:
            self.quick_sort(bucket)
            size: int = len(bucket)
            utils.array_copy(bucket, 0, self.nums, k, size)
            k += size

    @staticmethod
    def quick_sort(nums: List[int]) -> None:
        QuickSort().sort(nums)
