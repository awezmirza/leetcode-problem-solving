class Solution {
public:

    int solve(int m, int n, int i, int j, vector<vector<int>>& dp) {
        if (i == m && j == n) {
            return 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = 0;
        if (j != n) {
            right = solve(m, n, i, j + 1, dp);
        } 
        int down = 0;
        if (i != m) {
            down = solve(m, n, i + 1, j, dp);
        }

        return dp[i][j] = right + down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        return solve(m, n, 1, 1, dp);
    }
};