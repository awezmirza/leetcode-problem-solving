class Solution {
    int helper(vector<vector<int>>& obstacleGrid, int x, int y, vector<vector<int>>& dp){
        int maxX = obstacleGrid.size();
        int maxY = obstacleGrid[0].size();
        if(x >= maxX || y>= maxY || obstacleGrid[x][y] == 1)
            return 0;
        if(x == maxX-1 && y == maxY - 1) 
            return 1;
        if(dp[x][y] != -1)
            return dp[x][y];
        int down = helper(obstacleGrid, x , y + 1, dp);
        int left = helper(obstacleGrid, x + 1 , y, dp);
        return dp[x][y] = down + left;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int> (obstacleGrid[0].size(), -1));
        int ans = helper(obstacleGrid, 0 , 0, dp);
        return ans;
    }
};