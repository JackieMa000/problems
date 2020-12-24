import collections
import heapq


class Queue(list):

    def size(self) -> int:
        return len(self)

    def empty(self) -> bool:
        return self.size() == 0

    def push_back(self, x) -> None:
        self.append(x)

    def push(self, x) -> None:
        self.push_back(x)

    def peek(self) -> int:
        return self.front()

    def pop_front(self, index=0):
        """
        remove and return the front item from the queue
        """
        return super().pop(index)

    def pop(self, index=0):
        """
        remove and return the front item from the queue
        """
        return self.pop_front(index)

    def add(self, x) -> None:
        self.push_back(x)

    def front(self) -> int:
        return self[0]

    def fist(self) -> int:
        return self.front()

    def head(self) -> int:
        return self.front()

    def tail(self) -> int:
        return self[-1]

    def back(self) -> int:
        return self.tail()

    def last(self) -> int:
        return self.tail()


class Stack(list):

    def size(self) -> int:
        return len(self)

    def empty(self) -> bool:
        return self.size() == 0

    def push_back(self, x) -> None:
        super().append(x)

    def push_back1(self, x) -> None:
        self.push_back(x)

    def peek(self) -> int:
        return self.top()

    def add(self, x) -> None:
        self.push_back(x)

    def top(self) -> int:
        return self[-1]

    def bottom(self) -> int:
        return self[0]


class MinPriorityQueue(Queue):
    """ Min Heap """

    def push(self, x: int) -> None:
        heapq.heappush(self, x)

    def pop(self, key=None, index=0):
        return self.pop_top(key)

    def pop_top(self, key=None):
        if not key: return heapq.heappop(self)
        min_ = heapq.nsmallest(1, self, key)[0]
        self.remove(min_)
        return min_

    def peek(self, key=None) -> int:
        return self.top(key)

    def top(self, key=None) -> int:
        if not key: return self[0]
        return heapq.nsmallest(1, self, key)[0]


class MaxPriorityQueue(Queue):
    """ Max Heap """

    def push(self, x: int) -> None:
        self.push_top(x)

    def push_top(self, x: int):
        heapq.heappush(self, x)

    def pop(self, key=None, index=0):
        return self.pop_top(key)

    def pop_top(self, key=None):
        max_ = heapq.nlargest(1, self, key)[0]
        self.remove(max_)
        return max_

    def peek(self, key=None) -> int:
        return self.top(key)

    def top(self, key=None) -> int:
        return heapq.nlargest(1, self, key)[0]


class Deque(collections.deque):
    def size(self) -> int:
        return len(self)

    def empty(self) -> bool:
        return self.size() == 0

    def push(self, x) -> None:
        self.push_back(x)

    def push_back(self, x):
        self.appendleft(x)

    def push_left(self, x) -> None:
        self.push_back(x)

    def push_tail(self, x) -> None:
        self.push_back(x)

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
        return self.peek_front()

    def peek_front(self):
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
        return self.peek_back()

    def peek_back(self):
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
