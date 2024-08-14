class Solution {
public:

    bool solve(vector<vector<char>>& board, int i, int j) {
        if (i >= 9) {
            return true;
        }

        if (j >= 9) {
            return solve(board, i + 1, 0);
        }

        if (board[i][j] != '.') {
            return solve(board, i, j + 1);
        }

        int subBoxRowStart = (i / 3) * 3;
        int subBoxColStart = (j / 3) * 3;

        vector<bool> usedNums(10, false);
        for (int k = 0; k < 9; k++) {
            if (board[k][j] != '.') {
                usedNums[board[k][j] - '0'] = true;
            }
            if (board[i][k] != '.') {
                usedNums[board[i][k] - '0'] = true;
            }
        }
        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                if (board[k + subBoxRowStart][l + subBoxColStart] != '.') {
                    usedNums[board[k + subBoxRowStart][l + subBoxColStart] - '0'] = true;
                }
            }
        }

        for (int k = 1; k <= 9; k++) {
            if (!usedNums[k]) {
                board[i][j] = k + '0';
                if (solve(board, i, j + 1)) {
                    return true;
                }
                board[i][j] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};