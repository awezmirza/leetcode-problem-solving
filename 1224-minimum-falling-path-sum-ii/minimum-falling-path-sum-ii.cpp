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

    int solveTab(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp (m + 1, vector<int> (n + 1, 0));

        for(int j = 0; j < n; j++){
            dp[m - 1][j] = grid[m - 1][j];
        }

        for(int i = m - 2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                int minSumTillNow = 1000000;
                for(int k = 0; k < n; k++){
                    if(k != j){
                        minSumTillNow = min(minSumTillNow, grid[i][j] + dp[i + 1][k]);
                    }
                    dp[i][j] = minSumTillNow;
                }
            }
        }

        int ans = 100000000;

        for(int i = 0; i < n; i++){
            ans = min(ans, dp[0][i]);
        }

        return ans;
    }

    int solveTabSO(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        vector<int> nextDP (n);

        for(int j = 0; j < n; j++){
            nextDP[j] = grid[m - 1][j];
        }

        for(int i = m - 2; i >= 0; i--){
            vector<int> currDP (n);
            for(int j = 0; j < n; j++){

                int minSumTillNow = 1000000;

                for(int k = 0; k < n; k++){
                    if(k != j){
                        minSumTillNow = min(minSumTillNow, grid[i][j] + nextDP[k]);
                    }
                    currDP[j] = minSumTillNow;
                }
            }
            nextDP = currDP;
        }

        int ans = 100000000;

        for(int i = 0; i < n; i++){
            ans = min(ans, nextDP[i]);
        }

        return ans;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans = solveTabSO(grid);
        return ans;
    }
};