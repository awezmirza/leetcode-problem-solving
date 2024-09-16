class Solution {
public:

    int solve(string s, string t, int sPtr, int tPtr, vector<vector<int>>& dp) {
        int m = s.size();
        int n = t.size();
        if (tPtr >= n) {
            return 1;
        }
        if(sPtr >= m) {
            return 0;
        }
        if (dp[sPtr][tPtr] != -1) {
            return dp[sPtr][tPtr];
        }
        int take = 0;
        if (s[sPtr] == t[tPtr]) {
            take = solve(s, t, sPtr + 1, tPtr + 1, dp);
        }
        int leave = solve(s, t, sPtr + 1, tPtr, dp);
        return dp[sPtr][tPtr] = take + leave;
    }

    int solveSO(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));

        for (int j = m; j >= 0; j--) {
            dp[j][n] = 1;
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int take = 0;
                if (s[i] == t[j]) {
                    take = dp[i + 1][j + 1];
                }
                int leave = dp[i + 1][j];

                if ((double) take + leave <= INT_MAX) {
                    dp[i][j] = take + leave;
                }
            }
        }
        return dp[0][0];
    }

    int solveSO2(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;

        for (int i = m - 1; i >= 0; i--) {
            vector<int> curr(n + 1, 0);
            curr[n] = 1;
            for (int j = n - 1; j >= 0; j--) {
                int take = 0;
                if (s[i] == t[j]) {
                    take = dp[j + 1];
                }
                int leave = dp[j];

                if ((double) take + leave <= INT_MAX) {
                    curr[j] = take + leave;
                }
            }
            dp = curr;
        }
        return dp[0];
    }

    int numDistinct(string s, string t) {
        return solveSO2(s, t); 
    }
};