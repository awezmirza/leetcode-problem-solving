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

    int helper(vector<vector<int>>& obstacleGrid){
        int maxX = obstacleGrid.size();
        int maxY = obstacleGrid[0].size();
        vector<vector<int>> dp(maxX, vector<int> (maxY, 0));
        for(int i = maxX-1;i>=0;i--){
            if(obstacleGrid[i][maxY-1] == 1) break;
            dp[i][maxY-1] = 1;
        }
        for(int i = maxY-1;i>=0;i--){
            if(obstacleGrid[maxX-1][i] == 1) break;
            dp[maxX-1][i] = 1;
        }
        for(int i = 0;i<maxX;i++){
            for(int j = 0;j<maxY;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"After"<<endl;

        for(int i = maxX-2;i>=0;i--){
            for(int j = maxY-2;j>=0;j--){
                if(i+1 > maxX || j+1 > maxY || obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else{
                    int down = dp[i][j + 1];
                    int left = dp[i + 1][j];
                    if((long long)left + down < INT_MAX)
                    dp[i][j] = left + down;
                }
            }
        }
        for(int i = 0;i<maxX;i++){
            for(int j = 0;j<maxY;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[0][0];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int ans = helper(obstacleGrid);
        return ans;
    }
};