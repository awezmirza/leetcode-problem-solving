class Solution {
public:

    int solve(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& dp){
        if(row >= triangle.size()){
            return 0;
        }
        if(col >= triangle[row].size()){
            return 1000000;
        }
        if(dp[row][col] != -1) return dp[row][col];
        int left = triangle[row][col] + solve(triangle, row + 1, col, dp);
        int right = triangle[row][col] + solve(triangle, row + 1, col + 1, dp);
        return dp[row][col] = min(left, right);
    }

    int solveSO(vector<vector<int>>& triangle){
        int m = triangle.size();
        int mxColSze = triangle[m-1].size();
        vector<vector<int>> dp(m +1,vector<int> (m+1, 0));

        for(int row = m-1;row>=0;--row){
            for(int col = triangle[row].size()-1; col >=0;col-- ){
                int left = triangle[row][col] + dp[row + 1][col];
                int right = triangle[row][col] + dp[row + 1][col + 1];
                dp[row][col] = min(left, right);
            }
        }
        return dp[0][0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int ans = solveSO(triangle);
        return ans;
    }
};