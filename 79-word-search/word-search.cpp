class Solution {
public:
    bool isPossible(int i, int j, vector<vector<char>>& board, string word,
                    int index, vector<vector<bool>>& isVisited) {
        if (index == word.size() - 1) {
            return board[i][j] == word[index];
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return false;
        }
        bool ans = 0;
        if (board[i][j] == word[index]) {
            // Left
            if (i > 0 && !isVisited[i - 1][j]) {
                isVisited[i][j] = true;
                ans = ans ||
                      isPossible(i - 1, j, board, word, index + 1, isVisited);
                isVisited[i][j] = false;
            }
            // Right
            if (i < board.size() - 1 && !isVisited[i + 1][j]) {
                isVisited[i][j] = true;
                ans = ans ||
                      isPossible(i + 1, j, board, word, index + 1, isVisited);
                isVisited[i][j] = false;
            }
            // Up
            if (j > 0 && !isVisited[i][j - 1]) {
                isVisited[i][j] = true;
                ans = ans ||
                      isPossible(i, j - 1, board, word, index + 1, isVisited);
                isVisited[i][j] = false;
            }
            // Down
            if (j < board[0].size() - 1 && !isVisited[i][j + 1]) {
                isVisited[i][j] = true;
                ans = ans ||
                      isPossible(i, j + 1, board, word, index + 1, isVisited);
                isVisited[i][j] = false;
            }
        }
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> isVisited(m, vector<bool>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool ans = isPossible(i, j, board, word, 0, isVisited);
                if (ans) {
                    return true;
                }
            }
        }
        return false;
    }
};