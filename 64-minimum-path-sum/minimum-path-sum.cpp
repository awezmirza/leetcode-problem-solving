class Solution {
public:

    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        int m = grid.size();
        int n = grid[0].size();
        if(i == m-1 && j == n-1) return grid[i][j];
        if(i > m-1 || j > n-1) return 1000000;
        if(dp[i][j] != -1) return dp[i][j];
        int left = grid[i][j] + solve(grid, i, j+1, dp);
        int down = grid[i][j] + solve(grid, i+1, j, dp);
        return dp[i][j] = min(left,down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp (m, vector<int> (n,-1));
        int ans = solve(grid,0, 0, dp);
        return ans;
    }
};