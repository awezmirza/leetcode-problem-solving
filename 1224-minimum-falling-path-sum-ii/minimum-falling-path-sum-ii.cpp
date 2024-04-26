class Solution {
public:

    int solve(vector<vector<int>>& grid, int prevIdx, int row){
        int m = grid.size();
        int n = grid[0].size();

        if(row >= m){
            return 0;
        }

        int pathSum = 1000000;
        
        for(int i = 0; i < n; i++){
            if(i != prevIdx){
                pathSum = min(pathSum, grid[row][i] + solve(grid, i, row + 1));
            }
        }
        return pathSum;
    }

    int solveDP(vector<vector<int>>& grid, int prevIdx, int row, vector<vector<int>>& dp){
        int m = grid.size();
        int n = grid[0].size();

        if(row >= m){
            return 0;
        }

        if(prevIdx >= 0 && dp[row][prevIdx] != -1){
            return dp[row][prevIdx];
        }

        int pathSum = 1000000;
        
        for(int i = 0; i < n; i++){
            if(i != prevIdx){
                pathSum = min(pathSum, grid[row][i] + solveDP(grid, i, row + 1, dp));
            }
        }

        if(prevIdx >= 0){
            dp[row][prevIdx] = pathSum;
        }

        return pathSum;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp (m + 1, vector<int> (n + 1, -1));

        int ans = solveDP(grid, -10, 0, dp);
        return ans;
    }
};