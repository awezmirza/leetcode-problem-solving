class Solution {
public:

    void dfs(vector<vector<char>>& board, int i, int j) {
        int m = board.size();
        int n = board[0].size();
        if (i >= m || j >= n || i < 0 || j < 0 || board[i][j] != 'O') {
            return;
        }
        if (board[i][j] == 'X') {
            return;
        }
        board[i][j] = 'F';
        vector<vector<int>> dirn = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
        for (auto dir : dirn) {
            dfs(board, i + dir[0], j + dir[1]);
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                dfs(board, 0, j);
            }
            if (board[m - 1][j] == 'O') {
                dfs(board, m - 1, j);
            }
        }

        for (int i = 1; i < m - 1; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (board[i][n - 1] == 'O') {
                dfs(board, i, n - 1);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != 'F') {
                    board[i][j] = 'X';
                } else {
                    board[i][j] = 'O';
                }
            }
        }
    }
};