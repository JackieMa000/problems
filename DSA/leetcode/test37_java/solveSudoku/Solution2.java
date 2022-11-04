package solveSudoku;

// Solve the whole board again after filling in a number.
public class Solution2 {

    public void solveSudoku(char[][] board) {
        if (board.length == 0 || board[0].length == 0) return;
        solve(board);
    }

    private boolean solve(char[][] board) {
        int m = board.length;
        int n = board[0].length;
        //loop board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // fill in the board
                if (board[i][j] == '.') {
                    // loop 1~9
                    for (char c = '1'; c <= '9'; c++) {
                        // check valid
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            // Recursive case.
                            if (solve(board)) return true;
                            // Otherwise Rever state
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    private boolean isValid(char[][] board, int row, int col, char c) {
        for (int k = 0; k < 9; k++) {
            // check row
            if (board[k][col] == c) return false;
            // check col
            if (board[row][k] == c) return false;
            // check block
            if (board[3 * (row / 3) + k / 3][3 * (col / 3) + k % 3] == c) return false;
        }
        return true;
    }
}
