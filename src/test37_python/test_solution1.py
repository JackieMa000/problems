import unittest
from typing import List


# Clean DFS
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # check args
        # solve it
        if not board or not board[0]: return
        self.m, self.n = len(board), len(board[0])
        self.solveDFS(board, 0, 0)

    def solveDFS(self, board: List[List[str]], i: int, j: int) -> bool:
        # Terminator
        if i == self.m: return True

        # Recursive
        if j == self.n: return self.solveDFS(board, i + 1, 0)
        if board[i][j] != '.': return self.solveDFS(board, i, j + 1)
        # fill in the board
        # loop 1~9
        for c in range(1, 10):
            # check valid
            if self.is_valid(board, i, j, str(c)):
                board[i][j] = str(c)
                # Recursive
                if self.solveDFS(board, i, j + 1): return True
                # Revert state
                board[i][j] = '.'
        return False

    def is_valid(self, board: List[List[str]], row: int, col: int, c: str) -> bool:
        for i in range(9):
            # check row
            if board[i][col] == c: return False
            # check column
            if board[row][i] == c: return False
            # check block
            if board[3 * (row // 3) + i // 3][3 * (col // 3) + i % 3] == c: return False
        return True


class MyTestCase(unittest.TestCase):
    def test_something(self):
        input = [["5", "3", ".", ".", "7", ".", ".", ".", "."], ["6", ".", ".", "1", "9", "5", ".", ".", "."],
                 [".", "9", "8", ".", ".", ".", ".", "6", "."], ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
                 ["4", ".", ".", "8", ".", "3", ".", ".", "1"], ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
                 [".", "6", ".", ".", ".", ".", "2", "8", "."], [".", ".", ".", "4", "1", "9", ".", ".", "5"],
                 [".", ".", ".", ".", "8", ".", ".", "7", "9"]]
        expected = [["5", "3", "4", "6", "7", "8", "9", "1", "2"], ["6", "7", "2", "1", "9", "5", "3", "4", "8"],
                    ["1", "9", "8", "3", "4", "2", "5", "6", "7"], ["8", "5", "9", "7", "6", "1", "4", "2", "3"],
                    ["4", "2", "6", "8", "5", "3", "7", "9", "1"], ["7", "1", "3", "9", "2", "4", "8", "5", "6"],
                    ["9", "6", "1", "5", "3", "7", "2", "8", "4"], ["2", "8", "7", "4", "1", "9", "6", "3", "5"],
                    ["3", "4", "5", "2", "8", "6", "1", "7", "9"]]
        Solution().solveSudoku(input)
        self.assertEqual(expected, input)
