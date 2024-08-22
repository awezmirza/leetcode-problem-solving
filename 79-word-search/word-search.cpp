class Solution {
public:
    bool findAns(vector<vector<char>>& board, string word, int i, int j, int idx) {
        if (idx >= word.size()) {
            return true;
        }
        int m = board.size();
        int n = board[0].size();

        // Down
        if (i < m - 1 && board[i + 1][j] == word[idx]) {
            char temp = board[i + 1][j];
            board[i + 1][j] = '_';
            if (findAns(board, word, i + 1, j, idx + 1)) {
                return true;
            }
            board[i + 1][j] = temp;
        }

        // Left
        if (j > 0 && board[i][j - 1] == word[idx]) {
            char temp = board[i][j - 1];
            board[i][j - 1] = '_';
            if (findAns(board, word, i, j - 1, idx + 1)) {
                return true;
            }
            board[i][j - 1] = temp;
        }

        // Right
        if (j < n - 1 && board[i][j + 1] == word[idx]) {
            char temp = board[i][j + 1];
            board[i][j + 1] = '_';
            if (findAns(board, word, i, j + 1, idx + 1)) {
                return true;
            }
            board[i][j + 1] = temp;
        }

        // Up
        if (i > 0 && board[i - 1][j] == word[idx]) {
            char temp = board[i - 1][j];
            board[i - 1][j] = '_';
            if (findAns(board, word, i - 1, j, idx + 1)) {
                return true;
            }
            board[i - 1][j] = temp;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    char temp = board[i][j];
                    board[i][j] = '_';
                    if (findAns(board, word, i, j, 1)) {
                        return true;
                    }
                    board[i][j] = temp;
                }
            }
        }
        return false;
    }
};