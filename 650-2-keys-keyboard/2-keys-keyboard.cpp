class Solution {
public:

    int solve(int n, int copied, int len, vector<vector<int>>& dp) {
        if (len == n) {
            return 0;
        }
        int ans = 100009;
        if (len > n) {
            return ans;
        }

        if (dp[copied][len] != -1) {
            return dp[copied][len];
        }

        if (copied != len) {
            ans = min(ans, 1 + solve(n, len, len, dp));
        }

        if (copied != 0) {
            ans = min(ans, 1 + solve(n, copied, len + copied, dp));
        }
        return dp[copied][len] = ans;
    }

    int minSteps(int n) {
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        int ans = solve(n, 0, 1, dp);

        return ans;
    }
};