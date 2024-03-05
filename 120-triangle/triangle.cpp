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

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int mxColSze = triangle[m-1].size();
        vector<vector<int>> dp(m,vector<int> (mxColSze, -1));
        int ans = solve(triangle, 0, 0, dp);
        return ans;
    }
};