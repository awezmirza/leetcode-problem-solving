class Solution {
public:

    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        int m = grid2.size();
        int n = grid2[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] != 1) {
            return true;
        }
        if (grid2[i][j] != grid1[i][j]) {
            return false;
        }
        grid2[i][j] = 2;
        vector<vector<int>> dirn = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        bool toReturn = true;
        for (auto dir : dirn) {
            toReturn = dfs(grid1, grid2, i + dir[0], j + dir[1]) && toReturn;
        }
        return toReturn;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        int m = grid2.size();
        int n = grid2[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1) {
                    if (dfs(grid1, grid2, i, j)) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};