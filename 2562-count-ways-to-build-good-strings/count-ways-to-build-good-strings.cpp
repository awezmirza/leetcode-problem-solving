class Solution {

    int MOD = 1000000007;

    int solve(int low, int high, int zero, int one, int curr, vector<int>& dp) {
        if (curr > high) {
            return 0;
        }

        if (dp[curr] != -1) {
            return dp[curr];
        }

        int ans = 0;
        if (curr >= low && curr <= high) {
            ans++;
        }

        // Appent 0
        ans += solve(low, high, zero, one, curr + zero, dp);

        // Append 1
        ans += solve(low, high, zero, one, curr + one, dp);

        return dp[curr] = (ans % MOD);
    }


public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        int ans = solve(low, high, zero, one, 0, dp);
        return ans;
    }
};