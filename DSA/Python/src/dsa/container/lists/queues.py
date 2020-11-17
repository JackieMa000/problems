import collections
import heapq


class Queue(list):

    def size(self) -> int:
        return len(self)

    def empty(self) -> bool:
        return self.size() == 0

    def push(self, x) -> None:
        self.append(x)

    def peek(self) -> int:
        return self[0]

    def pop(self, index=0):
        """
        remove and return the front item from the queue
        """
        return super().pop(index)

    def add(self, x) -> None:
        self.push(x)

    def front(self) -> int:
        return self.peek()

    def fist(self) -> int:
        return self.peek()

    def head(self) -> int:
        return self.peek()

    def back(self) -> int:
        return self[-1]

    def last(self) -> int:
        return self[-1]

    def tail(self) -> int:
        return self[-1]


class Stack(list):

    def size(self) -> int:
        return len(self)

    def empty(self) -> bool:
        return self.size() == 0

    def push(self, x) -> None:
        super().append(x)

    def peek(self) -> int:
        return self[-1]

    def add(self, item) -> None:
        self.push(item)

    def top(self) -> int:
        return self.peek()

    def bottom(self) -> int:
        return self[0]


class MinPriorityQueue(Queue):
    """ Min Heap """

    def push(self, x: int) -> None:
        heapq.heappush(self, x)

    def pop(self, key=None, index=0):
        if not key: return heapq.heappop(self)
        min_ = heapq.nsmallest(1, self, key)[0]
        self.remove(min_)
        return min_

    def peek(self, key=None) -> int:
        if not key: return self[0]
        return heapq.nsmallest(1, self, key)[0]

    def top(self, key=None) -> int:
        return self.peek(key)


class MaxPriorityQueue(Queue):
    """ Max Heap """

    def push(self, x: int) -> None:
        heapq.heappush(self, x)

    def pop(self, key=None, index=0):
        max_ = heapq.nlargest(1, self, key)[0]
        self.remove(max_)
        return max_

    def peek(self, key=None) -> int:
        return heapq.nlargest(1, self, key)[0]

    def top(self, key=None) -> int:
        return self.peek(key)


class Deque(collections.deque):
    def size(self) -> int:
        return len(self)

    def empty(self) -> bool:
        return self.size() == 0

    def push(self, x) -> None:
        self.appendleft(x)

    def pushleft(self, x) -> None:
        self.push(x)

    def pushback(self, x) -> None:
        self.push(x)

    def pushtail(self, x) -> None:
        self.push(x)

    def pushright(self, x) -> None:
        self.append(x)

    def pushfront(self, x) -> None:
        self.append(x)

    def pushhead(self, x) -> None:
        self.append(x)

    def popright(self):
        return self.pop()

    def popfirst(self):
        return self.pop()

    def popfront(self):
        return self.pop()

    def pophead(self):
        return self.pop()

    def poplast(self):
        return self.popleft()

    def popback(self):
        return self.popleft()

    def poptail(self):
        return self.popleft()

    def peek(self):
        return self[-1]

    def peekright(self):
        return self.peek()

    def peekfirst(self):
        return self.peek()

    def peekfront(self):
        return self.peek()

    def peekhead(self):
        return self.peek()

    def front(self):
        return self.peek()

    def first(self):
        return self.peek()

    def head(self):
        return self.peek()

    def peekleft(self):
        return self[0]

    def peeklast(self):
        return self.peekleft()

    def peekback(self):
        return self.peekleft()

    def peektail(self):
        return self.peekleft()

    def back(self):
        return self.peekleft()

    def last(self):
        return self.peekleft()

    def tail(self):
        return self.peekleft()
