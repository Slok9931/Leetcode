class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, false));
        return solve(board, 0);
    }

    int solve(vector<vector<bool>>& board, int row) {
        int n = board.size();
        if (row == n) return 1;

        int count = 0;
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col)) {
                board[row][col] = true;
                count += solve(board, row + 1);
                board[row][col] = false;
            }
        }
        return count;
    }

    bool isSafe(vector<vector<bool>>& board, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i][col]) return false;
        }

        for (int i = 1; i <= min(row, col); i++) {
            if (board[row - i][col - i]) return false;
        }

        for (int i = 1; i <= min(row, (int)board.size() - 1 - col); i++) {
            if (board[row - i][col + i]) return false;
        }

        return true;
    }
};
