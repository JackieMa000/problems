package solveSudoku;


class Solution1 {

    private int m;
    private int n;

    public void solveSudoku(char[][] board) {
        if (board.length == 0 || board[0].length == 0) return;
        m = board.length;
        n = board[0].length;
        solveDFS(board, 0, 0);
    }

    private boolean solveDFS(char[][] board, int i, int j) {
        // terminator
        if (i == m) return true;

        //recursive case
        if (j == n) return solveDFS(board, i + 1, 0);
        if (board[i][j] != '.') return solveDFS(board, i, j + 1);

        //fill in the board
        // loop 1~9
        for (char c = '1'; c <= '9'; c++) {
            // check valid
            if (isValid(board, i, j, c)) {
                // Drill Down
                board[i][j] = c;
                if (solveDFS(board, i, j + 1)) return true;
                //Revert State
                board[i][j] = '.';
            }
        }
        return false;
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
