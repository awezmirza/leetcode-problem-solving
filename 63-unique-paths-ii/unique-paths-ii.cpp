class Solution {
    // int helper(vector<vector<int>>& obstacleGrid, int x, int y, vector<vector<int>>& dp){
    //     int maxX = obstacleGrid.size();
    //     int maxY = obstacleGrid[0].size();
    //     if(x >= maxX || y>= maxY || obstacleGrid[x][y] == 1)
    //         return 0;
    //     if(x == maxX-1 && y == maxY - 1) 
    //         return 1;
    //     if(dp[x][y] != -1)
    //         return dp[x][y];
    //     int down = helper(obstacleGrid, x , y + 1, dp);
    //     int left = helper(obstacleGrid, x + 1 , y, dp);
    //     return dp[x][y] = down + left;
    // }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int maxX = obstacleGrid.size();
        int maxY = obstacleGrid[0].size();
        vector<int> dp(maxY, 0);
        for(int i = maxY-1;i>=0;i--){
            if(obstacleGrid[maxX-1][i] == 1) break;
            dp[i] = 1;
        }
        for(int i = maxX-2;i>=0;i--){
            vector<int> curr(maxY,0);
            if(obstacleGrid[i][maxY-1] == 0 && dp[maxY-1] != 0) curr[maxY-1] = 1;
            for(int j = maxY-2;j>=0;j--){
                if(obstacleGrid[i][j] == 1) curr[j] = 0;
                else{
                    int right = curr[j + 1];
                    int down = dp[j];
                    if((long long)right + down <= INT_MAX) curr[j] = right + down;
                }
            }
            dp = curr;
        }
        return dp[0];
    }
};