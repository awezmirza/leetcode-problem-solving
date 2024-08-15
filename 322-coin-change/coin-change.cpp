class Solution {
public:

    int solve(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) {
            return 0;
        }

        if (amount < 0) {
            return INT_MAX;
        }

        if (dp[amount] != -1) {
            return dp[amount];
        }
        int n = coins.size();
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            int returned = solve(coins, amount - coins[i], dp);
            if (returned != INT_MAX) {
                mini = min(mini, returned + 1);
            }
        }
        return dp[amount] = mini;
    }

    int solveSO(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0);
        int n = coins.size();
        for (int j = 1; j <= amount; j++) {
            int mini = INT_MAX;

            for (int i = n - 1; i >= 0; i--) {
                if (j - coins[i] < 0) {
                    continue;
                }
                int returned = dp[j - coins[i]];
                if (returned != INT_MAX) {
                    mini = min(mini, returned + 1);
                }
            }
            dp[j] = mini;
        }
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int ans = solveSO(coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};