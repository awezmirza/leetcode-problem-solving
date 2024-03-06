class Solution {
public:

    int solveHelper(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& dp){
        if(row >= matrix.size()) return 0;
        if(col<0 || col >= matrix[0].size()) return 1000000;
        if(dp[row][col] != -1000000){
            return dp[row][col];
        }

        int mini = INT_MAX;
        mini = min(mini, matrix[row][col] + solveHelper(matrix, row + 1, col, dp));
        mini = min(mini, matrix[row][col] + solveHelper(matrix, row + 1, col + 1, dp));
        mini = min(mini, matrix[row][col] + solveHelper(matrix, row + 1, col - 1, dp));
        return dp[row][col] = mini;
    }

    int solve(vector<vector<int>>& matrix){
        int rows = matrix.size();
        int cols = matrix[0].size();
        int mini = INT_MAX;
        vector<vector<int>> dp(rows, vector<int> (cols, -1000000));
        for(int i = 0;i<cols;i++){
            mini = min(mini, solveHelper(matrix, 0, i, dp));
        }
        return mini;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = solve(matrix);
        return ans;
    }
};