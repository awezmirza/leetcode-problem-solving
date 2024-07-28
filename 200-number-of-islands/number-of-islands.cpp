class Solution {
public:

    void dfs(int i, int j, vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n) {
            return;
        }

        //  Up
        if (i > 0 && grid[i - 1][j] == '1') {
            grid[i - 1][j] = '0';
            dfs(i - 1, j, grid);
        }

        // //  Down
        if (i < m - 1 && grid[i + 1][j] == '1') {
            grid[i + 1][j] = '0';
            dfs(i + 1, j, grid);
        }

        // //  Left
        if (j > 0 && grid[i][j - 1] == '1') {
            grid[i][j - 1] = '0';
            dfs(i, j - 1, grid);
        }

        //  Right
        if (j < n - 1 && grid[i][j + 1] == '1') {
            grid[i][j + 1] = '0';
            dfs(i, j + 1, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    dfs(i, j, grid);
                    ans++;
                }
            }
        }

        return ans;
    }
};