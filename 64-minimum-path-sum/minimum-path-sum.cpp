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

    int solveSO(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp (m, vector<int> (n,0));
        dp[m-1][n-1] = grid[m-1][n-1];
        for(int i = m-2;i>=0;i--){
            dp[i][n-1] = grid[i][n-1] + dp[i+1][n-1];
        }
        for(int j = n-2;j>=0;j--){
            dp[m-1][j] = grid[m-1][j] + dp[m-1][j+1];
        }

        for(int i = m-2;i>=0;i--){
            for(int j = n-2;j>=0;j--){
                int left = grid[i][j] + dp[i][j+1];
                int down = grid[i][j] + dp[i+1][j];
                dp[i][j] = min(left, down);
            }
        }
        return dp[0][0];
    }

    int minPathSum(vector<vector<int>>& grid) {

        int ans = solveSO(grid);
        return ans;
    }
};