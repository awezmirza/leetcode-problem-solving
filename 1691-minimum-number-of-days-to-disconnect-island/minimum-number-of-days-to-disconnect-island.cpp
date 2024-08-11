class Solution {
public:
 
    void dfs(vector<vector<int>>& grid, int i, int j) {
        grid[i][j] = 0;
        // Down 
        if (i < grid.size() - 1 && grid[i + 1][j] == 1) {
            dfs(grid, i + 1, j);
        }
        // Right
        if (j < grid[0].size() - 1 && grid[i][j + 1] == 1) {
            dfs(grid, i, j + 1);
        }
        // Left
        if (j > 0 && grid[i][j - 1] == 1) {
            dfs(grid, i, j - 1);
        }

        // Up 
        if (i > 0 && grid[i - 1][j] == 1) {
            dfs(grid, i - 1, j);
        }
    }

    int findNumOfIsland(vector<vector<int>> grid) {
        int m = grid.size();
        int n = grid[0].size();
        int num = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                    num++;
                }
            }
        }

        return num;
    }

    int minDays(vector<vector<int>>& grid) {
        int numOfIslands = findNumOfIsland(grid);
        if (numOfIslands != 1) {
            return 0;
        }

        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    int islands = findNumOfIsland(grid);
                    if (islands != 1) {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};