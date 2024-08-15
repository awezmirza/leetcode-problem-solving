class Solution {
public:

    int solve(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) {
            return 0;
        }

        if (dp[amount] != -1) {
            return dp[amount];
        }
        int n = coins.size();
        int mini = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            if (amount - coins[i] < 0) {
                continue;
            }
            int returned = solve(coins, amount - coins[i], dp);
            if (returned != INT_MAX) {
                mini = min(mini, returned + 1);
            }
        }
        return dp[amount] = mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, -1);
        int ans = solve(coins, amount, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};