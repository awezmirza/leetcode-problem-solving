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

    int solveSO(int m, int n) {
        vector<int> prev(n + 1, 1);
        for (int i = m - 1; i >= 1; i--) {
            vector<int> curr (n + 1, 0);
            curr[n] = 1;
            for (int j = n - 1; j >= 1; j--) {
                curr[j] = prev[j] + curr[j + 1];
            }
            prev = curr;
        }
        return prev[1];
    }

    int uniquePaths(int m, int n) {
        return solveSO(m, n);
    }
};