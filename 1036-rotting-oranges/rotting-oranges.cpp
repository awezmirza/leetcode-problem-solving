class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int totalFresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    totalFresh++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int minutes = 0;

        while (totalFresh > 0 && !q.empty()) {
            int size = q.size();
            minutes++;
            for (int i = 0; i < size; i++) {

                int frRow = q.front().first;
                int frCol = q.front().second;
                q.pop();
                // Up
                if (frRow - 1 >= 0 && grid[frRow - 1][frCol] == 1) {
                    grid[frRow - 1][frCol] = 2;
                    q.push({frRow - 1, frCol});
                    totalFresh--;
                }

                // Down
                if (frRow + 1 <= m - 1 && grid[frRow + 1][frCol] == 1) {
                    grid[frRow + 1][frCol] = 2;
                    q.push({frRow + 1, frCol});
                    totalFresh--;
                }

                // Left
                if (frCol - 1 >= 0 && grid[frRow][frCol - 1] == 1) {
                    grid[frRow][frCol - 1] = 2;
                    q.push({frRow, frCol - 1});
                    totalFresh--;
                }

                // Right
                if (frCol + 1 <= n - 1 && grid[frRow][frCol + 1] == 1) {
                    grid[frRow][frCol + 1] = 2;
                    q.push({frRow, frCol + 1});
                    totalFresh--;
                }
            }
        }

        if (totalFresh != 0) {
            return -1;
        }
        return minutes;
    }
};