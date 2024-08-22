class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> newBoard(m, vector<int> (n, 0));
        vector<vector<int>> dirn = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int neighbors = 0;
                for (auto dir : dirn) {
                    int row = i + dir[0];
                    int col = j + dir[1];
                    if (row >= 0 && row < m && col >= 0 && col < n) {
                        if (board[row][col] == 1) {
                            neighbors++;
                        }
                    }
                }
                if (board[i][j] == 0) {
                    if (neighbors == 3) {                        
                        newBoard[i][j] = 1;
                    }
                } else {
                    if (neighbors == 2 || neighbors == 3) {
                        newBoard[i][j] = 1;
                    }
                }
            }
        }
        board = newBoard;
    }
};