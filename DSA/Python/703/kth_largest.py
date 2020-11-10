import heapq


# class KthLargest:
#     def __init__(self, k: int, nums: list):
#         self.pool = heapq.nlargest(k, nums)[::-1]
#         self.k = k
#
#     def add(self, val: int) -> int:
#         if len(self.pool) < self.k:
#             heapq.heappush(self.pool, val)
#         elif val > self.pool[0]:
#             heapq.heapreplace(self.pool, val)
#         return self.pool[0]


class KthLargest:
    def __init__(self, k: int, nums: list):
        self.pool = heapq.nlargest(k, nums)
        heapq.heapify(self.pool)
        self.k = k

    def add(self, val: int) -> int:
        if len(self.pool) < self.k:
            heapq.heappush(self.pool, val)
        else:
            heapq.heappushpop(self.pool, val)
        return self.pool[0]
