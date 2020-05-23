class UnionFind:
    def __init__(self, n):
        self.count = n
        # Initialize the UnionFind by defining the parents are themselves
        self.parents = [i for i in range(n)]
        # The rank for everyone, every cycle.
        self.rank = [0] * n

    def find_root(self, node: int) -> int:
        if self.parents[node] != node:
            self.parents[node] = self.find_root(self.parents[node])

        return self.parents[node]

    def union(self, node_x: int, node_y: int):
        # find root
        rootx = self.find_root(node_x)
        rooty = self.find_root(node_y)

        # take the edge case
        if rootx == rooty: return

        # compare rank and union
        # recaculate the rank value and count value
        if self.rank[rootx] == self.rank[rooty]:
            self.parents[rootx] = rooty
            self.rank[rooty] += 1
        elif self.rank[rootx] < self.rank[rooty]:
            self.parents[rootx] = rooty
        else:
            self.parents[rooty] = rootx

        self.count -= 1
