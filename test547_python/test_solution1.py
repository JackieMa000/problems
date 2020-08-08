import unittest
from typing import List


class Solution:
    # Graph. DFS
    def findCircleNum(self, M: List[List[int]]) -> int:
        if not M or not M[0]: return 0

        self.m, self.n = len(M), len(M[0])
        self.visited = [0] * len(M)

        count = 0
        for person in range(self.m):
            # Find this person's all friends and add them to visited, if he's not visited.
            # At least he's friend with himself.
            # This case still can be a friend circle based the problem description.
            if not self.visited[person]:
                self.bfs(M, person)
                count += 1
        return count

    # Add all of his friends(friend circle) to visited.
    def bfs(self, M: List[List[int]], person: int) -> None:
        queue = []
        queue.append(person)
        while queue:
            person = queue.pop(0)
            self.visited[person] = 1
            # generate_related_nodes
            for other in range(self.n):
                if M[person][other] == 1 and not self.visited[other]:
                    queue.append(other)

    # Friend Circle: A -> B -> C
    # Add all of his friends(friend circle) to visited.
    def dfs(self, M: List[List[int]], person: int) -> None:
        for other in range(self.n):
            if M[person][other] == 1 and not self.visited[other]:
                # We found an unvisited person in the current friend cycle
                self.visited[other] = 1
                self.dfs(M, other)  # Start DFS on this new found person


class MyTestCase(unittest.TestCase):
    def test_something(self):
        matrix = [[1, 1, 0, 0, 1],
                  [1, 1, 0, 0, 0],
                  [0, 0, 1, 1, 0],
                  [0, 0, 1, 1, 0],
                  [1, 0, 0, 0, 1]]
        self.assertEqual(2, Solution().findCircleNum(matrix))
        matrix = [[1, 1, 0],
                  [1, 1, 0],
                  [0, 0, 1]]
        self.assertEqual(2, Solution().findCircleNum(matrix))
        matrix = [[1, 1, 0],
                  [1, 1, 1],
                  [0, 1, 1]]
        self.assertEqual(1, Solution().findCircleNum(matrix))


if __name__ == '__main__':
    unittest.main()
